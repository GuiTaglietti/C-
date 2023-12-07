/**
 * @file instruction_handler.cpp
 * @author Guilherme Martinelli Taglietti
*/

#include "instruction_handler.h"

stackinterpreter::instruction_tuple stackinterpreter::InstructionHandler::handle_instruction(int enumtype, const QString &val) noexcept{
    switch(enumtype){
        case stackinterpreter::Instructions::PUSHI:
            return stackinterpreter::instruction_tuple(stackinterpreter::Instructions::PUSHI, val.toInt());
            break;

        case stackinterpreter::Instructions::PUSH:
            return stackinterpreter::instruction_tuple(stackinterpreter::Instructions::PUSH, val.toInt());
            break;

        case stackinterpreter::Instructions::POP:
            return stackinterpreter::instruction_tuple(stackinterpreter::Instructions::POP, val.toInt());
            break;

        case stackinterpreter::Instructions::ADD:
            return stackinterpreter::instruction_tuple(stackinterpreter::Instructions::ADD, -1);
            break;

        case stackinterpreter::Instructions::SUB:
            return stackinterpreter::instruction_tuple(stackinterpreter::Instructions::SUB, -1);
            break;

        case stackinterpreter::Instructions::DIV:
            return stackinterpreter::instruction_tuple(stackinterpreter::Instructions::DIV, -1);
            break;

        case stackinterpreter::Instructions::MUL:
            return stackinterpreter::instruction_tuple(stackinterpreter::Instructions::MUL, -1);
            break;

        case stackinterpreter::Instructions::INPUT:
            return stackinterpreter::instruction_tuple(stackinterpreter::Instructions::INPUT, -1);
            break;

        case stackinterpreter::Instructions::DROP:
            return stackinterpreter::instruction_tuple(stackinterpreter::Instructions::DROP, -1);
            break;

        case stackinterpreter::Instructions::DUP:
            return stackinterpreter::instruction_tuple(stackinterpreter::Instructions::DUP, -1);
            break;

        case stackinterpreter::Instructions::PRINT:
            return stackinterpreter::instruction_tuple(stackinterpreter::Instructions::PRINT, -1);
            break;

        case stackinterpreter::Instructions::SWAP:
            return stackinterpreter::instruction_tuple(stackinterpreter::Instructions::SWAP, -1);
            break;

        case stackinterpreter::Instructions::HLT:
            return stackinterpreter::instruction_tuple(stackinterpreter::Instructions::HLT, -1);
            break;

        default:
            return stackinterpreter::instruction_tuple(stackinterpreter::Instructions::ERROR, -1);
            break;
    }
}

void stackinterpreter::InstructionHandler::execute(QWidget* parent, stackinterpreter::Stack &stack, int enumtype, int value) noexcept{
    switch(enumtype){
        case stackinterpreter::Instructions::PUSHI:
            stack.PUSHI(value);
            break;

        case stackinterpreter::Instructions::PUSH:
            stack.PUSHI(value);
            break;

        case stackinterpreter::Instructions::POP:
            stack.PUSHI(value);
            break;

        case stackinterpreter::Instructions::ADD:
            stack.ADD();
            break;

        case stackinterpreter::Instructions::SUB:
            stack.SUB();
            break;

        case stackinterpreter::Instructions::MUL:
            stack.MUL();
            break;

        case stackinterpreter::Instructions::DIV:
            stack.DIV();
            break;

        case stackinterpreter::Instructions::PRINT:
            stack.PRINT(parent);
            break;

        case stackinterpreter::Instructions::DUP:
            stack.DUP();
            break;

        case stackinterpreter::Instructions::SWAP:
            stack.SWAP();
            break;

        case stackinterpreter::Instructions::INPUT:
            stack.INPUT(parent);
            break;

        case stackinterpreter::Instructions::DROP:
            stack.DROP();
            break;

        case stackinterpreter::Instructions::HLT:
            stack.HLT();
            break;

        default:
            break;
    }
}
