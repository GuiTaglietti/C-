#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QInputDialog>
#include <QMessageBox>
#include <string>
#ifdef _WIN32
#include <Windows.h>
#else
#include <unistd.h>
#endif
#include <iostream>
#include <cstdlib>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}


//Assets

class Stack{
private:
    int array[10];
    int size = -1;

public:
    Stack(){
        memset(this->array, 0, sizeof(this->array));
    }

    void push(int num){
        this->array[++this->size] = num;
    }

    int pop(){
        return this->array[this->size--];
    }

    QString getText(){
        QString aux = "";
        for(int i = 0; i < this->size + 1; i++){
            aux += QString::number(this->array[i]) + (i < this->size ? ", " : "");
        }
        return aux;
    }

    void showStack(QLineEdit *text){
        text->setText(this->getText());
    }

};

class Operations : public Stack{
public:
    void input(QWidget *parent){
        QString text = QInputDialog::getText(parent, "Teste", "Teste");
        float value = text.toFloat();
        this->push(value);
    }

    void add(){
        float n1 = this->pop();
        float n2 = this->pop();
        this->push(n2 + n1);
    }
};


void MainWindow::on_pushButton_clicked()
{
    Operations *stack = new Operations();
    stack->input(this);
    stack->input(this);
    stack->showStack(this->ui->lineEdit);
    sleep(5);
    stack->add();
    stack->showStack(this->ui->lineEdit);
    delete stack;
}

