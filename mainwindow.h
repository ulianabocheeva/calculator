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
    void on_btn_for_numbers_clicked();

    void on_btn_for_point_clicked();

    void on_btn_for_delete_clicked();

    void on_btn_for_options_clicked();

    void on_btn_for_equall_clicked();

    void on_btn_for_cancel_clicked();

    void on_btn_help_clicked();

    void on_btn_for_Mplus_clicked();

    void on_btn_for_Mminus_clicked();

    void on_btn_for_M_clicked();

    void on_btn_for_MR_clicked();

    void on_btn_for_MC_clicked();

    void on_btn_trig_clicked();

    void on_btn_for_neg_clicked();

    void enabledButtons(bool statement);

    void enabledTrigButtons(bool statement);

    void enabledNum(bool statement);

    QString actions(QString num1,QString num2,QString operation);

private:
    Ui::MainWindow *ui;
    QString num1;
    QString memory="0";
    QString operation;
};

#endif // MAINWINDOW_H
