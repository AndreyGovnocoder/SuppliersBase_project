#include "SupplierDialog.h"

SupplierDialog::SupplierDialog(QWidget *parent)
	: QDialog(parent)
{
	setupUi(this);
    setWindowSize();
    setTables();
    setContextMenues();
    setPositionsCBox();
    setBackground();
}

void SupplierDialog::setData(const Supplier* supplier)
{
    addOrSave_btn->setText("Сохранить");
    remarkTextEdit->setPlainText(supplier->get_remark());
    name_lineEdit->setText(supplier->get_name());
    setContactsTable(supplier->get_id());
    setPositionsTable(supplier->get_positions());
}

void SupplierDialog::setBackground()
{
    QPixmap bkgnd(":/MainInterface/fon.png");
    bkgnd = bkgnd.scaled(size(), Qt::IgnoreAspectRatio, Qt::SmoothTransformation);
    QPalette palette;
    palette.setBrush(QPalette::Background, bkgnd);
    this->setPalette(palette);
}

void SupplierDialog::resizeEvent(QResizeEvent* evt)
{
    QPixmap bkgnd(":/MainInterface/fon.png");
    bkgnd = bkgnd.scaled(size(), Qt::IgnoreAspectRatio, Qt::SmoothTransformation);
    QPalette p = palette();
    p.setBrush(QPalette::Background, bkgnd);
    setPalette(p);

    QDialog::resizeEvent(evt);
}

void SupplierDialog::setWindowSize()
{
    QSettings settings("Goose", "SuppliersBase");
    settings.beginGroup("SupplierDialog");
    const int height = settings.value("winHeight", this->height()).toInt();
    const int width = settings.value("winWidth", this->width()).toInt();
    settings.endGroup();
    this->resize(width, height);
}

bool SupplierDialog::checkInputs()
{
    if (name_lineEdit->text().isEmpty())
    {
        QMessageBox::warning(this, "Внимание", "Не введено название");
        return false;
    }
    else if (_positionsList.empty())
    {
        QMessageBox::warning(this, "Внимание", "Не добавлено ни одной позиции");
        return false;
    }
    return true;
}

bool SupplierDialog::checkToAddPositionToTable(const int positionId)
{
    for (const int posId : _positionsList)
    {
        if (posId != positionId)
            continue;

        if (MainInterface::askForAnyAction("Внимание", "Такая позиция уже есть в таблице. Всё равно добавить?"))
            return true;
        else
            return false;
    }
    return true;
}

void SupplierDialog::setPositionsTable(const std::vector<int> positionsList)
{
    positionsTable->setSortingEnabled(false);
    positionsTable->clearContents();
    positionsTable->setRowCount(0);

    for (const int positionId : positionsList)
    {
        if (Position* position = MainInterface::findPosition(positionId))
        {
            addItemToPositionsTable(position, positionsTable->rowCount());
            _positionsList.push_back(positionId);
        }
    }
    positionsTable->scrollToBottom();
    positionsTable->hideColumn(0);
    positionsTable->resizeColumnsToContents();
    positionsTable->horizontalHeader()->setSectionResizeMode(1, QHeaderView::Stretch);
    positionsTable->verticalHeader()->setSectionResizeMode(QHeaderView::ResizeToContents);
    positionsTable->setSortingEnabled(true);
}

void SupplierDialog::addItemToPositionsTable(const Position* position, const int row)
{
    QTableWidgetItem* positionIdItem = new QTableWidgetItem(QString::number(position->get_id()));
    positionIdItem->setData(Qt::UserRole, position->get_id());
    QTableWidgetItem* positionNameitem = new QTableWidgetItem(position->get_name());

    positionsTable->insertRow(row);
    positionsTable->setItem(row, 0, positionIdItem);
    positionsTable->setItem(row, 1, positionNameitem);
}

