/**
 * @headerfile stack.h
 * @author Guilherme Martinelli Taglietti
*/
#ifndef STACK_H
#define STACK_H

#include "qtextedit.h"
#pragma once

#include "memory.h"
#include "qlineedit.h"
#include "qwidget.h"
#include "QStack"
#include <QString>

namespace stackinterpreter{

class Memory;

namespace stackutil{

QStack<int> prepare(QStack<int> &stack) noexcept;
void log_write(const QString &instruction, QVector<QString> &log, const QString &value1  = "null", const QString &value2  = "null") noexcept;

} // namespace stackutil

class Stack : public Memory{
public:
    Stack() : Stack(16){} // Default max size = 16
    Stack(qsizetype _max_size) : max_size(_max_size){}
    Stack(const Stack &cpy) : stack(cpy.stack), max_size(cpy.max_size){}
    virtual ~Stack(){}
    Stack& operator=(const Stack &rhs);

    friend void operator<<(QLineEdit &os, const Stack &stack);
    friend QStack<int> stackutil::prepare(QStack<int> &stack) noexcept;

    void PUSHI(int /*T*/ value) noexcept;
    void PUSHI(int /*T*/ value, const QString &description, QVector<QString> &log) noexcept;
    void PUSH(int hex, const QString &description, QVector<QString> &log) noexcept;
    void POP(int hex, const QString &description, QVector<QString> &log) noexcept;
    void INPUT(QWidget* parent, const QString &description, QVector<QString> &log) noexcept;
    void PRINT(QWidget *parent, const QString &description, QVector<QString> &log) noexcept;
    void ADD(const QString &description, QVector<QString> &log) noexcept;
    void SUB(const QString &description, QVector<QString> &log) noexcept;
    void MUL(const QString &description, QVector<QString> &log) noexcept;
    void DIV(const QString &description, QVector<QString> &log) noexcept;
    void SWAP(const QString &description, QVector<QString> &log) noexcept;
    int DROP() noexcept;
    int DROP(const QString &description, QVector<QString> &log) noexcept;
    void DUP(const QString &description, QVector<QString> &log) noexcept;
    void HLT(const QString &description, QVector<QString> &log) noexcept;

    [[nodiscard]] const QStack<int>& get_stack() const noexcept{ return stack; } /// Inline function
    [[nodiscard]] qsizetype get_max_size() const noexcept{ return max_size; } /// Inline function

    void display_memory_log(QTextEdit &os) const noexcept;

private:
    QStack<int> stack;
    qsizetype max_size;

};

} // namespace stackinterpreter

#endif // STACK_H
