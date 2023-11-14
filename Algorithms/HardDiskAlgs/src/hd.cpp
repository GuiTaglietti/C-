#include "../include/hd.h"
#include <random>
#include <algorithm>

namespace SO2{

SO2::HardDisk::HardDisk(){
    using SO2::HardDisk;
    int l = 1, u = 100;
    std::random_device rd;
    std::mt19937 mt(rd());
    std::uniform_int_distribution<int> dist(1, 99);
    std::vector<int> init(u - l + 1);
    std::iota(init.begin(), init.end(), l);
    std::shuffle(init.begin(), init.end(), mt);
    for(std::size_t i = 0; i < (std::size_t)MAX_REQUISITONS; i++)
        req_buffer.push_back(init[i]);
    head_ptr = DEFAULT_HEAD_PTR_VALUE = dist(mt);
    head_ptr_displacement = 0;
    print_buffer = "";
}

SO2::HardDisk::~HardDisk(){}

inline constexpr SO2::HardDisk::hd_head_t SO2::HardDisk::get_head_ptr() const noexcept{
    return head_ptr;
}

inline std::vector<int> SO2::HardDisk::get_req_buffer() const noexcept{
    return req_buffer;
}

inline constexpr void SO2::HardDisk::set_default_head_ptr() noexcept{
    head_ptr = DEFAULT_HEAD_PTR_VALUE;
}

inline constexpr void SO2::HardDisk::set_default_head_ptr_displacement() noexcept{
    head_ptr_displacement = 0;
}

inline void SO2::HardDisk::set_default_print_buffer() noexcept{
    print_buffer = "";
}

void SO2::HardDisk::set_all_default() noexcept{
    set_default_head_ptr();
    set_default_head_ptr_displacement();
    set_default_print_buffer();
    PRINT_BUFFER_COUNT = false;
}

void SO2::HardDisk::load_to_print_buffer(const std::vector<int> &reqs, const SO2::HardDisk::hd_head_t displacement, 
                                         const unsigned int access, const std::string &alg_name, bool f = false)
{
    using SO2::HardDisk;
    print_buffer += "Acessou " + std::to_string(access) + " [";
    if(!f){
        if(!reqs.empty()){
            for(std::size_t i = 0; i < reqs.size(); i++){
                print_buffer += std::to_string(reqs[i]);
                if(i < reqs.size() - 1) print_buffer += " - ";
                else print_buffer += "] Já deslocou " + std::to_string(displacement) + "\n";
            }
        } 
        else{
            print_buffer += "] Já deslocou " + std::to_string(displacement) + "\n";
            print_buffer += alg_name + " - Quantidade total de deslocamentos: " + std::to_string(displacement) + "\n";
        }
    }
    else{
        if(!reqs.empty()){
            for(std::size_t i = 0; i < reqs.size(); i++){
                print_buffer += std::to_string(reqs[i]);
                if(i < reqs.size() - 1) print_buffer += " - ";
                else print_buffer += "] Já deslocou " + std::to_string(displacement) + "\n";
            }
        } 
        if(reqs.size() == 1) print_buffer += alg_name + " - Quantidade total de deslocamentos: " + std::to_string(displacement) + "\n";
    }
}

void SO2::HardDisk::FCFS(){
    using SO2::HardDisk;
    std::vector<int> cpy(req_buffer.begin(), req_buffer.end());
    std::reverse(cpy.begin(), cpy.end());
    set_default_print_buffer();
    while(!cpy.empty()){
        int req = cpy.back();
        head_ptr_displacement += abs(head_ptr - req);
        head_ptr = req;
        load_to_print_buffer(cpy, head_ptr_displacement, req, "FCFS");
        cpy.pop_back();
    }
    yield_print_buffer("FCFS");
    set_all_default();
}

void SO2::HardDisk::SSTF(){
    using SO2::HardDisk;
    set_default_print_buffer();
    std::vector<int> cpy(req_buffer.begin(), req_buffer.end());
    while(!cpy.empty()){
        auto closest = std::min_element(cpy.begin(), cpy.end(), [this](int a, int b){
            return std::abs(static_cast<int>(head_ptr) - a) < std::abs(static_cast<int>(head_ptr) - b);
        });
        head_ptr_displacement += std::abs(static_cast<int>(head_ptr) - *closest);
        head_ptr = static_cast<hd_head_t>(*closest);
        load_to_print_buffer(cpy, head_ptr_displacement, *closest, "SSTF");
        cpy.erase(closest);
    }
    yield_print_buffer("SSTF");
    set_all_default();
}

void SO2::HardDisk::SCAN(){
    std::vector<int> cpy_print(req_buffer.begin(), req_buffer.end());
    std::vector<int> cpy(req_buffer.begin(), req_buffer.end());
    std::sort(cpy.begin(), cpy.end());
    auto it = std::lower_bound(cpy.begin(), cpy.end(), head_ptr);
    while(it != cpy.end()){
        head_ptr_displacement += abs(head_ptr - *it);
        head_ptr = *it;
        load_to_print_buffer(cpy_print, head_ptr_displacement, *it, "SCAN", true);
        cpy_print.erase(std::find(cpy_print.begin(), cpy_print.end(), head_ptr)); 
        cpy.erase(it);
        it = std::lower_bound(cpy.begin(), cpy.end(), head_ptr);
    }
    it = std::lower_bound(cpy.begin(), cpy.end(), head_ptr);
    while(it != cpy.begin()){
        it--;
        head_ptr_displacement += abs(head_ptr - *it);
        head_ptr = *it;
        load_to_print_buffer(cpy_print, head_ptr_displacement, *it, "SCAN", true);
        cpy_print.erase(std::find(cpy_print.begin(), cpy_print.end(), head_ptr)); 
        cpy.erase(it);
        it = std::lower_bound(cpy.begin(), cpy.end(), head_ptr);
    }
    yield_print_buffer("SCAN (elevador)");
    set_all_default();
}

void SO2::HardDisk::CSCAN(){
    bool reversed = false;
    std::vector<int> cpy_print(req_buffer.begin(), req_buffer.end());
    std::vector<int> cpy(req_buffer.begin(), req_buffer.end());
    std::sort(cpy.begin(), cpy.end());
    auto it = std::find(cpy.begin(), cpy.end(), head_ptr);
    it = std::lower_bound(it, cpy.end(), head_ptr);
    if(it == cpy.end() && !reversed){
        head_ptr_displacement += abs(head_ptr - 99);
        head_ptr = 99;
        load_to_print_buffer(cpy_print, head_ptr_displacement, head_ptr, "Circular Scan", true);
        head_ptr_displacement += 99;
        it = cpy.begin();
        head_ptr = 0;
        load_to_print_buffer(cpy_print, head_ptr_displacement, it - cpy.begin(), "Circular Scan", true);
        reversed = true;
    }
    while(it != cpy.end()){
        head_ptr_displacement += abs(head_ptr - *it);
        head_ptr = *it;
        load_to_print_buffer(cpy_print, head_ptr_displacement, *it, "Circular Scan", true);
        cpy_print.erase(std::find(cpy_print.begin(), cpy_print.end(), head_ptr)); 
        it = cpy.erase(it);
    }
    if(!reversed){
        it = cpy.begin();
        while(it != cpy.end()){
            head_ptr_displacement += abs(head_ptr - *it);
            head_ptr = *it;
            load_to_print_buffer(cpy_print, head_ptr_displacement, *it, "Circular Scan", true);
            cpy_print.erase(std::find(cpy_print.begin(), cpy_print.end(), head_ptr)); 
            it = cpy.erase(it);
        }
    }
    yield_print_buffer("Circular SCAN");
    set_all_default();
}

void SO2::HardDisk::CLOOK(){
    using SO2::HardDisk;
    set_default_print_buffer();
    std::vector<int> cpy_print(req_buffer.begin(), req_buffer.end());
    std::vector<int> cpy(req_buffer.begin(), req_buffer.end());
    std::sort(cpy.begin(), cpy.end());
    auto it = std::lower_bound(cpy.begin(), cpy.end(), head_ptr);
    while(it != cpy.end()){
        head_ptr_displacement += abs(head_ptr - *it);
        head_ptr = *it;
        load_to_print_buffer(cpy_print, head_ptr_displacement, *it, "C-look", true);
        cpy_print.erase(std::find(cpy_print.begin(), cpy_print.end(), head_ptr)); 
        it = cpy.erase(it);
    }
    if(!cpy.empty()){
        head_ptr_displacement += abs(head_ptr - cpy.front());
        head_ptr = cpy.front();
        load_to_print_buffer(cpy_print, head_ptr_displacement, cpy.front(), "C-look", true);
        cpy_print.erase(std::find(cpy_print.begin(), cpy_print.end(), head_ptr)); 
        cpy.erase(cpy.begin());
    }
    while(!cpy.empty()){
        head_ptr_displacement += abs(head_ptr - cpy.front());
        head_ptr = cpy.front();
        load_to_print_buffer(cpy_print, head_ptr_displacement, cpy.front(), "C-look", true);
        cpy_print.erase(std::find(cpy_print.begin(), cpy_print.end(), head_ptr)); 
        cpy.erase(cpy.begin());
    }
    yield_print_buffer("C-look");
    set_all_default();
}

void SO2::HardDisk::set_rebonatto_values(){
    req_buffer.clear();
    std::vector<int> vi(MAX_REQUISITONS);
    int rbvalues[MAX_REQUISITONS] = {30, 70, 54, 59, 29, 64, 87, 38, 05, 40};
    for(std::size_t i = 0; i < (std::size_t)MAX_REQUISITONS; i++)
        vi[i] = rbvalues[i];
    req_buffer = vi;
    DEFAULT_HEAD_PTR_VALUE = head_ptr = 88;
    head_ptr_displacement = 0;
    PRINT_BUFFER_COUNT = false;
}

inline void SO2::HardDisk::debug(){
    set_rebonatto_values();
}

void SO2::HardDisk::yield_print_buffer(const std::string &alg_name) noexcept{
    if(!PRINT_BUFFER_COUNT){
        std::cout << "========== Algoritmo " + alg_name + " ==========" << std::endl;
        PRINT_BUFFER_COUNT = true;
    }
    std::cout << print_buffer << std::endl;
}


std::ostream &operator<<(std::ostream &os, const HardDisk &hd){
    os << hd.print_buffer;
    return os; 
}

};