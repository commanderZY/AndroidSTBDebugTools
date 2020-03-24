#ifndef ADBNOPERSONDEBUGWIDGET_H
#define ADBNOPERSONDEBUGWIDGET_H

#include <QWidget>
#include <QProcess>
#include <QLabel>
#include "appinfo.h"

namespace Ui {
class AdbNoPersonDebugWidget;
}

class AdbNoPersonDebugWidget : public QWidget
{
    Q_OBJECT

public:
    explicit AdbNoPersonDebugWidget(QWidget *parent = 0);
    ~AdbNoPersonDebugWidget();

private slots:
    void on_Btn_Set_clicked();

    void on_Btn_Menu_clicked();

    void on_Btn_Left_clicked();

    void on_Btn_Back_clicked();

    void on_Btn_Home_clicked();

    void on_Btn_Right_clicked();

    void on_Btn_OK_clicked();

    void on_Btn_Top_clicked();

    void on_Btn_Bottom_clicked();

    void on_lineEdit_Command_editingFinished();

    void set_Command_Read_res(QString command);

    void get_Screen_Capture();

    void on_Btn_getScreenCapture_clicked();

    void on_Btn_doubleBack_clicked();

private:
    Ui::AdbNoPersonDebugWidget *ui;
    QProcess p;
    QLabel screen_label;
};

#endif // ADBNOPERSONDEBUGWIDGET_H
