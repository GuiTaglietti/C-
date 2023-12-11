#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include "instruction_handler.h"
#include "qabstractbutton.h"
#include "stack.h"
#include <QMainWindow>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();
    void init_selector() noexcept;

private slots:
    void on_instructions_select_currentIndexChanged(int index);
    void on_exec_button_clicked();
    void update_stack_progressbar();
    void on_reset_instruction_log_clicked(QAbstractButton *button);

    void on_reset_memory_log_clicked(QAbstractButton *button);

    void on_pushButton_clicked();

private:
    Ui::MainWindow *ui;
    stackinterpreter::InstructionHandler instruction_handler;
    stackinterpreter::Stack stack;
};
#endif // MAINWINDOW_H
