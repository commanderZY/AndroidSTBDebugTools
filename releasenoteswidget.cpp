#include "releasenoteswidget.h"
#include "ui_releasenoteswidget.h"

ReleaseNotesWidget::ReleaseNotesWidget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::ReleaseNotesWidget)
{
    ui->setupUi(this);
}

ReleaseNotesWidget::~ReleaseNotesWidget()
{
    delete ui;
}
