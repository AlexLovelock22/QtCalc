// mainwindow.cpp

#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QDebug> // For debug output

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent), ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    // Connect the button's clicked signal to the slot
    connect(ui->btnOne, &QPushButton::clicked, this, &MainWindow::onButtonDigitClicked);
    connect(ui->btnTwo, &QPushButton::clicked, this, &MainWindow::onButtonDigitClicked);
    connect(ui->btnThree, &QPushButton::clicked, this, &MainWindow::onButtonDigitClicked);
    connect(ui->btnFour, &QPushButton::clicked, this, &MainWindow::onButtonDigitClicked);
    connect(ui->btnFive, &QPushButton::clicked, this, &MainWindow::onButtonDigitClicked);
    connect(ui->btnSix, &QPushButton::clicked, this, &MainWindow::onButtonDigitClicked);
    connect(ui->btnSeven, &QPushButton::clicked, this, &MainWindow::onButtonDigitClicked);
    connect(ui->btnEight, &QPushButton::clicked, this, &MainWindow::onButtonDigitClicked);
    connect(ui->btnNine, &QPushButton::clicked, this, &MainWindow::onButtonDigitClicked);
    connect(ui->btnZero, &QPushButton::clicked, this, &MainWindow::onButtonDigitClicked);

    connect(ui->btnPlus, &QPushButton::clicked, this, &MainWindow::onOperatorButtonClicked);
    connect(ui->btnMultiply, &QPushButton::clicked, this, &MainWindow::onOperatorButtonClicked);

    connect(ui->btnEquals, &QPushButton::clicked, this, &MainWindow::onEqualsButtonClicked);



}

MainWindow::~MainWindow()
{
    delete ui;
}
void MainWindow::onButtonDigitClicked()
{
    QPushButton *button = qobject_cast<QPushButton *>(sender());
    if (button)
        ui->txtBox->insertPlainText(button->text()); // Append the number

    if (button)
        currentNumber = currentNumber+button->text();
    qDebug() << currentNumber;





}

void MainWindow::onOperatorButtonClicked()
{
    QPushButton *button = qobject_cast<QPushButton *>(sender());
    if (button)
        ui->txtBox->insertPlainText(" " + button->text() + " "); // Append the operator

    if(button)
        numbersAndOperators << currentNumber << button->text();
    qDebug() << "Saved List : " << numbersAndOperators;
    currentNumber = "";

}

void MainWindow::onEqualsButtonClicked() {
    qDebug() << numbersAndOperators;
}
