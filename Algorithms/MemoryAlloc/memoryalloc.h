#ifndef MEMORY_ALLOC_H
#define MEMORY_ALLOC_H

#include <iostream>
#include <utility>

namespace SO2{

#define MAX_MEM_SIZE 12

class memoryalloc{
public:
    struct aloc_report{
        bool is_allocated = false;
        bool is_perfect_fit = false;
    };
    memoryalloc();
    memoryalloc(const memoryalloc &other);
    virtual ~memoryalloc();
    aloc_report first_fit(int N);
    aloc_report best_fit(int N);
    aloc_report worst_fit(int N);
    aloc_report next_fit(int N);
    size_t memsize() const;
    void load_from_buffer();
    memoryalloc& operator=(const memoryalloc &rhs);
    friend std::ostream& operator<<(std::ostream &os, const memoryalloc &ma);

private:
    int MEM[MAX_MEM_SIZE];
    int BUFFER[MAX_MEM_SIZE];
    size_t NEXT_FIT_INDEX;
    size_t MUTABLE_SIZE = MAX_MEM_SIZE;
    std::pair<int, int> LAST_MODDED_VALUE;
    void init();
    void realocate(int index);
};

};

#endif