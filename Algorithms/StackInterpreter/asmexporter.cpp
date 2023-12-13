#include "asmexporter.h"
#include <fstream>
#include <QVector>
#include <QStringList>
#include <QDir>

bool stackinterpreter::ASMExporter::export_to_file(const QVector<QString> &instruction_log) const{
    if(!instruction_log.size())
        return false;
    try{
        std::ofstream asmfile(filename.toStdString().c_str());
        asmfile << ".section .data\n    stack: .skip 1000\n\n.section .text\n    .global _start\n\n_start:\n    lea rsi, stack\n";
        for(const QString &instruction : instruction_log){
            QStringList parsed = instruction.split("    ");
            if(parsed[0] == "PUSHI")
                asmfile << "    movl $" << parsed[1].toInt() << ", (%rsi)\n    addq $4, %rsi\n";
            else if(parsed[0] == "PUSH")
                asmfile << "    movl (%rsi), %eax\n    movl %eax, " << parsed[1].toInt() << "(%rsi)\n    addq $4, %rsi\n";
            else if(parsed[0] == "POP")
                asmfile << "    movl " << parsed[1].toInt() << "(%rsi), %eax\n    movl %eax, (%rsi)\n    addq $4, %rsi\n";
            else if(parsed[0] == "INPUT")
                asmfile << "    movl $0, %eax\n    movl $3, %ebx\n    movl $1, %ecx\n    lea %edx, [rsi]\n    int $0x80\n    addq $4, %rsi\n";
            else if(parsed[0] == "ADD" || parsed[0] == "SUB" || parsed[0] == "MUL" || parsed[0] == "DIV"){
                asmfile << "    movl (%rsi), %eax\n    addq $4, %rsi\n";
                asmfile << "    movl (%rsi), %ebx\n    addq $4, %rsi\n";
                if(parsed[0] == "ADD")
                    asmfile << "    addl %ebx, %eax\n";
                else if(parsed[0] == "SUB")
                    asmfile << "    subl %ebx, %eax\n";
                else if(parsed[0] == "MUL")
                    asmfile << "    imul %ebx, %eax\n";
                else if(parsed[0] == "DIV")
                    asmfile << "    movl $0, %edx\n    idiv %ebx\n";
                asmfile << "    movl %eax, (%rsi)\n";
            }
            else if(parsed[0] == "SWAP"){
                asmfile << "    movl (%rsi), %eax\n    addq $4, %rsi\n";
                asmfile << "    movl (%rsi), %ebx\n    addq $4, %rsi\n";
                asmfile << "    movl %ebx, (%rsi)\n    movl %eax, 4(%rsi)\n";
            }
            else if(parsed[0] == "DUP"){
                asmfile << "    movl (%rsi), %eax\n    movl %eax, (%rsi)\n    addq $4, %rsi\n";
            }
            else if(parsed[0] == "DROP")
                asmfile << "    subq $4, %rsi\n";
            else if(parsed[0] == "PRINT")
                asmfile << "    subq $4, %rsi\n";
        }
        asmfile << "    movl $1, %eax\n    xorl %ebx, %ebx\n    int $0x80\n";
        return true;
    } catch(const std::exception &exception){
        QFile::remove(filename);
        return false;
    }
}
