/**
 * @file
 * @author Guilherme Martinelli Taglietti
*/

#include "instruction_handler.h"

stackinterpreter::instruction_tuple stackinterpreter::InstructionHandler::handle_instruction(int enumtype, const QString &val) noexcept{
    switch(enumtype){
        case stackinterpreter::Instructions::PUSHI:
            return stackinterpreter::instruction_tuple(stackinterpreter::Instructions::PUSHI, val.toInt());
            break;

        case stackinterpreter::Instructions::PUSH:
            return stackinterpreter::instruction_tuple(stackinterpreter::Instructions::PUSHI, val.toInt());
            break;

        case stackinterpreter::Instructions::POP:
            return stackinterpreter::instruction_tuple(stackinterpreter::Instructions::PUSHI, val.toInt());
            break;

        default:
            return stackinterpreter::instruction_tuple(stackinterpreter::Instructions::ERROR, -1);
            break;
    }
}
