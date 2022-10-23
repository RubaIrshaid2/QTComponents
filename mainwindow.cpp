#include "mainwindow.h"
#include "./ui_mainwindow.h"
#include "qmessagebox.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    ui->progressBar->setValue(ui->horizontalSlider->value());
    connect(ui->horizontalSlider , SIGNAL(valueChanged(int)) , ui->progressBar , SLOT(setValue(int)));

    ui->comboBox->addItems({"college of inforamtion technology and computer engineering" , "college of applied science " });

}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_pushButton_5_clicked()
{
    ui->lineEdit->setText("u clicked the button right now :) (: ");

    QEasingCurve curve ;
    curve.setType(QEasingCurve::SineCurve);

    animation2 = new QPropertyAnimation(ui->warningButton , "geometry");
    animation2->setDuration(2000);
    animation2->setStartValue(ui->warningButton->geometry());
    animation2->setEndValue(QRect(450,150,250,250));
    animation2->setEasingCurve(curve);

    animation3 = new QPropertyAnimation(ui->aboutBox , "geometry");
    animation3->setDuration(2000);
    animation3->setStartValue(ui->aboutBox->geometry());
    animation3->setEndValue(QRect(450,150,250 , 250));
    animation3->setEasingCurve(curve);

    animation4 = new QPropertyAnimation(ui->QuestionBox , "geometry");
    animation4 -> setDuration(3000);
    animation4->setStartValue(ui->QuestionBox->geometry());
    animation4->setEndValue(QRect(450,150,250,250));
    animation4->setEasingCurve(curve);

    animation5 = new QPropertyAnimation(ui->infoBox , "geometry");
    animation5 -> setDuration(3000);
    animation5->setStartValue(ui->infoBox->geometry());
    animation5->setEndValue(QRect(450,150,250,250));
    animation5->setEasingCurve(curve);

//    animationGroup = new QParallelAnimationGroup();
//    animationGroup->addAnimation(animation2);
//    animationGroup->addAnimation(animation3);
//    animationGroup->addAnimation(animation4);
//    animationGroup->addAnimation(animation5);

//    animationGroup->start();

    seqAnimationGroup = new QSequentialAnimationGroup();

    seqAnimationGroup->addAnimation(animation2);
    seqAnimationGroup->addAnimation(animation3);
    seqAnimationGroup->addAnimation(animation4);
    seqAnimationGroup->addAnimation(animation5);

    seqAnimationGroup->start();

}


void MainWindow::on_checkBox_2_stateChanged(int arg1)
{
    if(ui->checkBox_2->isChecked())
    {
        ui->label->setText("U checked the box");
    }
    else
    {
        ui->label->setText("U unchecked The Box");
    }
}


void MainWindow::on_comboBox_currentTextChanged(const QString &arg1)
{
    ui->label_2->setText("The choosen item is : "+arg1);
}


void MainWindow::on_pushButton_3_clicked()
{
    QListWidgetItem *item = ui->listWidget->currentItem();
    item->setTextColor(Qt::red);
}


void MainWindow::on_boldListWidget_clicked()
{
    QFont font("Times", 15 , QFont::Bold , true);
    QListWidgetItem *item = ui->listWidget->currentItem();
    item->setFont(font);
}


void MainWindow::on_background_clicked()
{
    QListWidgetItem *item = ui->listWidget->currentItem();
    item->setBackground(Qt::blue);
}


void MainWindow::on_infoBox_clicked()
{
    QMessageBox::information(this , "message box " , "This is an Information message box");
}


void MainWindow::on_warningButton_clicked()
{
    QMessageBox::warning(this , "warning" , "This is a warning box");
}


void MainWindow::on_aboutBox_clicked()
{
    QMessageBox::about(this , "About Box" , "This is about message box");
}


void MainWindow::on_QuestionBox_clicked()
{
    QMessageBox::question(this, "question Box" , "Are you ok?");
}


void MainWindow::on_action3_triggered()
{
    QApplication::quit();
}


void MainWindow::on_actionabout_Qt_triggered()
{
    QApplication::aboutQt();
}


void MainWindow::on_actionhelp_triggered()
{
    QMessageBox::question(this,"HELP" , "Do you need help");
}


void MainWindow::on_actionfont_triggered()
{
    bool ok;
    QFont font = QFontDialog::getFont(&ok, QFont("Times" , 14 , QFont::Bold) , this);
    ui->textEdit->setFont(font);
}


void MainWindow::on_actioncolor_triggered()
{
    QColor color = QColorDialog::getColor(Qt::blue , this);
    ui->textEdit->setTextColor(color);
}


void MainWindow::on_action1_triggered()
{
    QString fileName = QFileDialog::getOpenFileName(this , "open a file","c://");
    ui->textEdit->setText(fileName);
}

