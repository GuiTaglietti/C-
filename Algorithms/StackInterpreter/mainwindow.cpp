#include "mainwindow.h"
#include "asmexporter.h"
#include "cppexporter.h"
#include "customoptions.h"
#include "instruction_handler.h"
#include "instructions.h"
#include "ui_mainwindow.h"
#include "QMessageBox"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    init_selector();
    ui->stack_pb->setRange(0, 100);
    ui->stack_pb->setValue(0);
    ui->label_stack->setText("Stack (Current max size: " + QString::number(stack.get_max_size()) + ")");
}

MainWindow::~MainWindow()
{
    delete ui;
    delete options_dialog_box;
}

/**
 * @brief Set up the selector in the UI
*/
void MainWindow::init_selector() noexcept
{
    ui->instructions_select->addItem("PUSHI", stackinterpreter::Instructions::PUSHI);
    ui->instructions_select->addItem("PUSH", stackinterpreter::Instructions::PUSH);
    ui->instructions_select->addItem("POP", stackinterpreter::Instructions::POP);
    ui->instructions_select->addItem("INPUT", stackinterpreter::Instructions::INPUT);
    ui->instructions_select->addItem("PRINT", stackinterpreter::Instructions::PRINT);
    ui->instructions_select->addItem("ADD", stackinterpreter::Instructions::ADD);
    ui->instructions_select->addItem("SUB", stackinterpreter::Instructions::SUB);
    ui->instructions_select->addItem("MUL", stackinterpreter::Instructions::MUL);
    ui->instructions_select->addItem("DIV", stackinterpreter::Instructions::DIV);
    ui->instructions_select->addItem("SWAP", stackinterpreter::Instructions::SWAP);
    ui->instructions_select->addItem("DROP", stackinterpreter::Instructions::DROP);
    ui->instructions_select->addItem("DUP", stackinterpreter::Instructions::DUP);
    ui->instructions_select->addItem("HLT", stackinterpreter::Instructions::HLT);
}

/**
 * @brief Set the line edit to read only or not, also changes the placeholder based on read only or not
 * @param index The index of the option (Relative with enum type)
*/
void MainWindow::on_instructions_select_currentIndexChanged(int index)
{
    if(index == stackinterpreter::Instructions::PUSHI ||
       index == stackinterpreter::Instructions::PUSH  ||
       index == stackinterpreter::Instructions::POP)
    {
        ui->flagged_values->setReadOnly(false);
        ui->flagged_values->setPlaceholderText("Type here...");
        return;
    }
    ui->flagged_values->setReadOnly(true);
    ui->flagged_values->setPlaceholderText("");
    ui->flagged_values->setText("");
}

/**
 * @brief Execute the instruction selected in the options selector
 * @note Uses a InstructionHandler class member function (handle_instructions()) to prepare wich instruction will be executed
*/
void MainWindow::on_exec_button_clicked()
{
    ui->instruction_log->setText("");
    stackinterpreter::instruction_tuple instruction_buffer = instruction_handler.handle_instruction(ui->instructions_select->currentIndex(), ui->flagged_values->text());
    instruction_handler.execute(this, stack, instruction_buffer.instruction, instruction_buffer.value, instruction_handler, ui->instructions_select->currentText());
    update_stack_progressbar();
    *ui->stackostream << stack;
    stack.display_memory_log(*ui->memostream);
    *ui->instruction_log << instruction_handler;
}

/**
 * @brief Update the progress bar by calculating the percentage to update the progress bar depending on wich size the stack have
*/
void MainWindow::update_stack_progressbar(){
    int stack_size = static_cast<int>(stack.get_stack().size());
    int percentage = static_cast<int>((static_cast<float>(stack_size) / stack.get_max_size()) * 100);
    ui->stack_pb->setValue(percentage);
}

void MainWindow::on_cpp_export_button_clicked()
{
    stackinterpreter::CPPExporter exporter;
    if(!exporter.export_to_file(instruction_handler.get_log())){
        QMessageBox::critical(this, "Error", "Error exporting to .cpp file, please, try again!");
        return;
    }
    QMessageBox::information(this, "Success", "File successfully exported to .cpp!");
}


void MainWindow::on_asm_export_button_clicked()
{
    stackinterpreter::ASMExporter exporter;
    if(!exporter.export_to_file(instruction_handler.get_log())){
        QMessageBox::critical(this, "Error", "Error exporting to .asm file, please, try again!");
        return;
    }
    QMessageBox::information(this, "Success", "File successfully exported to .asm!");
}


void MainWindow::on_options_button_clicked()
{
    options_dialog_box = new stackinterpreter::CustomOptions(this);
    // options_dialog_box->init();
    if(options_dialog_box->exec() == QDialog::Accepted){
        bool is_integer_temp1, is_integer_temp2;
        QString temp1 = options_dialog_box->get_stack_size_input(); QString temp2 = options_dialog_box->get_memory_size_input();
        int value1 = temp1.toInt(&is_integer_temp1), value2 = temp2.toInt(&is_integer_temp2);
        if(is_integer_temp1 && is_integer_temp2 && value1 <= stack.get_max_possible_size() && value2 <= stack.get_max_possible_mem_size()){
            if(!stack.resize_stack(value1) || !stack.resize_memory(value2)){
                QMessageBox::critical(this, "Error", "Not allowed to set sizes smallers than the actual number of elements in the stack/memory!");
                return;
            }
            int stack_size = static_cast<int>(stack.get_stack().size());
            int percentage = static_cast<int>((static_cast<float>(stack_size) / stack.get_max_size()) * 100);
            ui->stack_pb->setValue(percentage);
            ui->label_stack->setText("Stack (Current max size: " + QString::number(stack.get_max_size()) + ")");
            QMessageBox::information(this, "Success", "New sizes successfully applied!");
        }
        else if(value1 > stack.get_max_possible_size() || value2 > stack.get_max_possible_mem_size())
            QMessageBox::critical(this, "Error", "Please, insert a smaller value!");
        else
            QMessageBox::critical(this, "Error", "Type a valid number!");
    }
    else
        QMessageBox::information(this, "Sucess", "Successfully canceled!");
}

