/**
 * @headerfile stack.h
 * @author Guilherme Martinelli Taglietti
*/
#ifndef STACK_H
#define STACK_H

#include "qlineedit.h"
#include "qwidget.h"
#include <cstddef>
#include <stack>
#include <QString>

namespace stackinterpreter{

class Stack;

namespace stackutil{

std::stack<int> prepare(std::stack<int> &stack) noexcept;
void log_write(const QString &instruction, QVector<QString> &log, const QString &value1  = "null", const QString &value2  = "null") noexcept;

} // namespace stackutil

class Stack{
public:
    Stack() : Stack(16){} // Default max size = 16
    Stack(std::size_t _max_size) : max_size(_max_size){}
    Stack(const Stack &cpy) : stack(cpy.stack), max_size(cpy.max_size){}
    virtual ~Stack(){}
    Stack& operator=(const Stack &rhs);

    friend void operator<<(QLineEdit &os, const Stack &stack);
    friend std::stack<int> stackutil::prepare(std::stack<int> &stack) noexcept;

    void PUSHI(int /*T*/ value, const QString &description, QVector<QString> &log) noexcept;
    void PUSH(const QString &hex, const QString &description, QVector<QString> &log) noexcept;
    void POP(const QString &hex, const QString &description, QVector<QString> &log) noexcept;
    void INPUT(QWidget* parent, const QString &description, QVector<QString> &log) noexcept;
    void PRINT(QWidget *parent, const QString &description, QVector<QString> &log) noexcept;
    void ADD(const QString &description, QVector<QString> &log) noexcept;
    void SUB(const QString &description, QVector<QString> &log) noexcept;
    void MUL(const QString &description, QVector<QString> &log) noexcept;
    void DIV(const QString &description, QVector<QString> &log) noexcept;
    void SWAP(const QString &description, QVector<QString> &log) noexcept;
    void DROP(const QString &description, QVector<QString> &log) noexcept;
    void DUP(const QString &description, QVector<QString> &log) noexcept;
    void HLT(const QString &description, QVector<QString> &log) noexcept;

    [[nodiscard]] const std::stack<int>& get_stack() const noexcept{ return stack; } /// Inline function
    [[nodiscard]] std::size_t get_max_size() const noexcept{ return max_size; } /// Inline function

private:
    std::stack<int> stack;
    std::size_t max_size;

};

} // namespace stackinterpreter

#endif // STACK_H
