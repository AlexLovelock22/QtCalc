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


    if (button) {
        ui->txtBox->insertPlainText(button->text()); // Append the number
        wasLastInputAnOperator = false;
    }

    if (button) {
        currentNumber = currentNumber+button->text();
        qDebug() << currentNumber;
        wasLastInputAnOperator = false;
    }




}

// Adding a new operator
void MainWindow::onOperatorButtonClicked()
{
    QPushButton *button = qobject_cast<QPushButton *>(sender());
    if (!button) return;

    QString newOperator = button->text();

    // If the last input was an operator, replace it with the new operator
    if (wasLastInputAnOperator) {
        if (!numbersAndOperators.isEmpty()) {
            numbersAndOperators.removeLast(); // Remove the last operator
        }
        numbersAndOperators << newOperator; // Add the new operator

        // Update the display: remove the last operator and add the new one
        QString currentText = ui->txtBox->toPlainText();
        int lastSpaceIndex = currentText.lastIndexOf(' ');
        if (lastSpaceIndex != -1) {
            currentText = currentText.left(lastSpaceIndex);
        }

        ui->txtBox->setPlainText(currentText + " " + newOperator + " ");
    } else {
        // If the last input was not an operator, simply append the current number and operator
        if (!currentNumber.isEmpty()) {
            numbersAndOperators << currentNumber; // Add the current number if it's not empty
            currentNumber.clear();
        }
        numbersAndOperators << newOperator;
        wasLastInputAnOperator = true;

        // Update the display
        ui->txtBox->insertPlainText(" " + newOperator);
    }

    qDebug() << "Saved List : " << numbersAndOperators;
}



void MainWindow::onEqualsButtonClicked() {
    if (!currentNumber.isEmpty()) {
        numbersAndOperators << currentNumber; // Add the last number
    }
    qDebug() << "Final List : " << numbersAndOperators;

    currentNumber.clear(); // Reset for the next calculation
    numbersAndOperators.clear(); // Clear the list for the next calculation
    ui->txtBox->clear();
}
