#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include "instruction_handler.h"
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

private:
    Ui::MainWindow *ui;
    stackinterpreter::Stack stack;
    stackinterpreter::InstructionHandler instruction_handler;
};
#endif // MAINWINDOW_H
