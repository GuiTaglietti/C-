#include "cppexporter.h"
#include <fstream>
#include <QVector>
#include <QStringList>
#include <QDir>

void stackinterpreter::CPPExporter::export_to_file(const QVector<QString> &instruction_log) const{
    QString desktop_path = QDir::homePath() + "/Desktop/";
    QDir exports_dir(desktop_path + "Exports");
    if(!exports_dir.exists())
        exports_dir.mkpath(".");
    QString path = exports_dir.filePath(filename);
    std::ofstream cppfile(path.toStdString());
    cppfile << "#include <iostream>\n#include <stack>\n\nint main(){\n    std::stack<int> stack;\n";
    for(const QString &instruction : instruction_log){
        QStringList parsed = instruction.split("    ");
        if(parsed[0] == "PUSHI")
            cppfile << "    stack.push(" << parsed[1].toInt() << ");\n";
        else if(parsed[0] == "PUSH")
            cppfile << "    stack.pop(); /* PUSHED A VALUE FROM THE STACK TO MEMORY IN THE ADDRESS: " << parsed[1].toInt() << " */\n";
        else if(parsed[0] == "POP")
            cppfile << "    stack.push(" << parsed[1].toInt() << "); /* PUSHED A VALUE THAT WAS ON MEMORY TO THE STACK: " << parsed[1].toInt() << " */\n";
        else if(parsed[0] == "INPUT")
            cppfile << "    stack.push(" << parsed[1].toInt() << ");\n";
        else if(parsed[0] == "ADD"){
            cppfile << "    int v1 = stack.top(); stack.pop();\nint v2 = stack.top(); stack.pop();\n";
            cppfile << "    stack.push(v1 + v2);\n";
        }
        else if(parsed[0] == "SUB"){
            cppfile << "    int v1 = stack.top(); stack.pop();\nint v2 = stack.top(); stack.pop();\n";
            cppfile << "    stack.push(v1 - v2);\n";
        }
        else if(parsed[0] == "MUL"){
            cppfile << "    int v1 = stack.top(); stack.pop();\nint v2 = stack.top(); stack.pop();\n";
            cppfile << "    stack.push(v1 * v2);\n";
        }
        else if(parsed[0] == "DIV"){
            cppfile << "    int v1 = stack.top(); stack.pop();\nint v2 = stack.top(); stack.pop();\n";
            cppfile << "    stack.push(v1 / v2);\n";
        }
        else if(parsed[0] == "SWAP"){
            cppfile << "    int v1 = stack.top(); stack.pop();\nint v2 = stack.top(); stack.pop();\n";
            cppfile << "    stack.push(v1);\n";
            cppfile << "    stack.push(v2);\n";
        }
        else if(parsed[0] == "DUP"){
            cppfile << "    int v1 = stack.top();\n";
            cppfile << "    stack.push(v1);\n";
        }
        else if(parsed[0] == "DROP")
            cppfile << "    stack.pop();\n";
    }
    cppfile << "    return 0;\n}";
}
