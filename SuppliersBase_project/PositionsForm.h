#pragma once

#include <QDialog>
#include "ui_PositionsForm.h"
#include "MainInterface.h"
#include <QCloseEvent>

class PositionsForm : public QDialog, public Ui::PositionsForm
{
	Q_OBJECT

public:
	PositionsForm(QWidget *parent = Q_NULLPTR);
	~PositionsForm() = default;

private:
	QMenu* _positionsContextMenu = new QMenu(this);
	QAction* _addPositionAction = new QAction("Добавить", this);
	QAction* _editPositionAction = new QAction("Редактировать", this);
	QAction* _removePositionAction = new QAction("Удалить", this);
	bool _isChanged = false;
	std::vector<Position> _foundPositions;

	void setBackground();
	void resizeEvent(QResizeEvent* evt);
	void setWindowSize();
	void setPositionsTable();
	void setPositionsTable(const std::vector<Position>& positionsList);
	void addItemToPositionsTable(const Position& position, const int row);
	void addItemToPositionsTable(const Position* position, const int row);
	void closeEvent(QCloseEvent* event);
	void setContextMenu();
	bool checkPositionInSuppliers(const int removablePositionId);

private slots:
	void positionsMenuRequestedSlot(QPoint pos);
	void addPositionSlot();
	void editPositionSlot();
	void removePositionSlot();
	void searchPositionsSlot();
};
