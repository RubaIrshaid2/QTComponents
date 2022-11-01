#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QFontDialog>
#include <QColorDialog>
#include <QFileDialog>
#include <QPropertyAnimation>
#include <QParallelAnimationGroup>
#include <QSequentialAnimationGroup>
#include <string>
#include <QTreeView>
#include <QFileSystemModel>
#include <QListView>
#include <QHeaderView>

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
    void on_pushButton_5_clicked();

    void on_checkBox_2_stateChanged(int arg1);

    void on_comboBox_currentTextChanged(const QString &arg1);

    void on_pushButton_3_clicked();

    void on_boldListWidget_clicked();

    void on_background_clicked();

    void on_infoBox_clicked();

    void on_warningButton_clicked();

    void on_aboutBox_clicked();

    void on_QuestionBox_clicked();

    void on_action3_triggered();

    void on_actionabout_Qt_triggered();

    void on_actionhelp_triggered();

    void on_actionfont_triggered();

    void on_actioncolor_triggered();

    void on_action1_triggered();

    void on_commandLinkButton_clicked();

private:
    Ui::MainWindow *ui;
    QPropertyAnimation *animation;
    QPropertyAnimation *animation2;
    QPropertyAnimation *animation3;
    QPropertyAnimation *animation4;
    QPropertyAnimation *animation5;

    QParallelAnimationGroup *animationGroup;
    QSequentialAnimationGroup *seqAnimationGroup;
};
#endif // MAINWINDOW_H
