#pragma once

#include <QDialog>
#include "ui_ContactDialog.h"
#include "MainInterface.h"

class ContactDialog : public QDialog, public Ui::ContactDialog
{
	Q_OBJECT

public:
	ContactDialog(QWidget *parent = Q_NULLPTR);
	~ContactDialog() = default;

	void setData(Contact* contact);

private:
	void setBackground();
	void resizeEvent(QResizeEvent* evt);
	void setWindowSize();
	bool checkInputs();
	
private slots:
	void acceptSlot();
};
