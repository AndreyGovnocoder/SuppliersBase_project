#include "Database.h"

const QString Database::TABLE_CONTACTS("contacts");
const QString Database::TABLE_POSITIONS("positions");
const QString Database::TABLE_SUPPLIERS("suppliers");

QSqlDatabase Database::getDatabase()
{
    QSettings settings("Goose", "SuppliersBase");
    return QSqlDatabase::database(settings.value("pathToDB").toString());
}

bool Database::checkConnect()
{
    QSqlQuery query(getDatabase());
    query.exec("SELECT _id FROM " + TABLE_SUPPLIERS);

    return query.exec();
}

bool Database::initDatabase(const QString& DB_NAME)
{
    auto db = QSqlDatabase::addDatabase("QSQLITE");
    db.setDatabaseName(DB_NAME);
    const bool ok = db.open();
    if (!ok)
    {
        QString error = db.lastError().text();
        QMessageBox::critical(0, "Ошибка", "Ошибка подключения к базе данных: " + error);
    }
    return ok;
}

int Database::getLastId(const QString& table)
{
    int lastId = -1;

    QSqlQuery query(getDatabase());
    query.exec("SELECT _id FROM " + table + " ORDER BY _id DESC LIMIT 1");

    if (query.first())
        lastId = query.value(0).toInt();

    return query.exec() ? lastId : -1;
}

int Database::getObjectCount(const QString& table)
{
    int rowCount = -1;

    QSqlQuery query(getDatabase());
    query.exec("SELECT _id FROM " + table);

    query.last();
    rowCount = query.at();
    if (rowCount > 0)
        ++rowCount;
    else
        rowCount = 0;

    return query.exec() ? rowCount : -1;
}

std::vector<Supplier> Database::getSuppliersList()
{
    //получаем список клиентов из БД
    int rowCount = 0;
    QSqlQuery query(getDatabase());

    query.exec("SELECT * FROM " + TABLE_SUPPLIERS);
    query.last();
    rowCount = query.at();
    std::vector<Supplier> suppliersList;
    if (rowCount > 0)
        suppliersList.reserve(++rowCount);

    query.first();
    query.previous();

    while (query.next())
    {
        Supplier supplier(
            query.value(0).toInt(),
            query.value(1).toString(),
            query.value(2).toBool(),
            query.value(3).toString());

        const QStringList positionsList = query.value(4).toString().split("^");
        for (const auto& positionId : positionsList)
        {
            supplier.add_position(positionId.toInt());
        }
        suppliersList.push_back(std::move(supplier));
    }

    return suppliersList;
}

bool Database::addSupplier(const Supplier& newSupplier)
{
    QString positionsList;
    for (const int positionId : newSupplier.get_positions())
    {
        positionsList.append(QString::number(positionId)).append("^");
    }

    QSqlQuery query(getDatabase());
    query.prepare("INSERT INTO " + TABLE_SUPPLIERS + " (name, status, remark, positions)"
        "VALUES (:name, :status, :remark, :positions);");
    query.bindValue(":name", newSupplier.get_name());
    query.bindValue(":status", newSupplier.is_status());
    query.bindValue(":remark", newSupplier.get_remark());
    query.bindValue(":positions", positionsList);

    return query.exec();
}

bool Database::editSupplier(const Supplier* supplier)
{
    QString positionsList;
    for (const int positionId : supplier->get_positions())
    {
        positionsList.append(QString::number(positionId)).append("^");
    }
    QSqlQuery query(getDatabase());
    query.prepare("UPDATE " + TABLE_SUPPLIERS +
        " SET name = ?, status = ?, remark = ?,  positions = ? " +
        " WHERE _id=" + QString::number(supplier->get_id()));
    query.addBindValue(supplier->get_name());
    query.addBindValue(supplier->is_status());
    query.addBindValue(supplier->get_remark());
    query.addBindValue(positionsList);

    return query.exec();
}

bool Database::editSupplierStatus(const int supplierId, bool status)
{
    QSqlQuery query(getDatabase());
    query.prepare("UPDATE " + TABLE_SUPPLIERS +
        " SET status = ? " +
        " WHERE _id=" + QString::number(supplierId));
    query.addBindValue(status);

    return query.exec();
}

