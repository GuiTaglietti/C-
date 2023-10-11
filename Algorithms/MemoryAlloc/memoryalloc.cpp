#include "memoryalloc.h"
#include <random>
#include <utility>
#include <algorithm>

namespace SO2{

// Função do namespace

void charge_random_values(int arr[], size_t max_size){
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_int_distribution<int> dist(1, 100);
    for(size_t i = 0; i < max_size; i++)
        arr[i] = dist(gen);
}

// Implementação da classe 

SO2::memoryalloc::memoryalloc(){
    NEXT_FIT_INDEX = 0;
    init();
}

SO2::memoryalloc::memoryalloc(const memoryalloc &other){
    NEXT_FIT_INDEX = other.NEXT_FIT_INDEX;
    LAST_MODDED_VALUE = other.LAST_MODDED_VALUE;
    MUTABLE_SIZE = other.MUTABLE_SIZE;
    std::copy(other.MEM, other.MEM + MUTABLE_SIZE, MEM);
    std::copy(other.BUFFER, other.BUFFER + MUTABLE_SIZE, BUFFER);
}

SO2::memoryalloc::~memoryalloc(){}

inline size_t SO2::memoryalloc::memsize() const{
    return MUTABLE_SIZE;
}

void SO2::memoryalloc::init(){
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_int_distribution<int> dist(1, 100);
    LAST_MODDED_VALUE = {-1, -1};
    for(size_t i = 0; i < MUTABLE_SIZE; i++) MEM[i] = BUFFER[i] = dist(gen);
}

void SO2::memoryalloc::realocate(int index){
    size_t shift = index;
    while(shift < MUTABLE_SIZE - 1){
        MEM[shift] = MEM[shift + 1];
        shift++;
    }
    MUTABLE_SIZE--;
}

SO2::memoryalloc::aloc_report SO2::memoryalloc::first_fit(int N){
    SO2::memoryalloc::aloc_report aloc;
    for(size_t i = 0; i < memsize(); i++){
        if(MEM[i] == N){
            MEM[i] -= N;
            LAST_MODDED_VALUE.first = MEM[i]; 
            LAST_MODDED_VALUE.second = i;
            aloc.is_perfect_fit = true; aloc.is_allocated = true;
            realocate(i);
            return aloc;
        }
        if(MEM[i] > N){
            MEM[i] -= N;
            LAST_MODDED_VALUE.first = MEM[i]; 
            LAST_MODDED_VALUE.second = i;
            aloc.is_allocated = true;
            return aloc;
        }
    }
    return aloc;
}

SO2::memoryalloc::aloc_report SO2::memoryalloc::best_fit(int N){
    SO2::memoryalloc::aloc_report aloc;
    std::pair<int, int> ii(1e9, -1);
    for(size_t i = 0; i < memsize(); i++)
        if(MEM[i] >= N && MEM[i] < ii.first){ 
            ii.first = MEM[i]; ii.second = i;
        }
    if(ii.first == 1e9) return aloc;
    int temp = MEM[ii.second];
    MEM[ii.second] -= N;
    LAST_MODDED_VALUE.first = MEM[ii.second];
    LAST_MODDED_VALUE.second = ii.second;
    if(N == temp){ 
        aloc.is_perfect_fit = true;
        realocate(ii.second);
    }
    aloc.is_allocated = true;
    return aloc;
}

SO2::memoryalloc::aloc_report SO2::memoryalloc::worst_fit(int N){
    SO2::memoryalloc::aloc_report aloc;
    int temp = -1;
    int idx = -1;
    for(size_t i = 0; i < memsize(); i++)
        if(MEM[i] >= N && MEM[i] > temp){
            temp = MEM[i]; idx = i;
        }
    if(idx == -1) return aloc;
    if(N == temp){
        MEM[idx] -= N;
        LAST_MODDED_VALUE.first = MEM[idx];
        LAST_MODDED_VALUE.second = idx;
        aloc.is_perfect_fit = true;
        aloc.is_allocated = true;
        realocate(idx);
    } 
    else{
        aloc.is_allocated = true;
        MEM[idx] -= N;
        LAST_MODDED_VALUE.first = MEM[idx];
        LAST_MODDED_VALUE.second = idx;
    }
    return aloc;
}

SO2::memoryalloc::aloc_report SO2::memoryalloc::next_fit(int N){
    SO2::memoryalloc::aloc_report aloc;
    for(size_t i = NEXT_FIT_INDEX; i < memsize(); i++){
        if(MEM[i] == N){
            MEM[i] -= N;
            LAST_MODDED_VALUE.first = MEM[i];
            LAST_MODDED_VALUE.second = i;
            aloc.is_perfect_fit = true; aloc.is_allocated = true;
            NEXT_FIT_INDEX = i;
            realocate(i);
            return aloc;
        }
        if(MEM[i] > N){
            MEM[i] -= N;
            LAST_MODDED_VALUE.first = MEM[i];
            LAST_MODDED_VALUE.second = i;
            aloc.is_allocated = true;
            NEXT_FIT_INDEX = i;
            return aloc;
        }
    }
    NEXT_FIT_INDEX = 0;
    return aloc;
}

void SO2::memoryalloc::load_from_buffer(){
    std::copy(std::begin(BUFFER), std::end(BUFFER), std::begin(MEM));
    MUTABLE_SIZE = 12;
}

memoryalloc& memoryalloc::operator=(const memoryalloc &rhs){
    if(this != &rhs){
        NEXT_FIT_INDEX = rhs.NEXT_FIT_INDEX;
        LAST_MODDED_VALUE = rhs.LAST_MODDED_VALUE;
        MUTABLE_SIZE = rhs.MUTABLE_SIZE;
        std::copy(rhs.MEM, rhs.MEM + MUTABLE_SIZE, MEM);
        std::copy(rhs.BUFFER, rhs.BUFFER + MUTABLE_SIZE, BUFFER);
    }
    return *this;
}

std::ostream& operator<<(std::ostream &os, const memoryalloc &ma){
    os << "[ ";
    for(size_t i = 0; i < ma.memsize(); i++){
        if(ma.MEM[i] == ma.LAST_MODDED_VALUE.first && (int)i == ma.LAST_MODDED_VALUE.second) os << "\33[31m";
        os << ma.MEM[i];
        if(ma.MEM[i] == ma.LAST_MODDED_VALUE.first && (int)i == ma.LAST_MODDED_VALUE.second) os << "\33[0m";
        if(i < ma.memsize() - 1) os << " - ";
    }
    os << " ]";
    return os;
}

}