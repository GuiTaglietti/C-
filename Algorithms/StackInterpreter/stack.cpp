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
 * @brief Overloaded operator used to attribute the stack to another stack
*/
stackinterpreter::Stack& stackinterpreter::Stack::operator=(const Stack &rhs){
    if(this != &rhs){
        max_size = rhs.max_size;
        stack = rhs.stack;
    }
    return *this;
}

void stackinterpreter::Stack::PUSHI(int /*T*/ value, const QString &description, QVector<QString> &log) noexcept{
    if(stack.size() == max_size){
        QMessageBox::critical(nullptr, "Error!", "Stack overflow! Please clear or resize the stack to continue...");
        return;
    }
    stackutil::log_write(description, log, QString::number(value));
    stack.push(value);
}

void stackinterpreter::Stack::PUSH(const QString &hex, const QString &description, QVector<QString> &log) noexcept{
    QMessageBox::critical(nullptr, "Error!", "Missing memory...");
    return;
}

void stackinterpreter::Stack::POP(const QString &hex, const QString &description, QVector<QString> &log) noexcept{
    QMessageBox::critical(nullptr, "Error!", "Missing memory...");
    return;
}

void stackinterpreter::Stack::INPUT(QWidget *parent, const QString &description, QVector<QString> &log) noexcept{
    if(stack.size() == max_size){
        QMessageBox::critical(nullptr, "Error!", "Stack overflow! Please clear or resize the stack to continue...");
        return;
    }
    bool ok;
    int value = QInputDialog::getInt(parent, "Type a number", "Number:", 0, -2147483647, 2147483647, 1, &ok);
    if(ok){
        stack.push(value);
        stackutil::log_write(description, log, QString::number(value));
    }
    else
        QMessageBox::information(parent, "Warning", "Instruction canceled!");
}

void stackinterpreter::Stack::PRINT(QWidget *parent, const QString &description, QVector<QString> &log) noexcept{
    if(stack.empty()){
        QMessageBox::critical(nullptr, "Error!", "Stack underflow! Not enough values to execute the instruction...");
        return;
    }
    int value = stack.top();
    stack.pop();
    stackutil::log_write(description, log, QString::number(value));
    QMessageBox::information(parent, "PRINT Instruction", "Value discarded and printed: " + QString::fromStdString(std::to_string(value)));
}

void stackinterpreter::Stack::ADD(const QString &description, QVector<QString> &log) noexcept{
    if(stack.empty() || stack.size() == 1){
        QMessageBox::critical(nullptr, "Error!", "Stack underflow! Not enough values to execute the instruction...");
        return;
    }
    int value1, value2;
    value1 = stack.top(); stack.pop();
    value2 = stack.top(); stack.pop();
    stack.push(value2 + value1);
    stackutil::log_write(description, log, QString::number(value1), QString::number(value2));
}

void stackinterpreter::Stack::SUB(const QString &description, QVector<QString> &log) noexcept{
    if(stack.empty() || stack.size() == 1){
        QMessageBox::critical(nullptr, "Error!", "Stack underflow! Not enough values to execute the instruction...");
        return;
    }
    int value1, value2;
    value1 = stack.top(); stack.pop();
    value2 = stack.top(); stack.pop();
    stack.push(value2 - value1);
    stackutil::log_write(description, log, QString::number(value1), QString::number(value2));
}

void stackinterpreter::Stack::MUL(const QString &description, QVector<QString> &log) noexcept{
    if(stack.empty() || stack.size() == 1){
        QMessageBox::critical(nullptr, "Error!", "Stack underflow! Not enough values to execute the instruction...");
        return;
    }
    int value1, value2;
    value1 = stack.top(); stack.pop();
    value2 = stack.top(); stack.pop();
    stack.push(value2 * value1);
    stackutil::log_write(description, log, QString::number(value1), QString::number(value2));
}

void stackinterpreter::Stack::DIV(const QString &description, QVector<QString> &log) noexcept{
    if(stack.empty() || stack.size() == 1){
        QMessageBox::critical(nullptr, "Error!", "Stack underflow! Not enough values to execute the instruction...");
        return;
    }
    int value1, value2;
    value1 = stack.top(); stack.pop();
    value2 = stack.top(); stack.pop();
    stack.push(value2 / value1);
    stackutil::log_write(description, log, QString::number(value1), QString::number(value2));
}

void stackinterpreter::Stack::SWAP(const QString &description, QVector<QString> &log) noexcept{
    if(stack.empty() || stack.size() == 1){
        QMessageBox::critical(nullptr, "Error!", "Stack underflow! Not enough values to execute the instruction...");
        return;
    }
    int value1, value2;
    value1 = stack.top(); stack.pop();
    value2 = stack.top(); stack.top();
    stack.push(value1);
    stack.push(value2);
    stackutil::log_write(description, log, QString::number(value1), QString::number(value2));
}

void stackinterpreter::Stack::DROP(const QString &description, QVector<QString> &log) noexcept{
    if(stack.empty()){
        QMessageBox::critical(nullptr, "Error!", "Stack underflow! Not enough values to execute the instruction...");
        return;
    }
    int value = stack.top();
    stack.pop();
    stackutil::log_write(description, log, QString::number(value));
}

void stackinterpreter::Stack::DUP(const QString &description, QVector<QString> &log) noexcept{
    if(stack.size() == max_size){
        QMessageBox::critical(nullptr, "Error!", "Stack overflow! Please clear or resize the stack to continue...");
        return;
    }
    int value = stack.top();
    stack.push(value);
    stackutil::log_write(description, log, QString::number(value));
}

void stackinterpreter::Stack::HLT(const QString &description, QVector<QString> &log) noexcept{
    while(!stack.empty())
        stack.pop();
    stackutil::log_write(description, log);
    // CLEAR MEMORY
    // ASK FOR .CPP .ASM .FORTH EXPORTS
}

void stackinterpreter::operator<<(QLineEdit &os, const stackinterpreter::Stack &stack){
    std::stack<int> /* T template type soon */ stack_buffer = stack.get_stack();
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

/// STACKUTIL NAMESPACE IMPLEMENTATIONS BELOW

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

void stackinterpreter::stackutil::log_write(const QString &instruction, QVector<QString> &log, const QString &value1, const QString &value2) noexcept{
    if(value1 == "null" && value2 == "null"){
        log.append(instruction);
        return;
    }
    else if(value2 == "null"){
        log.append(instruction + "    " + value1);
        return;
    }
    log.append(instruction + "    " + value1 + " " + value2);
}

