#include "mainwindow.h"
#include "ui_mainwindow.h"

uchar g_screenShotsType = SET_JPG;

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    this->setWindowTitle(g_appName + g_version);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_action_adb_noperson_debug_triggered()
{
    nopersonDebugwidget.show();
}

void MainWindow::on_action_version_about_triggered()
{
    releaseNotesWgt.show();
}

void MainWindow::on_action_openCmd_triggered()
{
    system("cmd.exe");
}

void MainWindow::on_action_openCmder_triggered()
{
    system("Cmder.exe");
}

void MainWindow::on_action_setPng_triggered()
{
    g_screenShotsType = SET_PNG;

    qDebug("设置截图为png格式");
}

void MainWindow::on_action_setJpg_triggered()
{
    g_screenShotsType = SET_JPG;


    qDebug("设置截图为jpg格式");
}
