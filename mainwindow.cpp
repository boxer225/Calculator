#include "mainwindow.h"
#include "ui_mainwindow.h"

double num_first;

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    connect(ui->pushButton_0, SIGNAL(clicked()), this, SLOT(digits_numbers()));
    connect(ui->pushButton_1, SIGNAL(clicked()), this, SLOT(digits_numbers()));
    connect(ui->pushButton_2, SIGNAL(clicked()), this, SLOT(digits_numbers()));
    connect(ui->pushButton_3, SIGNAL(clicked()), this, SLOT(digits_numbers()));
    connect(ui->pushButton_4, SIGNAL(clicked()), this, SLOT(digits_numbers()));
    connect(ui->pushButton_5, SIGNAL(clicked()), this, SLOT(digits_numbers()));
    connect(ui->pushButton_6, SIGNAL(clicked()), this, SLOT(digits_numbers()));
    connect(ui->pushButton_7, SIGNAL(clicked()), this, SLOT(digits_numbers()));
    connect(ui->pushButton_8, SIGNAL(clicked()), this, SLOT(digits_numbers()));
    connect(ui->pushButton_9, SIGNAL(clicked()), this, SLOT(digits_numbers()));
    connect(ui->pushButton_change, SIGNAL(clicked()), this, SLOT(operations()));
    connect(ui->pushButton_procent, SIGNAL(clicked()), this, SLOT(operations()));
    connect(ui->pushButton_pus, SIGNAL(clicked()), this, SLOT(math_operations()));
    connect(ui->pushButton_minus, SIGNAL(clicked()), this, SLOT(math_operations()));
    connect(ui->pushButton_del, SIGNAL(clicked()), this, SLOT(math_operations()));
    connect(ui->pushButton_mult, SIGNAL(clicked()), this, SLOT(math_operations()));

    ui->pushButton_pus->setCheckable(true);
    ui->pushButton_minus->setCheckable(true);
    ui->pushButton_del->setCheckable(true);
    ui->pushButton_mult->setCheckable(true);

}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::digits_numbers() {
    QPushButton *button = (QPushButton *)sender();
    QString newLabel;
    if (ui->result_show->text().contains('0') && button->text() == '0') {
        newLabel = ui->result_show->text() + button->text();
    }
    else {
        double all_numbers = (ui->result_show->text() + button->text()).toDouble();
        newLabel = QString::number(all_numbers, 'g', 15);
    }
    ui->result_show->setText(newLabel);

}

void MainWindow::on_pushButton_dot_clicked()
{
    if (!ui->result_show->text().contains('.')) ui->result_show->setText(ui->result_show->text() + '.');

}

void MainWindow::operations() {
    QPushButton *button = (QPushButton *)sender();
    double all_numbers = (ui->result_show->text()).toDouble();
    QString newLabel;
    if (button->text() == "+/-") {
        all_numbers *= -1;
    }
    if (button->text() == "%") {
        all_numbers *= 0.01;
    }
    newLabel = QString::number(all_numbers, 'g', 15);
    ui->result_show->setText(newLabel);
}

void MainWindow::on_pushButton_AC_clicked()
{
    ui->pushButton_pus->setChecked(false);
    ui->pushButton_minus->setChecked(false);
    ui->pushButton_del->setChecked(false);
    ui->pushButton_mult->setChecked(false);
    ui->result_show->setText("0");
}


void MainWindow::math_operations() {
    QPushButton *button = (QPushButton *)sender();

    num_first = ui->result_show->text().toDouble();
    ui->result_show->setText("0");
    button->setChecked(true);

}

void MainWindow::on_pushButton_res_clicked()
{
    double labelNumber, num_second;
    QString newlabel;
    num_second = ui->result_show->text().toDouble();
    if (ui->pushButton_pus->isChecked()) {
      labelNumber = num_first + num_second;
      ui->pushButton_pus->setChecked(false);
    }
    if (ui->pushButton_minus->isChecked()) {
      labelNumber = num_first - num_second;
      ui->pushButton_minus->setChecked(false);
    }
    if (ui->pushButton_del->isChecked()) {
      labelNumber = num_first * num_second;
      ui->pushButton_del->setChecked(false);
    }
    if (ui->pushButton_mult->isChecked()) {
      labelNumber = num_first / num_second;
      ui->pushButton_mult->setChecked(false);
    }
    newlabel = QString::number(labelNumber, 'g', 15);
    ui->result_show->setText(newlabel);
}

