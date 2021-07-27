#include "PositionDialog.h"

PositionDialog::PositionDialog(QWidget *parent)
	: QDialog(parent)
{
	setupUi(this);
	setWindowSize();
}

void PositionDialog::setBackground()
{
	QPixmap bkgnd(":/MainInterface/fon.png");
	bkgnd = bkgnd.scaled(size(), Qt::IgnoreAspectRatio, Qt::SmoothTransformation);
	QPalette palette;
	palette.setBrush(QPalette::Background, bkgnd);
	this->setPalette(palette);
}

void PositionDialog::resizeEvent(QResizeEvent* evt)
{
	QPixmap bkgnd(":/MainInterface/fon.png");
	bkgnd = bkgnd.scaled(size(), Qt::IgnoreAspectRatio, Qt::SmoothTransformation);
	QPalette p = palette();
	p.setBrush(QPalette::Background, bkgnd);
	setPalette(p);

	QDialog::resizeEvent(evt);
}

void PositionDialog::acceptSlot()
{
	if (checkInputs())
		accept();
}

void PositionDialog::setData(const QString& name)
{
	addOrSave_btn->setText("Сохранить");
	name_lineEdit->setText(name);
}

void PositionDialog::setWindowSize()
{
	QSettings settings("Goose", "SuppliersBase");
	settings.beginGroup("PositionDialog");
	const int height = settings.value("winHeight", this->height()).toInt();
	const int width = settings.value("winWidth", this->width()).toInt();
	settings.endGroup();
	this->resize(width, height);
}

bool PositionDialog::checkInputs()
{
	if (name_lineEdit->text().isEmpty())
	{
		QMessageBox::warning(this, "Внимание", "Введите название позиции");
		return false;
	}

	return true;
}
