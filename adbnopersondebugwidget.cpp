#include "adbnopersondebugwidget.h"
#include "ui_adbnopersondebugwidget.h"

extern uchar g_screenShotsType;

AdbNoPersonDebugWidget::AdbNoPersonDebugWidget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::AdbNoPersonDebugWidget)
{
    ui->setupUi(this);

    //设置滚动条始终指到最底部
    ui->textBrowser_DebugInfo->moveCursor(QTextCursor::End);
}

AdbNoPersonDebugWidget::~AdbNoPersonDebugWidget()
{
    delete ui;
}

void AdbNoPersonDebugWidget::on_Btn_Set_clicked()
{
    qDebug("click set.");

    set_Command_Read_res(QString("adb shell input keyevent 176"));

    get_Screen_Capture();
}

void AdbNoPersonDebugWidget::on_Btn_Menu_clicked()
{
    qDebug("click menu.");

    set_Command_Read_res(QString("adb shell input keyevent 82"));

    get_Screen_Capture();
}

void AdbNoPersonDebugWidget::on_Btn_Top_clicked()
{
    qDebug("click top.");

    set_Command_Read_res(QString("adb shell input keyevent 19"));

    get_Screen_Capture();
}

void AdbNoPersonDebugWidget::on_Btn_Bottom_clicked()
{
    qDebug("click bottom.");

    set_Command_Read_res(QString("adb shell input keyevent 20"));

    get_Screen_Capture();
}

void AdbNoPersonDebugWidget::on_Btn_Left_clicked()
{
    qDebug("click left.");

    set_Command_Read_res(QString("adb shell input keyevent 21"));

    get_Screen_Capture();
}

void AdbNoPersonDebugWidget::on_Btn_Right_clicked()
{
    qDebug("click right.");

    set_Command_Read_res(QString("adb shell input keyevent 22"));

    get_Screen_Capture();
}

void AdbNoPersonDebugWidget::on_Btn_OK_clicked()
{
    qDebug("click ok.");

    set_Command_Read_res(QString("adb shell input keyevent 23"));

    get_Screen_Capture();
}

void AdbNoPersonDebugWidget::on_Btn_Home_clicked()
{
    qDebug("click home.");

    set_Command_Read_res(QString("adb shell input keyevent 3"));

    get_Screen_Capture();
}

void AdbNoPersonDebugWidget::on_Btn_Back_clicked()
{
    qDebug("click back.");

    set_Command_Read_res(QString("adb shell input keyevent 4"));

    get_Screen_Capture();
}

void AdbNoPersonDebugWidget::on_lineEdit_Command_editingFinished()
{
    qDebug("adb command input finished.");

    set_Command_Read_res(ui->lineEdit_Command->text());
}

void AdbNoPersonDebugWidget::set_Command_Read_res(QString command)
{
    p.start("cmd", QStringList()<<"/c"<<command);
    p.waitForStarted();
    p.waitForFinished();
    QString strTemp=QString::fromLocal8Bit(p.readAllStandardOutput());
    ui->textBrowser_DebugInfo->append(strTemp);
}

void AdbNoPersonDebugWidget::get_Screen_Capture()
{
    QPixmap pixmap;
    if (g_screenShotsType == SET_JPG)
    {
        set_Command_Read_res("adb shell screencap -p /sdcard/1.jpg");
        set_Command_Read_res(QString("adb pull /sdcard/1.jpg ."));
        pixmap = QPixmap("1.jpg");
    }
    else if (g_screenShotsType == SET_PNG)
    {
        set_Command_Read_res("adb shell screencap -p /sdcard/1.png");
        set_Command_Read_res(QString("adb pull /sdcard/1.png ."));
        pixmap = QPixmap("1.png");
    }
    else
        return;

    screen_label.setWindowTitle("机顶盒屏幕截图");
    //图片随Label放大缩小而放大缩小
    screen_label.setScaledContents(true);
    screen_label.setPixmap(pixmap);
    screen_label.show();
}

void AdbNoPersonDebugWidget::on_Btn_getScreenCapture_clicked()
{
    get_Screen_Capture();
}

void AdbNoPersonDebugWidget::on_Btn_doubleBack_clicked()
{
    qDebug("click double back.");

    p.start("cmd", QStringList()<<"/c"<<"adb shell input keyevent 4"<<"adb shell input keyevent 4");
    p.waitForStarted();
    p.waitForFinished();
    QString strTemp=QString::fromLocal8Bit(p.readAllStandardOutput());
    ui->textBrowser_DebugInfo->append(strTemp);

    get_Screen_Capture();
}
