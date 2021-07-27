#include "AboutForm.h"

AboutForm::AboutForm(QWidget *parent)
	: QDialog(parent)
{
	setupUi(this);
}

void AboutForm::setBackground()
{
    QPixmap bkgnd(":/MainInterface/fon.png");
    bkgnd = bkgnd.scaled(size(), Qt::IgnoreAspectRatio, Qt::SmoothTransformation);
    QPalette palette;
    palette.setBrush(QPalette::Background, bkgnd);
    this->setPalette(palette);
}

void AboutForm::resizeEvent(QResizeEvent* evt)
{
    QPixmap bkgnd(":/MainInterface/fon.png");
    bkgnd = bkgnd.scaled(size(), Qt::IgnoreAspectRatio, Qt::SmoothTransformation);
    QPalette p = palette();
    p.setBrush(QPalette::Background, bkgnd);
    setPalette(p);

    QDialog::resizeEvent(evt);
}
