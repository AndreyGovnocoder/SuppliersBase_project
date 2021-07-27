#pragma once

#include <QtWidgets/QMainWindow>
#include "ui_MainInterface.h"
#include <QTableWidgetItem>
#include <QClipboard>
#include <QFileDialog>
#include <QCloseEvent>
#include "Supplier.h"
#include "Position.h"
#include "Database.h"
#include "Contact.h"
#include "SupplierDialog.h"
#include "PositionsForm.h"
#include "AboutForm.h"

class MainInterface : public QMainWindow
{
    Q_OBJECT

public:
    MainInterface(QWidget *parent = Q_NULLPTR);

    static Position* findPosition(int positionId);
    static Position* findPositionByName(const QString& name);
    static Supplier* findSupplier(int supplierId);
    static Contact* findContact(int contactId);
    static std::vector<Supplier>& get_suppliersList() { return _suppliersList; };
    static std::vector<Position>& get_positionsList() { return _positionsList; };
    static std::vector<Contact>& get_contactsList() { return _contactsList; };
    static bool askForAnyAction(const QString& titleText, const QString& askText);
    static void saveWinSizes(const QString& group, const int winHeight, const int winWidth);

private:
    Ui::MainInterfaceClass ui;

    static std::vector<Supplier> _suppliersList;
    static std::vector<Position> _positionsList;
    static std::vector<Contact> _contactsList;
    std::vector<Supplier> _foundSupplierList;

    QMenu* _suppliersContextMenu = new QMenu(this);
    QMenu* _contactsContextMenu = new QMenu(this);
    QAction* _addSupplierAction = new QAction("Добавить", this);
    QAction* _editSupplierAction = new QAction("Редактировать", this);
    QAction* _removeSupplierAction = new QAction("Удалить", this);
    QMenu* _setSuppliersStatusMenu = new QMenu("Статус", this);
    QAction* _setSuppliersStatusAction = new QAction("Актуальный", this);
    QAction* _openPositionsFormAction = new QAction("Список позиций", this);
    QAction* _openAboutFormAction = new QAction("О программе", this);
    QAction* _copyPhoneAction = new QAction("Скопировать телефон", this);
    QAction* _copyEmailAction = new QAction("Скопировать e-mail", this);

    void setBackground();
    void resizeEvent(QResizeEvent* evt);
    void setDataFromDB();
    void setWindowSize();
    void setSuppliersTable(const std::vector<Supplier>& suppliersList);
    void addItemToSuppliersTable(const Supplier& supplier, const int row);
    void addItemToSuppliersTable(const Supplier* supplier, const int row);
    void setPositionsTable(const std::vector<int>& positionsList);
    void addItemToPositionsTable(const Position* position, const int row);
    void setContactsTable(int supplierId);
    void addItemToContactsTable(const Contact& contact, const int row);
    void setTables();
    void setContextMenues();
    void clearSupplierDetails();
    void searchBySupplier();
    void searchByPosition();
    void removeContactsBySupplier(const int supplierId);
    void closeEvent(QCloseEvent* event);
    void saveData();
    void loadData();

private slots:
    void addSupplierSlot();
    void editSupplierSlot();
    void removeSupplierSlot();
    void setSuppliersStatusSlot();
    void suppliersMenuRequestedSlot(QPoint pos);
    void contactsMenuRequestedSlot(QPoint pos);
    void openPositionsFormSlot();
    void openAboutFormSlot();
    void selectSupplierSlot();
    void setSuppliersTableSlot();
    void searchSlot();
    void showPathToDBSlot();
    void setPathToDBSlot();
    void copyPhoneSlot();
    void copyEmailSlot();
};