void SupplierDialog::setContactsTable(int supplierId)
{
    contactsTable->setSortingEnabled(false);
    contactsTable->clearContents();
    contactsTable->setRowCount(0);

    for (const Contact& contact : MainInterface::get_contactsList())
    {
        if (contact.get_supplierId() != supplierId)
            continue;
        _contactsList.push_back(contact);
        addItemToContactsTable(contact, contactsTable->rowCount());
    }
    contactsTable->scrollToBottom();
    contactsTable->hideColumn(0);
    contactsTable->horizontalHeader()->setSectionResizeMode(1, QHeaderView::Stretch);
    contactsTable->resizeColumnsToContents();
    contactsTable->verticalHeader()->setSectionResizeMode(QHeaderView::ResizeToContents);
    contactsTable->setSortingEnabled(true);
}

void SupplierDialog::setContactsTable(std::vector<Contact> contactsList)
{
    contactsTable->setSortingEnabled(false);
    contactsTable->clearContents();
    contactsTable->setRowCount(0);

    for (const Contact& contact : contactsList)
    {
        addItemToContactsTable(contact, contactsTable->rowCount());
    }

    contactsTable->scrollToBottom();
    contactsTable->hideColumn(0);
    contactsTable->horizontalHeader()->setSectionResizeMode(1, QHeaderView::Stretch);
    contactsTable->resizeColumnsToContents();
    contactsTable->verticalHeader()->setSectionResizeMode(QHeaderView::ResizeToContents);
    contactsTable->setSortingEnabled(true);
}

void SupplierDialog::addItemToContactsTable(const Contact& contact, const int row)
{
    QTableWidgetItem* contactIdItem = new QTableWidgetItem(QString::number(contact.get_id()));
    contactIdItem->setData(Qt::UserRole, contact.get_id());
    QTableWidgetItem* contactNameItem = new QTableWidgetItem(contact.get_name());
    QTableWidgetItem* contactPhonesItem = new QTableWidgetItem(contact.get_phones());
    QTableWidgetItem* contactEmailItem = new QTableWidgetItem(contact.get_email());

    contactsTable->insertRow(row);
    contactsTable->setItem(row, 0, contactIdItem);
    contactsTable->setItem(row, 1, contactNameItem);
    contactsTable->setItem(row, 2, contactPhonesItem);
    contactsTable->setItem(row, 3, contactEmailItem);
}

void SupplierDialog::addItemToContactsTable(const Contact* contact, const int row)
{

    QTableWidgetItem* contactIdItem = new QTableWidgetItem(QString::number(contact->get_id()));
    contactIdItem->setData(Qt::UserRole, contact->get_id());
    QTableWidgetItem* contactNameItem = new QTableWidgetItem(contact->get_name());
    QTableWidgetItem* contactPhoneItem = new QTableWidgetItem(contact->get_phones());
    QTableWidgetItem* contactEmailItem = new QTableWidgetItem(contact->get_email());

    contactsTable->insertRow(row);
    contactsTable->setItem(row, 0, contactIdItem);
    contactsTable->setItem(row, 1, contactNameItem);
    contactsTable->setItem(row, 2, contactPhoneItem);
    contactsTable->setItem(row, 3, contactEmailItem);
}

void SupplierDialog::setContextMenues()
{
    _contactsContextMenu->addAction(_addContactAction);
    _contactsContextMenu->addAction(_editContactAction);
    _contactsContextMenu->addAction(_removeContactAction);

    connect(_addContactAction, &QAction::triggered, this, &SupplierDialog::addContactSlot);
    connect(_editContactAction, &QAction::triggered, this, &SupplierDialog::editContactSlot);
    connect(_removeContactAction, &QAction::triggered, this, &SupplierDialog::removeContactSlot);
    connect(contactsTable, &QTableWidget::customContextMenuRequested, this, &SupplierDialog::contactsMenuRequestedSlot);
}

