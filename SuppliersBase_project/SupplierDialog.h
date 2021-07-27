#pragma once

#include <QDialog>
#include "ui_SupplierDialog.h"
#include "Supplier.h"
#include "Position.h"
#include "Contact.h"
#include "MainInterface.h"
#include "ContactDialog.h"
#include "PositionDialog.h"

class SupplierDialog : public QDialog, public Ui::SupplierDialog
{
	Q_OBJECT

public:
	SupplierDialog(QWidget *parent = Q_NULLPTR);
	~SupplierDialog() = default;
	void setData(const Supplier* supplier);
	std::vector<Contact> get_contactsList() { return _contactsList; };
	std::vector<int> get_positionsList() { return _positionsList; };

private:
	QMenu* _contactsContextMenu = new QMenu(this);
	QAction* _addContactAction = new QAction("Добавить", this);
	QAction* _editContactAction = new QAction("Редактировать", this);
	QAction* _removeContactAction = new QAction("Удалить", this);

	std::vector<Contact> _contactsList;
	std::vector<int> _positionsList;

	void setBackground();
	void resizeEvent(QResizeEvent* evt);
	void setWindowSize();
	bool checkInputs();
	bool checkToAddPositionToTable(const int positionId);
	void setPositionsTable(const std::vector<int> positionsList);
	void addItemToPositionsTable(const Position* position, const int row);
	void setContactsTable(int supplierId);
	void setContactsTable(std::vector<Contact> contactList);
	void addItemToContactsTable(const Contact& contact, const int row);
	void addItemToContactsTable(const Contact* contact, const int row);
	void setContextMenues();
	void setTables();
	void setPositionsCBox();
	void setPositionsCBox(const int positionId);
	Contact* findContact(int ContactId);

private slots:
	void acceptSlot();
	void contactsMenuRequestedSlot(QPoint pos);
	void addPositionToTableSlot();
	void removePositionFromTableSlot();
	void addContactSlot();
	void editContactSlot();
	void removeContactSlot();
	void openPositionsFormSlot();
	void addNewPositionSlot();
};
