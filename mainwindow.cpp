#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "QMessageBox"
#include "options.h"
#define LEN 30
#define ERROR 98765e-99

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow){
    ui->setupUi(this);
    connect(ui->btn_for_0, SIGNAL(clicked()),this, SLOT(on_btn_for_numbers_clicked()));
    connect(ui->btn_for_1, SIGNAL(clicked()),this, SLOT(on_btn_for_numbers_clicked()));
    connect(ui->btn_for_2, SIGNAL(clicked()),this, SLOT(on_btn_for_numbers_clicked()));
    connect(ui->btn_for_3, SIGNAL(clicked()),this, SLOT(on_btn_for_numbers_clicked()));
    connect(ui->btn_for_4, SIGNAL(clicked()),this, SLOT(on_btn_for_numbers_clicked()));
    connect(ui->btn_for_5, SIGNAL(clicked()),this, SLOT(on_btn_for_numbers_clicked()));
    connect(ui->btn_for_6, SIGNAL(clicked()),this, SLOT(on_btn_for_numbers_clicked()));
    connect(ui->btn_for_7, SIGNAL(clicked()),this, SLOT(on_btn_for_numbers_clicked()));
    connect(ui->btn_for_8, SIGNAL(clicked()),this, SLOT(on_btn_for_numbers_clicked()));
    connect(ui->btn_for_9, SIGNAL(clicked()),this, SLOT(on_btn_for_numbers_clicked()));
    connect(ui->btn_for_plus, SIGNAL(clicked()),this, SLOT(on_btn_for_options_clicked()));
    connect(ui->btn_for_minus, SIGNAL(clicked()),this, SLOT(on_btn_for_options_clicked()));
    connect(ui->btn_for_div, SIGNAL(clicked()),this, SLOT(on_btn_for_options_clicked()));
    connect(ui->btn_for_mult, SIGNAL(clicked()),this, SLOT(on_btn_for_options_clicked()));
    connect(ui->btn_sin, SIGNAL(clicked()),this, SLOT(on_btn_trig_clicked()));
    connect(ui->btn_cos, SIGNAL(clicked()),this, SLOT(on_btn_trig_clicked()));
    connect(ui->btn_tg, SIGNAL(clicked()),this, SLOT(on_btn_trig_clicked()));
    connect(ui->btn_ctg, SIGNAL(clicked()),this, SLOT(on_btn_trig_clicked()));
}

MainWindow::~MainWindow(){
    delete ui;
}

void MainWindow::enabledButtons(bool statement){
    ui->btn_for_plus->setEnabled(statement);
    ui->btn_for_minus->setEnabled(statement);
    ui->btn_for_mult->setEnabled(statement);
    ui->btn_for_div->setEnabled(statement);
    ui->btn_for_equall->setEnabled(statement);
}

void MainWindow::enabledTrigButtons(bool statement){
    ui->btn_sin->setEnabled(statement);
    ui->btn_cos->setEnabled(statement);
    ui->btn_tg->setEnabled(statement);
    ui->btn_ctg->setEnabled(statement);
}

void MainWindow::enabledNum(bool statement){
    ui->btn_for_0->setEnabled(statement);
    ui->btn_for_1->setEnabled(statement);
    ui->btn_for_2->setEnabled(statement);
    ui->btn_for_3->setEnabled(statement);
    ui->btn_for_4->setEnabled(statement);
    ui->btn_for_5->setEnabled(statement);
    ui->btn_for_6->setEnabled(statement);
    ui->btn_for_7->setEnabled(statement);
    ui->btn_for_8->setEnabled(statement);
    ui->btn_for_9->setEnabled(statement);
}