std::vector<Position> Database::getPositionList()
{
    int rowCount = 0;
    QSqlQuery query(getDatabase());

    query.exec("SELECT * FROM " + TABLE_POSITIONS);
    query.last();
    rowCount = query.at();
    std::vector<Position> positionList;
    if (rowCount > 0)
        positionList.reserve(++rowCount);

    query.first();
    query.previous();

    while (query.next())
    {
        Position position(
            query.value(0).toInt(),
            query.value(1).toString(),
            query.value(2).toBool());
        positionList.push_back(std::move(position));
    }

    return positionList;
}

bool Database::addPosition(const Position& newPosition)
{
    QSqlQuery query(getDatabase());
    query.prepare("INSERT INTO " + TABLE_POSITIONS + " (name, active)"
        "VALUES (:name, :active);");
    query.bindValue(":name", newPosition.get_name());
    query.bindValue(":active", newPosition.is_active());

    return query.exec();
}

bool Database::editPosition(const Position* position)
{
    QSqlQuery query(getDatabase());
    query.prepare("UPDATE " + TABLE_POSITIONS +
        " SET name = ?, active = ? " +
        " WHERE _id=" + QString::number(position->get_id()));
    query.addBindValue(position->get_name());
    query.addBindValue(position->is_active());

    return query.exec();
}

std::vector<Contact> Database::getContactsList()
{
    int rowCount = 0;
    QSqlQuery query(getDatabase());

    query.exec("SELECT * FROM " + TABLE_CONTACTS);
    query.last();
    rowCount = query.at();
    std::vector<Contact> contactsList;
    if (rowCount > 0)
        contactsList.reserve(++rowCount);

    query.first();
    query.previous();

    while (query.next())
    {
        Contact contact(
            query.value(0).toInt(),
            query.value(1).toInt(),
            query.value(2).toString(),
            query.value(3).toString(),
            query.value(4).toString());
        contactsList.push_back(std::move(contact));
    }

    return contactsList;
}

bool Database::addContact(const Contact& newContact)
{
    QSqlQuery query(getDatabase());
    query.prepare("INSERT INTO " + TABLE_CONTACTS + " (supplierId, name, phones, email)"
        "VALUES (:supplierId, :name, :phones, :email);");
    query.bindValue(":supplierId", newContact.get_supplierId());
    query.bindValue(":name", newContact.get_name());
    query.bindValue(":phones", newContact.get_phones());
    query.bindValue(":email", newContact.get_email());

    return query.exec();
}

bool Database::editContact(const Contact& contact)
{
    QSqlQuery query(getDatabase());
    query.prepare("UPDATE " + TABLE_CONTACTS +
        " SET supplierId = ?, name = ?, phones = ?, email = ? " +
        " WHERE _id=" + QString::number(contact.get_id()));
    query.addBindValue(contact.get_supplierId());
    query.addBindValue(contact.get_name());
    query.addBindValue(contact.get_phones());
    query.addBindValue(contact.get_email());

    return query.exec();
}

bool Database::editContact(const Contact* contact)
{
    QSqlQuery query(getDatabase());
    query.prepare("UPDATE " + TABLE_CONTACTS +
        " SET supplierId = ?, name = ?, phones = ?, email = ? " +
        " WHERE _id=" + QString::number(contact->get_id()));
    query.addBindValue(contact->get_supplierId());
    query.addBindValue(contact->get_name());
    query.addBindValue(contact->get_phones());
    query.addBindValue(contact->get_email());

    return query.exec();
}

bool Database::removeObject(int id, const QString& table)
{
    QSqlQuery query(getDatabase());

    return query.exec("DELETE FROM " + table + " WHERE _id=" + QString::number(id));
}

bool Database::removeContactsBySupplier(int supplierId)
{
    QSqlQuery query(getDatabase());

    return query.exec("DELETE FROM " + TABLE_CONTACTS + " WHERE supplierId=" + QString::number(supplierId));
}
