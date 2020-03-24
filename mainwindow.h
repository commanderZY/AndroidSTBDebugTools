#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QMessageBox>
#include "adbnopersondebugwidget.h"
#include "releasenoteswidget.h"
#include <QProcess>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

private slots:
    void on_action_adb_noperson_debug_triggered();

    void on_action_version_about_triggered();

    void on_action_openCmd_triggered();

    void on_action_openCmder_triggered();

    void on_action_setPng_triggered();

    void on_action_setJpg_triggered();

private:
    Ui::MainWindow *ui;
    AdbNoPersonDebugWidget nopersonDebugwidget;
    ReleaseNotesWidget releaseNotesWgt;
    QProcess mProcess;
};

#endif // MAINWINDOW_H
