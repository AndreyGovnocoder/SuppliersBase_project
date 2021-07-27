#pragma once

#include <QDialog>
#include "ui_PositionDialog.h"
#include "MainInterface.h"

class PositionDialog : public QDialog, public Ui::PositionDialog
{
	Q_OBJECT

public:
	PositionDialog(QWidget *parent = Q_NULLPTR);
	~PositionDialog() = default;

	void setData(const QString& name);

private:
	void setBackground();
	void resizeEvent(QResizeEvent* evt);
	void setWindowSize();
	bool checkInputs();

private slots:
	void acceptSlot();
};
