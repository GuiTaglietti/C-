#include "memory.h"
#include "stack.h"
#include <QMessageBox>

stackinterpreter::Memory::Memory(qsizetype _max_mem_size) : max_mem_size(_max_mem_size){
    mem.resize(max_mem_size);
    mem.assign(max_mem_size, stackinterpreter::mem_slot());
}

stackinterpreter::Memory::Memory(const Memory &cpy) : mem(cpy.mem), max_mem_size(cpy.max_mem_size){}

stackinterpreter::Memory& stackinterpreter::Memory::operator=(const Memory &rhs){
    if(this != &rhs){
        mem = rhs.mem;
        max_mem_size = rhs.max_mem_size;
    }
    return *this;
}

bool stackinterpreter::Memory::push_in(const mem_slot &slot, stackinterpreter::Stack &stack) noexcept{
    if(slot.address == -1 || slot.address >= max_mem_size){
        QMessageBox::critical(nullptr, "Error!", "Error inserting the value in memory, check hexadecimal address!");
        return false;
    }
    int value = stack.DROP();
    mem[slot.address] = stackinterpreter::mem_slot(slot.address, value, true);
    return true;
}

bool stackinterpreter::Memory::pop_out(const mem_slot &slot, stackinterpreter::Stack &stack) noexcept{
    if(slot.address == -1 || slot.address >= max_mem_size){
        QMessageBox::critical(nullptr, "Error!", "Error removing the value in memory, check hexadecimal address!");
        return false;
    }
    else if(!is_occupied(slot.address)){
        QMessageBox::critical(nullptr, "Error!", "Error removing empty memory slot!");
        return false;
    }
    int value = slot.value;
    mem[slot.address] = stackinterpreter::mem_slot();
    stack.PUSHI(value);
    return true;
}