void MainWindow::on_btn_for_numbers_clicked(){
    QPushButton *btn = (QPushButton *)sender();
    ui->btn_for_delete->setEnabled(true);
    enabledButtons(true);
    enabledTrigButtons(true);
    if ((ui->lbl_for_text->text()).size()>LEN)
        QMessageBox::information(this,"Error","It is too big number");
    else{
        if (ui->lbl_for_text->text() == "0")
            ui->lbl_for_text->setText(btn->text());
        else if(ui->lbl_for_text->text() == "-0")
            ui->lbl_for_text->setText("-" + btn->text());
        else{
            this->ui->lbl_for_text->setText(ui->lbl_for_text->text() + btn->text());
            if (!ui->lbl_for_text->text().contains("."))
                ui->btn_for_point->setEnabled(true);
        }
    }
    if (num1=="")
        ui->btn_for_equall->setEnabled(false);
}

void MainWindow::on_btn_for_point_clicked(){
    if (!ui->lbl_for_text->text().contains("."))//проверка на отсутствие точки
        ui->lbl_for_text->setText(ui->lbl_for_text->text()+".");//запись точки в текстлейбл
    ui->btn_for_point->setEnabled(false);//блокировка возможности нажать точку
    enabledTrigButtons(false);//блокировка тригонометрических функций
    enabledButtons(false); //пока нажата точка и не нажата цифра, нельзя нажать действие
}

void MainWindow::on_btn_for_options_clicked(){
    QPushButton *btn = (QPushButton *)sender();//sender тип данных QObject* (класс, вокруг которого построена объектная модель Qt)
    ui->btn_for_point->setEnabled(false);//блокирование кнопок
    enabledButtons(false);//блокировка операций
    enabledTrigButtons(false);//блокировка тригонометрических функций
    enabledNum(true);//разблокировка цифр
    QString temp=ui->lbl_for_text->text();//temp временная переменная для
    if (num1!=""){//проверка на наличие хотя бы одного введенного числа
        num1=actions(num1,ui->lbl_for_text->text(),operation);
    }
    else
        num1=temp; //если не введено только первое число
    operation=btn->text();//в переменную записывается текст с кнопки
    ui->lbl_for_text->setText("");//установка в текстлейбл пустой строки
}

void MainWindow::on_btn_trig_clicked(){
    QPushButton *btn = (QPushButton *)sender();//sender тип данных QObject* (класс, вокруг которого построена объектная модель Qt)
    QString num=ui->lbl_for_text->text();//считывает тест из текстлейбл
    QString func=btn->text();//запись текста с кнопки
    struct options options;//создание структуры
    options.num1=num.toDouble();//запись в структуру
    options.num2=0;//запись в структуру
    QByteArray var = func.toLatin1(); // явное приведение из QString в char* ()
    options.operation=var.data();//явное приведение из QString в char* ()
    double result=entryPoint(trigOperations,options);//результат выполнения функции
    if (result==ERROR)//если функция не существует
        QMessageBox::critical(this,"Error","The function does not exist");//information-с целью информировани, this - указатель на экземпляр класса
    else
        num=QString::number(result);//в num записывается результат
    ui->lbl_for_text->setText(num);//вывод результата на экран
}

void MainWindow::on_btn_for_equall_clicked(){
    ui->btn_for_equall->setEnabled(false);//блокировка =
    num1=actions(num1,ui->lbl_for_text->text(),operation);
    ui->lbl_for_text->setText(num1);//вывод на экран результата
    if (ui->lbl_for_text->text().contains("e")){//если запись содержит экспоненту
        ui->btn_for_delete->setEnabled(false);//блокировка кнопоки удаления цифр
        enabledNum(false);//блокировка цифр
    }
    if ((ui->lbl_for_text->text().contains("inf"))||(ui->lbl_for_text->text().contains("+"))){//если запись равна бесконечности
        ui->btn_for_point->setEnabled(false);//блокировка кнопки .
        ui->btn_for_delete->setEnabled(false);//блокировка кнопки удаления цифр
        enabledButtons(false);//блокировка кнопок
        enabledTrigButtons(false);//блокировка тригонометрических функций
    }
    num1="";//num1 обнуляется, потому что при нажатии = на экране отображается результат и если пользователь продолжит работу с эти числом
    //то функия считает это число с экрана
}

