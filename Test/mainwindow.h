// mainwindow.h

#ifndef MAINWINDOW_H
#define MAINWINDOW_H

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

private slots:
    void onButtonDigitClicked();
    void onOperatorButtonClicked();
    void onEqualsButtonClicked();


private:
    Ui::MainWindow *ui;

    QString currentNumber;
    QStringList numbersAndOperators;

};

#endif // MAINWINDOW_H