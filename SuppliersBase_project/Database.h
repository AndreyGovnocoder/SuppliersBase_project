#pragma once

#include <QtSql>
#include <QSqlDatabase>
#include <QFile>
#include <vector>
#include <qstring.h>
#include <qmessagebox.h>
#include "Supplier.h"
#include "Position.h"
#include "Contact.h"

class Database
{
public:
    Database() = default;
    ~Database() = default;

    static const QString TABLE_CONTACTS;
    static const QString TABLE_POSITIONS;
    static const QString TABLE_SUPPLIERS;

    static QSqlDatabase getDatabase();
    static bool checkConnect();
    static bool initDatabase(const QString & DB_NAME);
    static int getLastId(const QString & table);
    static int getObjectCount(const QString& table);
    static std::vector<Supplier> getSuppliersList();
    static bool addSupplier(const Supplier & newSupplier);
    static bool editSupplier(const Supplier* supplier);
    static bool editSupplierStatus(const int supplierId, bool status);
    static std::vector<Position> getPositionList();
    static bool addPosition(const Position& newPosition);
    static bool editPosition(const Position* position);
    static std::vector<Contact> getContactsList();
    static bool addContact(const Contact& newContact);
    static bool editContact(const Contact& contact);
    static bool editContact(const Contact* contact);
    static bool removeObject(int id, const QString & table);
    static bool removeContactsBySupplier(int supplierId);
};