void MainWindow::on_btn_for_neg_clicked(){
    QString str = ui->lbl_for_text->text();//вывод - на экран
    if (str.startsWith("-")){
        str.remove(0,1);
        ui->lbl_for_text->setText(str);
    }
    else if ((ui->lbl_for_text->text()!="")&&(ui->lbl_for_text->text()!="0")){
        ui->lbl_for_text->setText("-"+str);
    }
}

void MainWindow::on_btn_for_delete_clicked(){
    QString str = ui->lbl_for_text->text();//запись в str текста с текстлейбл
    str.chop(1);//удаляет символ с конца строки
    if (str.isEmpty()){//если строка пуста
        ui->btn_for_point->setEnabled(false);//блокировка кнопки .
        enabledButtons(false);//блокировка кнопок
    }
    ui->lbl_for_text->setText(str);//вывод строки на экран после стирания 1 цифры с конца
    if (!ui->lbl_for_text->text().contains("."))//если стерли .
        ui->btn_for_point->setEnabled(true);//разблокировка кнопки .
}

void MainWindow::on_btn_for_cancel_clicked(){
    ui->lbl_for_text->setText("");//установка пустой строки
    num1="";//обнуление переменной
    operation="";//обнуление переменной
    ui->btn_for_point->setEnabled(false);//блокировка кнопки .
    enabledButtons(false);//блокировка кнопок действий
    enabledNum(true);//блокировка цифр
}

void MainWindow::on_btn_help_clicked(){
    QMessageBox::information(this,"Help","If you clicked / or * then all the previous expression will be divided or multiplied");//information-с целью информировани, this - указатель на экземпляр класса
}

void MainWindow::on_btn_for_M_clicked(){
    memory=ui->lbl_for_text->text();//запись в переменную memory текста с экрана
}

void MainWindow::on_btn_for_MR_clicked(){
    ui->lbl_for_text->setText(memory);//вывод переменной memory на экран
    if ((ui->lbl_for_text->text().contains("inf"))||(ui->lbl_for_text->text().contains("e"))){
        enabledNum(false);
        ui->btn_for_delete->setEnabled(false);
        ui->btn_for_point->setEnabled(false);
    }
}

void MainWindow::on_btn_for_MC_clicked(){
    memory="0";//обнуление переменной memorys
}

void MainWindow::on_btn_for_Mplus_clicked(){
    QString num=ui->lbl_for_text->text();//запись во временную переменную текста с экрана
    char op[] = {'+'};
    struct options options = {memory.toDouble(),num.toDouble(),op};
    memory=QString::number(entryPoint(operate,options));
}

void MainWindow::on_btn_for_Mminus_clicked(){
    QString num=ui->lbl_for_text->text();//запись во временную переменную текста с экрана
    char op[] = {'-'};
    struct options options = {memory.toDouble(),num.toDouble(),op};
    memory=QString::number(entryPoint(operate,options));
}

QString MainWindow::actions(QString num1,QString num2,QString operation){
    struct options options;//создание структуры
    options.num1=num1.toDouble();//запись в структуру
    options.num2=num2.toDouble();//запись в структуру
    QByteArray var = operation.toLatin1(); // явное приведение из QString в char* ()
    options.operation=var.data();// явное приведение из QString в char* ()
    double result=entryPoint(operate,options);//запись результата функции
    if (result==ERROR){//если какая-то ошибка
        QMessageBox::information(this,"Error","It is forbidden to divide by zero");//information-с целью информировани, this - указатель на экземпляр класса
        this->on_btn_for_cancel_clicked();//числа, над которыми до этого были произведены действия уже записаны в num1 и не теряются,
        //а действие и num2 стираются; this указатель на экземпляр класса
    }
    else
        num1=QString::number(result);//приведение double к QString
    return num1;
}