void SupplierDialog::setTables()
{
    positionsTable->setSortingEnabled(false);
    positionsTable->clearContents();
    positionsTable->setRowCount(0);
    positionsTable->scrollToBottom();
    positionsTable->hideColumn(0);
    positionsTable->resizeColumnsToContents();
    positionsTable->horizontalHeader()->setSectionResizeMode(1, QHeaderView::Stretch);
    positionsTable->verticalHeader()->setSectionResizeMode(QHeaderView::ResizeToContents);
    positionsTable->setSortingEnabled(true);

    contactsTable->setSortingEnabled(false);
    contactsTable->clearContents();
    contactsTable->setRowCount(0);
    contactsTable->scrollToBottom();
    contactsTable->hideColumn(0);
    contactsTable->horizontalHeader()->setSectionResizeMode(1, QHeaderView::Stretch);
    contactsTable->verticalHeader()->setSectionResizeMode(QHeaderView::ResizeToContents);
    contactsTable->resizeColumnsToContents();
    contactsTable->setSortingEnabled(true);
}

void SupplierDialog::setPositionsCBox()
{
    positionsCBox->clear();
    positionsCBox->lineEdit()->clear();
    int positionIndex = 0;
    for (const Position& position : MainInterface::get_positionsList())
    {
        if (!position.is_active())
            continue;

        QVariant var;
        var.setValue(position.get_id());
        positionsCBox->addItem(position.get_name());
        positionsCBox->setItemData(positionIndex, var);
        ++positionIndex;
    }

    positionsCBox->setCurrentIndex(-1);
}

void SupplierDialog::setPositionsCBox(const int positionId)
{
    positionsCBox->clear();
    positionsCBox->lineEdit()->clear();
    int positionIndex = 0;
    int currIndex = -1;
    for (const Position& position : MainInterface::get_positionsList())
    {
        if (!position.is_active())
            continue;

        QVariant var;
        var.setValue(position.get_id());
        positionsCBox->addItem(position.get_name());
        positionsCBox->setItemData(positionIndex, var);
        if (position.get_id() == positionId)
            currIndex = positionIndex;
        ++positionIndex;
    }

    positionsCBox->setCurrentIndex(currIndex);
}

Contact* SupplierDialog::findContact(int contactId)
{
    auto it = std::find_if(_contactsList.begin(), _contactsList.end(), [&contactId](const Contact& contact) {return contact.get_id() == contactId; });
    return (it == _contactsList.end()) ? nullptr : &(*it);
}

void SupplierDialog::contactsMenuRequestedSlot(QPoint pos)
{
    const int currRow = contactsTable->selectionModel()->currentIndex().row();
    bool enable = true;
    _contactsContextMenu->popup(contactsTable->viewport()->mapToGlobal(pos));
    if (currRow < 0)
        enable = false;
    _editContactAction->setEnabled(enable);
    _removeContactAction->setEnabled(enable);
}

void SupplierDialog::addPositionToTableSlot()
{
    if (positionsCBox->currentIndex() < 0)
    {
        QMessageBox::warning(this, "Внимание", "Такой позиции нет в списке");
        return;
    }

    int positionId = positionsCBox->currentData().toInt();
    if (!checkToAddPositionToTable(positionId))
        return;
    _positionsList.push_back(std::move(positionId));
    addItemToPositionsTable(MainInterface::findPosition(positionId), positionsTable->rowCount());
    positionsCBox->setCurrentIndex(-1);
    positionsCBox->lineEdit()->clear();
}

void SupplierDialog::removePositionFromTableSlot()
{
    int currRow = positionsTable->currentRow();
    if (currRow < 0)
        return;

    int positionId = positionsTable->item(currRow, 0)->data(Qt::UserRole).toInt();
    positionsTable->removeRow(currRow);
    auto itPositionId = std::remove_if(_positionsList.begin(), _positionsList.end(), [&positionId](const int posId) {return positionId == posId; });
    _positionsList.erase(itPositionId, _positionsList.end());
}

