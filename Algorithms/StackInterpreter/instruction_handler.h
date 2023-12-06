/**
 * @headerfile instruction_handler.h
 * @author Guilherme Martinelli Taglietti
*/
#ifndef INSTRUCTION_HANDLER_H
#define INSTRUCTION_HANDLER_H

#include <QString>
#include "instructions.h" // Enum
#include "mainwindow.h"

namespace stackinterpreter{

typedef struct instruction_tuple{
    stackinterpreter::Instructions instruction; // Enum type
    int                            value;       // Can be null in case where the instruction is not PUSHI, PUSH or POP

    /// Constructors
    instruction_tuple(){}
    instruction_tuple(stackinterpreter::Instructions _instruction, int _value): instruction(_instruction), value(_value){}
} instruction_tuple;

class InstructionHandler : public MainWindow{
public:
    explicit InstructionHandler(){}
    virtual ~InstructionHandler(){}

    /// Deleting copy constructor && assignment operator
    InstructionHandler(const InstructionHandler &cpy) = delete;
    InstructionHandler& operator=(const InstructionHandler &rhs) = delete;

    [[nodiscard]] static stackinterpreter::instruction_tuple handle_instruction(int enumtype, const QString &val = "null") noexcept;
                        /*       STRUCT TYPE RETURN       */
};

} // namespsace stackinterpreter

#endif // INSTRUCTION_HANDLER_H
