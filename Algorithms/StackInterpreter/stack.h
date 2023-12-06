/**
 * @headerfile stack.h
 * @author Guilherme Martinelli Taglietti
*/
#ifndef STACK_H
#define STACK_H

#include "qwidget.h"
#include <cstddef>
#include <stack>
#include <QString>

namespace stackinterpreter{

class Stack{
public:
    Stack() : Stack(16){} // TEMP
    Stack(std::size_t _max_size);
    virtual ~Stack();
    Stack(const Stack &cpy);
    Stack& operator=(const Stack &rhs);

    void PUSHI(int /*T*/ value) noexcept;
    void PUSH(const QString &hex) noexcept;
    void POP(const QString &hex) noexcept;
    void INPUT(QWidget* parent) noexcept;
    void PRINT(QWidget *parent) noexcept;
    void ADD() noexcept;
    void SUB() noexcept;
    void MUL() noexcept;
    void DIV() noexcept;
    void SWAP() noexcept;
    void DROP() noexcept;
    void DUP() noexcept;
    void HLT() noexcept;

private:
    std::stack<int> stack;
    std::size_t max_size;

};

} // namespace stackinterpreter

#endif // STACK_H
