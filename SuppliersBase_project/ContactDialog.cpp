#include "ContactDialog.h"

ContactDialog::ContactDialog(QWidget *parent)
	: QDialog(parent)
{
	setupUi(this);
	setWindowSize();
	save_btn->setVisible(false);
}

void ContactDialog::setBackground()
{
	QPixmap bkgnd(":/MainInterface/fon.png");
	bkgnd = bkgnd.scaled(size(), Qt::IgnoreAspectRatio, Qt::SmoothTransformation);
	QPalette palette;
	palette.setBrush(QPalette::Background, bkgnd);
	this->setPalette(palette);
}

void ContactDialog::resizeEvent(QResizeEvent* evt)
{
	QPixmap bkgnd(":/MainInterface/fon.png");
	bkgnd = bkgnd.scaled(size(), Qt::IgnoreAspectRatio, Qt::SmoothTransformation);
	QPalette p = palette();
	p.setBrush(QPalette::Background, bkgnd);
	setPalette(p);

	QDialog::resizeEvent(evt);
}

void ContactDialog::setData(Contact* contact)
{
	save_btn->setVisible(true);
	add_btn->setVisible(false);
	name_lineEdit->setText(contact->get_name());
	phone_lineEdit->setText(contact->get_phones());
	email_lineEdit->setText(contact->get_email());
}

void ContactDialog::setWindowSize()
{
	QSettings settings("Goose", "SuppliersBase");
	settings.beginGroup("PhoneDialog");
	const int height = settings.value("winHeight", this->height()).toInt();
	const int width = settings.value("winWidth", this->width()).toInt();
	settings.endGroup();
	this->resize(width, height);
}

bool ContactDialog::checkInputs()
{
	if (name_lineEdit->text().isEmpty())
	{
		QMessageBox::warning(this, "Внимание", "Введите имя");
		return false;
	}
	else if (phone_lineEdit->text().isEmpty() && email_lineEdit->text().isEmpty())
	{
		QMessageBox::warning(this, "Внимание", "Введите либо телефон(ы), либо e-mail");
		return false;
	}
	
	return true;
}

void ContactDialog::acceptSlot()
{
	if (checkInputs())
		accept();
}
