#ifndef HD_H
#define HD_H

#include <iostream>
#include <vector>
#include <queue>

namespace SO2{

class HardDisk{

#define MAX_REQUISITONS 10

public:
    typedef unsigned int hd_head_t;
    HardDisk();
    HardDisk(const HardDisk &other) = delete;
    virtual ~HardDisk();
    void FCFS();
    void SSTF();
    void SCAN();
    void CSCAN();
    void CLOOK();
    void debug();
    constexpr hd_head_t get_head_ptr() const noexcept;
    std::vector<int> get_req_buffer() const noexcept;
    HardDisk &operator=(const HardDisk &rhs) = delete;
    friend std::ostream &operator<<(std::ostream &os, const HardDisk &hd);

private:
    std::vector<int> req_buffer;
    hd_head_t DEFAULT_HEAD_PTR_VALUE;
    bool PRINT_BUFFER_COUNT = false;
    hd_head_t head_ptr;
    hd_head_t head_ptr_displacement;
    std::string print_buffer;
    constexpr void set_default_head_ptr() noexcept;
    constexpr void set_default_head_ptr_displacement() noexcept;
    void set_default_print_buffer() noexcept;
    void set_all_default() noexcept;
    void load_to_print_buffer(const std::vector<int> &reqs, const hd_head_t ptr, const unsigned int access, const std::string &alg_name, bool f);
    void yield_print_buffer(const std::string &alg_name) noexcept;
    void set_rebonatto_values();
};

};

#endif 