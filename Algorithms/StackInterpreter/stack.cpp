/**
 * @file stack.cpp
 * @author Guilherme Martinelli Taglietti
*/
#include "stack.h"
#include <QMessageBox>
#include <QInputDialog>

/**
 * @namespace stackinterpreter
 * @class Stack
 * @brief Overloaded constructor used to start the stack depending on wich max size the user chooses
*/
stackinterpreter::Stack::Stack(const Stack &cpy){
    // Soon...
}

stackinterpreter::Stack::~Stack(){
    // Soon...
}

void stackinterpreter::Stack::PUSHI(int /*T*/ value) noexcept{
    if(stack.size() == max_size){
        QMessageBox::critical(nullptr, "Error!", "Stack overflow! Please clear or resize the stack to continue...");
        return;
    }
    stack.push(value);
}

void stackinterpreter::Stack::PUSH(const QString &hex) noexcept{
    QMessageBox::critical(nullptr, "Error!", "Missing memory...");
    return;
}

void stackinterpreter::Stack::POP(const QString &hex) noexcept{
    QMessageBox::critical(nullptr, "Error!", "Missing memory...");
    return;
}

void stackinterpreter::Stack::INPUT(QWidget *parent) noexcept{
    if(stack.size() == max_size){
        QMessageBox::critical(nullptr, "Error!", "Stack overflow! Please clear or resize the stack to continue...");
        return;
    }
    bool ok;
    int value = QInputDialog::getInt(parent, "Type a number", "Number:", 0, -2147483647, 2147483647, 1, &ok);
    if(ok)
        stack.push(value);
    else
        QMessageBox::information(parent, "Warning", "Instruction canceled!");
}

void stackinterpreter::Stack::PRINT(QWidget *parent) noexcept{
    if(stack.empty()){
        QMessageBox::critical(nullptr, "Error!", "Stack underflow! Not enough values to execute the instruction...");
        return;
    }
    int value = stack.top();
    stack.pop();
    QMessageBox::information(parent, "PRINT Instruction", "Value discarded and printed: " + QString::fromStdString(std::to_string(value)));
}

void stackinterpreter::Stack::ADD() noexcept{
    if(stack.empty() || stack.size() == 1){
        QMessageBox::critical(nullptr, "Error!", "Stack underflow! Not enough values to execute the instruction...");
        return;
    }
    int value1, value2;
    value1 = stack.top(); stack.pop();
    value2 = stack.top(); stack.pop();
    stack.push(value2 + value1);
}

void stackinterpreter::Stack::SUB() noexcept{
    if(stack.empty() || stack.size() == 1){
        QMessageBox::critical(nullptr, "Error!", "Stack underflow! Not enough values to execute the instruction...");
        return;
    }
    int value1, value2;
    value1 = stack.top(); stack.pop();
    value2 = stack.top(); stack.pop();
    stack.push(value2 - value1);
}

void stackinterpreter::Stack::MUL() noexcept{
    if(stack.empty() || stack.size() == 1){
        QMessageBox::critical(nullptr, "Error!", "Stack underflow! Not enough values to execute the instruction...");
        return;
    }
    int value1, value2;
    value1 = stack.top(); stack.pop();
    value2 = stack.top(); stack.pop();
    stack.push(value2 * value1);
}

void stackinterpreter::Stack::DIV() noexcept{
    if(stack.empty() || stack.size() == 1){
        QMessageBox::critical(nullptr, "Error!", "Stack underflow! Not enough values to execute the instruction...");
        return;
    }
    int value1, value2;
    value1 = stack.top(); stack.pop();
    value2 = stack.top(); stack.pop();
    stack.push(value2 / value1);
}

void stackinterpreter::Stack::SWAP() noexcept{
    if(stack.empty() || stack.size() == 1){
        QMessageBox::critical(nullptr, "Error!", "Stack underflow! Not enough values to execute the instruction...");
        return;
    }
    int value1, value2;
    value1 = stack.top(); stack.pop();
    value2 = stack.top(); stack.top();
    stack.push(value1);
    stack.push(value2);
}

void stackinterpreter::Stack::DROP() noexcept{
    if(stack.empty()){
        QMessageBox::critical(nullptr, "Error!", "Stack underflow! Not enough values to execute the instruction...");
        return;
    }
    stack.pop();
}

void stackinterpreter::Stack::DUP() noexcept{
    if(stack.size() == max_size){
        QMessageBox::critical(nullptr, "Error!", "Stack overflow! Please clear or resize the stack to continue...");
        return;
    }
    stack.push(stack.top());
}

void stackinterpreter::Stack::HLT() noexcept{
    while(!stack.empty())
        stack.pop();
    // CLEAR MEMORY
    // ASK FOR .CPP .ASM .FORTH EXPORTS
}

void stackinterpreter::operator<<(QLineEdit &os, const stackinterpreter::Stack &stack){
    std::stack<int> /* T template type soon */ stack_buffer = stack.getStack();
    stack_buffer = stackinterpreter::stackutil::prepare(stack_buffer);
    QString text;
    while(!stack_buffer.empty()){
        text += QString::number(stack_buffer.top());
        stack_buffer.pop();
        if(!stack_buffer.empty())
            text += " - ";
    }
    os.setText(text);
}

std::stack<int> stackinterpreter::stackutil::prepare(std::stack<int> &orig) noexcept{
    if(orig.empty() || orig.size() == 1)
        return orig;
    std::stack<int> cpy;
    while(!orig.empty()){
        cpy.push(orig.top());
        orig.pop();
    }
    return cpy;
}
