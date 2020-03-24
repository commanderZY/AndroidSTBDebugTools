#ifndef RELEASENOTESWIDGET_H
#define RELEASENOTESWIDGET_H

#include <QWidget>

namespace Ui {
class ReleaseNotesWidget;
}

class ReleaseNotesWidget : public QWidget
{
    Q_OBJECT

public:
    explicit ReleaseNotesWidget(QWidget *parent = 0);
    ~ReleaseNotesWidget();

private:
    Ui::ReleaseNotesWidget *ui;
};

#endif // RELEASENOTESWIDGET_H
