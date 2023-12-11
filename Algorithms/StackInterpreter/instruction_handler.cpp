/**
 * @file instruction_handler.cpp
 * @author Guilherme Martinelli Taglietti
*/

#include "instruction_handler.h"
#include <QMessageBox>

stackinterpreter::instruction_tuple stackinterpreter::InstructionHandler::handle_instruction(int enumtype, const QString &val) noexcept{
    switch(enumtype){
        case stackinterpreter::Instructions::PUSHI:
            if(!is_valid_number(val)){
                QMessageBox::critical(nullptr, "Error!", "Type a valid number!");
                return stackinterpreter::instruction_tuple(stackinterpreter::Instructions::ERROR, -1);
            }
            return stackinterpreter::instruction_tuple(stackinterpreter::Instructions::PUSHI, val.toInt());
            break;

        case stackinterpreter::Instructions::PUSH:
            return stackinterpreter::instruction_tuple(stackinterpreter::Instructions::PUSH, hex_to_int(val));
            break;

        case stackinterpreter::Instructions::POP:
            return stackinterpreter::instruction_tuple(stackinterpreter::Instructions::POP, hex_to_int(val));
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

void stackinterpreter::InstructionHandler::execute(QWidget* parent, stackinterpreter::Stack &stack, int enumtype, int value, InstructionHandler &handler, const QString &description) noexcept{
    switch(enumtype){
        case stackinterpreter::Instructions::PUSHI:
            stack.PUSHI(value, description, handler.get_log());
            break;

        case stackinterpreter::Instructions::PUSH:
            stack.PUSH(value, description, handler.get_log());
            break;

        case stackinterpreter::Instructions::POP:
            stack.POP(value, description, handler.get_log());
            break;

        case stackinterpreter::Instructions::ADD:
            stack.ADD(description, handler.get_log());
            break;

        case stackinterpreter::Instructions::SUB:
            stack.SUB(description, handler.get_log());
            break;

        case stackinterpreter::Instructions::MUL:
            stack.MUL(description, handler.get_log());
            break;

        case stackinterpreter::Instructions::DIV:
            stack.DIV(description, handler.get_log());
            break;

        case stackinterpreter::Instructions::PRINT:
            stack.PRINT(parent, description, handler.get_log());
            break;

        case stackinterpreter::Instructions::DUP:
            stack.DUP(description, handler.get_log());
            break;

        case stackinterpreter::Instructions::SWAP:
            stack.SWAP(description, handler.get_log());
            break;

        case stackinterpreter::Instructions::INPUT:
            stack.INPUT(parent, description, handler.get_log());
            break;

        case stackinterpreter::Instructions::DROP:
            stack.DROP(description, handler.get_log());
            break;

        case stackinterpreter::Instructions::HLT:
            stack.HLT(description, handler.get_log());
            break;

        default:
            break;
    }
}

int stackinterpreter::InstructionHandler::hex_to_int(const QString &hex) const noexcept{
    bool ok;
    int hex_integer = hex.toInt(&ok, 16);
    if(!ok){
        QMessageBox::critical(nullptr, "Error!", "Mismatch converting hexadecimal to a number!");
        return -1;
    }
    return hex_integer;
}

bool stackinterpreter::InstructionHandler::is_valid_number(const QString &numstr) const noexcept{
    bool ok;
    numstr.toInt(&ok);
    return ok;
}

QTextEdit& stackinterpreter::operator<<(QTextEdit &os, stackinterpreter::InstructionHandler &handler){
    QVector<QString>& log = handler.get_log();
    for(const QString &entry : log)
        os.append(entry);
    return os;
}
