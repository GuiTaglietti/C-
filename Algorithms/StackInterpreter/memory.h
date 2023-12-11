#ifndef MEMORY_H
#define MEMORY_H

#pragma once

#include "qcontainerfwd.h"
#include "QVector"

namespace stackinterpreter{

class Stack;

typedef struct mem_slot{
    qsizetype  address;
    int        value;
    bool       occupied;
    mem_slot() : occupied(false){}
    mem_slot(qsizetype _address, int _value, bool _occupied) : address(_address), value(_value), occupied(_occupied){}
} mem_slot;

class Memory{
public:
    Memory() : Memory(256){} // Default size
    Memory(qsizetype _max_mem_size);
    Memory(const Memory &cpy);
    Memory& operator=(const Memory &rhs);

    bool push_in(const mem_slot &slot, stackinterpreter::Stack &stack) noexcept;
    bool pop_out(const mem_slot &slot, stackinterpreter::Stack &stack) noexcept;
    [[nodiscard]] qsizetype get_max_mem_size() const noexcept { return max_mem_size; } /// Inline function
    [[nodiscard]] const QVector<QString>& get_mem_log() const noexcept{ return mem_log; } /// Inline function
    void clear_log() noexcept { mem_log.clear(); }

protected:
    QVector<mem_slot> mem;
    QVector<QString> mem_log;
    qsizetype max_mem_size;
    [[nodiscard]] bool is_occupied(int address) const noexcept { return mem[address].occupied; } /// Inline function
};

} // namespace stackinterpreter

#endif // MEMORY_H