void SupplierDialog::addContactSlot()
{
    ContactDialog contactDialog;
    contactDialog.setWindowTitle("Добавление контакта");
    contactDialog.setWindowFlags(Qt::Window);
    if (!contactDialog.exec())
    {
        MainInterface::saveWinSizes("ContactDialog", contactDialog.height(), contactDialog.width());
        return;
    }
    MainInterface::saveWinSizes("ContactDialog", contactDialog.height(), contactDialog.width());
    Contact contact;
    contact.set_name(contactDialog.name_lineEdit->text());
    contact.set_phones(contactDialog.phone_lineEdit->text());
    contact.set_email(contactDialog.email_lineEdit->text());
    contact.set_supplierId(-1);
    if (!Database::addContact(contact))
    {
        QMessageBox::critical(this, "Ошибка", "Сбой доступа к базе данных");
        return;
    }
    contact.set_id(Database::getLastId(Database::TABLE_CONTACTS));
    _contactsList.push_back(std::move(contact));
    setContactsTable(_contactsList);
}

void SupplierDialog::editContactSlot()
{
    const int currRow = contactsTable->currentRow();
    if (currRow < 0)
        return;
    const int contactId = contactsTable->item(currRow, 0)->data(Qt::UserRole).toInt();
    if (Contact* contact = findContact(contactId))
    {
        ContactDialog contactDialog;
        contactDialog.setWindowTitle("Редактирование контакта");
        contactDialog.setWindowFlags(Qt::Window);
        contactDialog.setData(contact);
        if (!contactDialog.exec())
            return;
        contact->set_name(contactDialog.name_lineEdit->text());
        contact->set_phones(contactDialog.phone_lineEdit->text());
        contact->set_email(contactDialog.email_lineEdit->text());
        if (contact->get_supplierId() == -1)
        {
            if (!Database::editContact(contact))
            {
                QMessageBox::critical(this, "Ошибка", "Сбой доступа к базе данных");
                return;
            }
        }

        contactsTable->removeRow(currRow);
        addItemToContactsTable(contact, currRow);
        contactsTable->selectRow(currRow);
    }
}

void SupplierDialog::removeContactSlot()
{
    const int currRow = contactsTable->currentRow();

    if (currRow < 0)
        return;

    const int contactId = contactsTable->item(currRow, 0)->data(Qt::UserRole).toInt();
    if (Contact* contact = findContact(contactId))
    {
        if (contact->get_supplierId() == -1)
            Database::removeObject(contactId, Database::TABLE_CONTACTS);
    }
    auto itContact = std::remove_if(
        _contactsList.begin(),
        _contactsList.end(),
        [&contactId](const Contact& contact) {return contactId == contact.get_id(); });
    _contactsList.erase(itContact, _contactsList.end());
    contactsTable->removeRow(currRow);
    contactsTable->clearSelection();
}

void SupplierDialog::openPositionsFormSlot()
{
    PositionsForm positionsForm;
    positionsForm.setWindowTitle("Список всех позиций");
    positionsForm.setWindowFlags(Qt::Window);
    if (positionsForm.exec())
        setPositionsCBox();
    MainInterface::saveWinSizes("positionsForm", positionsForm.height(), positionsForm.width());
}

void SupplierDialog::addNewPositionSlot()
{
    PositionDialog positionDialog;
    positionDialog.setWindowTitle("Добавление новой позиции");
    positionDialog.setWindowFlags(Qt::Window);
    if (positionDialog.exec())
    {
        Position position(positionDialog.name_lineEdit->text(), true);
        int selectPosition = -1;
        if (Position* oldPosition = MainInterface::findPositionByName(position.get_name()))
        {
            oldPosition->set_active(true);
            if (!Database::editPosition(oldPosition))
            {
                QMessageBox::critical(this, "Ошибка", "Не удалось добавить позицию в базу данных");
                return;
            }
            selectPosition = oldPosition->get_id();
        }
        else
        {
            if (!Database::addPosition(position))
            {
                QMessageBox::critical(this, "Ошибка", "Не удалось добавить позицию в базу данных");
                return;
            }
            position.set_id(Database::getLastId(Database::TABLE_POSITIONS));
            MainInterface::get_positionsList().push_back(std::move(position));
            selectPosition = position.get_id();
        }

        setPositionsCBox(selectPosition);
        addPosition_btn->setFocus();
    }
    MainInterface::saveWinSizes("PositionDialog", positionDialog.height(), positionDialog.width());
}

void SupplierDialog::acceptSlot()
{
	if (checkInputs())
		accept();
}
