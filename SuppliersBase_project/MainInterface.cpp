#include "MainInterface.h"

std::vector<Supplier> MainInterface::_suppliersList;
std::vector<Position> MainInterface::_positionsList;
std::vector<Contact> MainInterface::_contactsList;

MainInterface::MainInterface(QWidget *parent)
    : QMainWindow(parent)
{
    ui.setupUi(this);
    ui.menuBar->addAction(_openPositionsFormAction);
    ui.menuBar->addAction(_openAboutFormAction);
    connect(_openPositionsFormAction, &QAction::triggered, this, &MainInterface::openPositionsFormSlot);
    connect(ui.isShowing_action, &QAction::triggered, this, &MainInterface::setSuppliersTableSlot);
    connect(ui.showPathToDB_action, &QAction::triggered, this, &MainInterface::showPathToDBSlot);
    connect(ui.setPathToDB_action, &QAction::triggered, this, &MainInterface::setPathToDBSlot);
    connect(_openAboutFormAction, &QAction::triggered, this, &MainInterface::openAboutFormSlot);
    _suppliersList.reserve(Database::getObjectCount(Database::TABLE_SUPPLIERS));
    _positionsList.reserve(Database::getObjectCount(Database::TABLE_POSITIONS));
    _contactsList.reserve(Database::getObjectCount(Database::TABLE_CONTACTS));
    setWindowSize();
    loadData();
    setTables();
    setDataFromDB();
    setSuppliersTable(_suppliersList);
    setContextMenues();    
    setBackground();
}

void MainInterface::setBackground()
{
    QPixmap bkgnd(":/MainInterface/fon.png");
    bkgnd.scaled(this->size(), Qt::IgnoreAspectRatio, Qt::SmoothTransformation);
    QPalette palette;
    palette.setBrush(QPalette::Background, bkgnd);
    this->setPalette(palette);
}

void MainInterface::resizeEvent(QResizeEvent* evt)
{
    QPixmap bkgnd(":/MainInterface/fon.png");
    bkgnd = bkgnd.scaled(size(), Qt::IgnoreAspectRatio, Qt::SmoothTransformation);
    QPalette p = palette();
    p.setBrush(QPalette::Background, bkgnd);
    setPalette(p);

    QMainWindow::resizeEvent(evt); //call base implementation
}

void MainInterface::setDataFromDB()
{
    _suppliersList.clear();
    _positionsList.clear();
    _contactsList.clear();
    _suppliersList = Database::getSuppliersList();
    _positionsList = Database::getPositionList();
    _contactsList = Database::getContactsList();
}

void MainInterface::setWindowSize()
{
    QSettings settings("Goose", "SuppliersBase");
    settings.beginGroup("MainInterface");
    const int height = settings.value("winHeight", this->height()).toInt();
    const int width = settings.value("winWidth", this->width()).toInt();
    settings.endGroup();
    this->resize(width, height);
}

void MainInterface::setSuppliersTable(const std::vector<Supplier>& suppliersList)
{
    ui.suppliersTable->setSortingEnabled(false);
    ui.suppliersTable->clearContents();
    ui.suppliersTable->setRowCount(0);
    ui.positionsTable->setEnabled(false);
    ui.contactsTable->setEnabled(false);

    for (const Supplier& supplier : suppliersList)
    {
        if (!supplier.is_status() && !ui.isShowing_action->isChecked())
            continue;
        addItemToSuppliersTable(supplier, ui.suppliersTable->rowCount());
    }

    ui.suppliersTable->scrollToBottom();
    ui.suppliersTable->hideColumn(0);
    ui.suppliersTable->horizontalHeader()->setSectionResizeMode(1, QHeaderView::Stretch);
    ui.suppliersTable->setSortingEnabled(true);
    ui.suppliersTable->resizeColumnsToContents();
}

void MainInterface::addItemToSuppliersTable(const Supplier& supplier, const int row)
{
    QTableWidgetItem* supplierIdItem = new QTableWidgetItem(QString::number(supplier.get_id()));
    supplierIdItem->setData(Qt::UserRole, supplier.get_id());
    QTableWidgetItem* supplierNameItem = new QTableWidgetItem(supplier.get_name());
    QTableWidgetItem* supplierStatusItem = new QTableWidgetItem();
    supplier.is_status() ? supplierStatusItem->setText("Актуальный") : supplierStatusItem->setText("Неактуальный");

    ui.suppliersTable->insertRow(row);
    ui.suppliersTable->setItem(row, 0, supplierIdItem);
    ui.suppliersTable->setItem(row, 1, supplierNameItem);
    ui.suppliersTable->setItem(row, 2, supplierStatusItem);
}

void MainInterface::addItemToSuppliersTable(const Supplier* supplier, const int row)
{
    QTableWidgetItem* supplierIdItem = new QTableWidgetItem(QString::number(supplier->get_id()));
    supplierIdItem->setData(Qt::UserRole, supplier->get_id());
    QTableWidgetItem* supplierNameItem = new QTableWidgetItem(supplier->get_name());
    QTableWidgetItem* supplierStatusItem = new QTableWidgetItem();
    supplier->is_status() ? supplierStatusItem->setText("Актуальный") : supplierStatusItem->setText("Неактуальный");

    ui.suppliersTable->insertRow(row);
    ui.suppliersTable->setItem(row, 0, supplierIdItem);
    ui.suppliersTable->setItem(row, 1, supplierNameItem);
    ui.suppliersTable->setItem(row, 2, supplierStatusItem);
}

void MainInterface::setPositionsTable(const std::vector<int>& positionsList)
{
    ui.positionsTable->setSortingEnabled(false);
    ui.positionsTable->clearContents();
    ui.positionsTable->setRowCount(0);

    for (const int positionId : positionsList)
    {
        if (Position* position = findPosition(positionId))
        {
            addItemToPositionsTable(position, ui.positionsTable->rowCount());
        }
    }
    ui.positionsTable->scrollToBottom();
    ui.positionsTable->hideColumn(0);
    ui.positionsTable->horizontalHeader()->setSectionResizeMode(1, QHeaderView::Stretch);
    ui.positionsTable->resizeColumnsToContents();
    ui.positionsTable->verticalHeader()->setSectionResizeMode(QHeaderView::ResizeToContents);
    ui.positionsTable->setSortingEnabled(true);

}

void MainInterface::addItemToPositionsTable(const Position* position, const int row)
{
    QTableWidgetItem* positionIdItem = new QTableWidgetItem(QString::number(position->get_id()));
    positionIdItem->setData(Qt::UserRole, position->get_id());
    QTableWidgetItem* positionNameitem = new QTableWidgetItem(position->get_name());

    ui.positionsTable->insertRow(row);
    ui.positionsTable->setItem(row, 0, positionIdItem);
    ui.positionsTable->setItem(row, 1, positionNameitem);
}

void MainInterface::setContactsTable(int supplierId)
{
    ui.contactsTable->setSortingEnabled(false);
    ui.contactsTable->clearContents();
    ui.contactsTable->setRowCount(0);

    for (const Contact& contact : _contactsList)
    {
        if (contact.get_supplierId() != supplierId)
            continue;
        addItemToContactsTable(contact, ui.contactsTable->rowCount());
    }
    ui.contactsTable->scrollToBottom();
    ui.contactsTable->hideColumn(0);
    ui.contactsTable->horizontalHeader()->setSectionResizeMode(1, QHeaderView::Stretch);
    ui.contactsTable->resizeColumnsToContents();
    ui.contactsTable->verticalHeader()->setSectionResizeMode(QHeaderView::ResizeToContents);
    ui.contactsTable->setSortingEnabled(true);
}

void MainInterface::addItemToContactsTable(const Contact& contact, const int row)
{
    QTableWidgetItem* contactIdItem = new QTableWidgetItem(QString::number(contact.get_id()));
    contactIdItem->setData(Qt::UserRole, contact.get_id());
    QTableWidgetItem* contactNameItem = new QTableWidgetItem(contact.get_name());
    QTableWidgetItem* contactPhonesItem = new QTableWidgetItem(contact.get_phones());
    QTableWidgetItem* contactEmailItem = new QTableWidgetItem(contact.get_email());

    ui.contactsTable->insertRow(row);
    ui.contactsTable->setItem(row, 0, contactIdItem);
    ui.contactsTable->setItem(row, 1, contactNameItem);
    ui.contactsTable->setItem(row, 2, contactPhonesItem);
    ui.contactsTable->setItem(row, 3, contactEmailItem);
}

void MainInterface::setTables()
{
    ui.suppliersTable->setSortingEnabled(false);
    ui.suppliersTable->clearContents();
    ui.suppliersTable->setRowCount(0);
    ui.suppliersTable->scrollToBottom();
    ui.suppliersTable->hideColumn(0);
    ui.suppliersTable->resizeColumnsToContents();
    ui.suppliersTable->horizontalHeader()->setSectionResizeMode(1, QHeaderView::Stretch);
    ui.suppliersTable->setSortingEnabled(true);

    ui.positionsTable->setSortingEnabled(false);
    ui.positionsTable->clearContents();
    ui.positionsTable->setRowCount(0);
    ui.positionsTable->scrollToBottom();
    ui.positionsTable->hideColumn(0);
    ui.positionsTable->resizeColumnsToContents();
    ui.positionsTable->horizontalHeader()->setSectionResizeMode(1, QHeaderView::Stretch);
    ui.positionsTable->verticalHeader()->setSectionResizeMode(QHeaderView::ResizeToContents);
    ui.positionsTable->setSortingEnabled(true);
    ui.positionsTable->setEnabled(false);

    ui.contactsTable->setSortingEnabled(false);
    ui.contactsTable->clearContents();
    ui.contactsTable->setRowCount(0);
    ui.contactsTable->scrollToBottom();
    ui.contactsTable->hideColumn(0);
    ui.contactsTable->resizeColumnsToContents();
    ui.contactsTable->horizontalHeader()->setSectionResizeMode(1, QHeaderView::Stretch);
    ui.contactsTable->verticalHeader()->setSectionResizeMode(QHeaderView::ResizeToContents);
    ui.contactsTable->setSortingEnabled(true);
    ui.contactsTable->setEnabled(false);
}

Position* MainInterface::findPosition(int positionId)
{
    auto it = std::find_if(_positionsList.begin(), _positionsList.end(), [&positionId](const Position& position) {return position.get_id() == positionId; });
    return (it == _positionsList.end()) ? nullptr : &(*it);
}

Position* MainInterface::findPositionByName(const QString& name)
{
    auto it = std::find_if(_positionsList.begin(), _positionsList.end(), [&name](const Position& position) {return position.get_name() == name; });
    return (it == _positionsList.end()) ? nullptr : &(*it);
}

Supplier* MainInterface::findSupplier(int supplierId)
{
    auto it = std::find_if(_suppliersList.begin(), _suppliersList.end(), [&supplierId](const Supplier& supplier) {return supplier.get_id() == supplierId; });
    return (it == _suppliersList.end()) ? nullptr : &(*it);
}

Contact* MainInterface::findContact(int contactId)
{
    auto it = std::find_if(_contactsList.begin(), _contactsList.end(), [&contactId](const Contact& contact) {return contact.get_id() == contactId; });
    return (it == _contactsList.end()) ? nullptr : &(*it);
}

bool MainInterface::askForAnyAction(const QString& titleText, const QString& askText)
{
    QMessageBox messageBox(QMessageBox::Question,
        titleText,
        askText,
        QMessageBox::Yes | QMessageBox::No,
        0);
    messageBox.setButtonText(QMessageBox::Yes, "Да");
    messageBox.setButtonText(QMessageBox::No, "Нет");
    if (messageBox.exec() == QMessageBox::No)
        return false;

    return true;
}

void MainInterface::saveWinSizes(const QString& group, const int winHeight, const int winWidth)
{
    QSettings settings("Goose", "SuppliersBase");
    settings.beginGroup(group);
    settings.setValue("winHeight", winHeight);
    settings.setValue("winWidth", winWidth);
    settings.endGroup();
}

void MainInterface::setContextMenues()
{
    _suppliersContextMenu->addAction(_addSupplierAction);
    _suppliersContextMenu->addAction(_editSupplierAction);
    _suppliersContextMenu->addAction(_removeSupplierAction);
    _suppliersContextMenu->addSeparator();
    _setSuppliersStatusMenu->addAction(_setSuppliersStatusAction);
    _suppliersContextMenu->addMenu(_setSuppliersStatusMenu);
    _contactsContextMenu->addAction(_copyEmailAction);
    _contactsContextMenu->addAction(_copyPhoneAction);

    connect(_addSupplierAction, &QAction::triggered, this, &MainInterface::addSupplierSlot);
    connect(_editSupplierAction, &QAction::triggered, this, &MainInterface::editSupplierSlot);
    connect(_removeSupplierAction, &QAction::triggered, this, &MainInterface::removeSupplierSlot);
    connect(_setSuppliersStatusAction, &QAction::triggered, this, &MainInterface::setSuppliersStatusSlot);
    connect(_copyEmailAction, &QAction::triggered, this, &MainInterface::copyEmailSlot);
    connect(_copyPhoneAction, &QAction::triggered, this, &MainInterface::copyPhoneSlot);
    connect(ui.suppliersTable, &QTableWidget::customContextMenuRequested, this, &MainInterface::suppliersMenuRequestedSlot);
    connect(ui.contactsTable, &QTableWidget::customContextMenuRequested, this, &MainInterface::contactsMenuRequestedSlot);
}

void MainInterface::clearSupplierDetails()
{
    ui.remarkTextEdit->clear();
    ui.positionsTable->clearContents();
    ui.positionsTable->setRowCount(0);
    ui.contactsTable->clearContents();
    ui.contactsTable->setRowCount(0);
}

void MainInterface::searchBySupplier()
{
    clearSupplierDetails();
    _foundSupplierList.clear();
    QString searchText = ui.searchLineEdit->text().toLower();
    size_t one = 1;
    for (const Supplier& supplier : _suppliersList)
    {
        if (!supplier.is_status() && !ui.isShowing_action->isChecked())
            continue;

        const QString supplierName = supplier.get_name().toLower();
        for (size_t k = 0; k < searchText.size(); ++k)
        {
            if (k == supplierName.size())
                break;
            if (searchText.at(k) != supplierName.at(k))
                break;
            if (k == searchText.size() - one)
                _foundSupplierList.push_back(supplier);
        }
    }

    for (const Supplier& supplier : _suppliersList)
    {
        if (!supplier.is_status() && !ui.isShowing_action->isChecked())
            continue;
        const int supplierId = supplier.get_id();
        const QString supplierName = supplier.get_name().toLower();
        const QStringList supplierWordsList = supplierName.split(" ");

        for (size_t n = 1; n < supplierWordsList.size(); ++n)
        {
            for (size_t k = 0; k < searchText.size(); ++k)
            {
                if (k == supplierWordsList[n].size())
                    break;
                if (searchText.at(k) != supplierWordsList[n].at(k))
                    break;
                if (k == searchText.size() - one)
                {
                    bool duplicate = false;
                    auto it = std::find_if(
                        _foundSupplierList.begin(),
                        _foundSupplierList.end(),
                        [&supplierId](const Supplier& supplier) {return supplier.get_id() == supplierId; });
                    duplicate = (it == _foundSupplierList.end() ? false : true);

                    if (!duplicate)
                        _foundSupplierList.push_back(supplier);
                }
            }
        }
    }

    setSuppliersTable(_foundSupplierList);
}

void MainInterface::searchByPosition()
{
    clearSupplierDetails();
    _foundSupplierList.clear();
    QString searchText = ui.searchLineEdit->text().toLower();
    size_t one = 1;
    for (const Supplier& supplier : _suppliersList)
    {
        if (!supplier.is_status() && !ui.isShowing_action->isChecked())
            continue;

        for (const int positionId : supplier.get_positions())
        {
            if (const Position* position = findPosition(positionId))
            {
                const QString positionName = position->get_name().toLower();
                for (size_t k = 0; k < searchText.size(); ++k)
                {
                    if (k == positionName.size())
                        break;
                    if (searchText.at(k) != positionName.at(k))
                        break;
                    if (k == searchText.size() - one)
                        _foundSupplierList.push_back(supplier);
                }
            }
        }
    }

    for (const Supplier& supplier : _suppliersList)
    {
        if (!supplier.is_status() && !ui.isShowing_action->isChecked())
            continue;

        for (const int positionId : supplier.get_positions())
        {
            if (const Position* position = findPosition(positionId))
            {
                const int supplierId = supplier.get_id();
                const QString positionName = position->get_name().toLower();
                const QStringList positionWordsList = positionName.split(" ");

                for (size_t n = 1; n < positionWordsList.size(); ++n)
                {
                    for (size_t k = 0; k < searchText.size(); ++k)
                    {
                        if (k == positionWordsList[n].size())
                            break;
                        if (searchText.at(k) != positionWordsList[n].at(k))
                            break;
                        if (k == searchText.size() - one)
                        {
                            bool duplicate = false;
                            auto it = std::find_if(
                                _foundSupplierList.begin(),
                                _foundSupplierList.end(),
                                [&supplierId](const Supplier& supplier) {return supplier.get_id() == supplierId; });
                            duplicate = (it == _foundSupplierList.end() ? false : true);

                            if (!duplicate)
                                _foundSupplierList.push_back(supplier);
                        }
                    }
                }
            }
        }
    }

    setSuppliersTable(_foundSupplierList);
}

void MainInterface::removeContactsBySupplier(const int supplierId)
{
    _contactsList.erase(std::remove_if(
        _contactsList.begin(),
        _contactsList.end(),
        [&supplierId](const Contact& contact) {return supplierId == contact.get_supplierId(); }),
        _contactsList.end());
}

void MainInterface::closeEvent(QCloseEvent* event)
{
    saveWinSizes("MainInterface", height(), width());
    saveData();
    event->accept();
}

void MainInterface::saveData()
{
    QSettings settings("Goose", "SuppliersBase");
    settings.beginGroup("config");
    settings.setValue("searchByPosition", ui.position_rBtn->isChecked());
    settings.setValue("showNoActiveSupp", ui.isShowing_action->isChecked());
    settings.endGroup();
}

void MainInterface::loadData()
{
    QSettings settings("Goose", "SuppliersBase");
    settings.beginGroup("config");
    const int height = settings.value("winHeight", this->height()).toInt();
    bool searchByPosition = settings.value("searchByPosition", true).toBool();
    bool showNoActiveSupp = settings.value("showNoActiveSupp", true).toBool();
    ui.position_rBtn->setChecked(searchByPosition);
    ui.supplier_rBtn->setChecked(!searchByPosition);
    ui.isShowing_action->setChecked(showNoActiveSupp);
}

void MainInterface::editSupplierSlot()
{
    const int currRow = ui.suppliersTable->currentRow();
    if (currRow < 0)
        return;
    const int supplierId = ui.suppliersTable->item(currRow, 0)->data(Qt::UserRole).toInt();
    if (Supplier* supplier = findSupplier(supplierId))
    {
        SupplierDialog supplierDialog;
        supplierDialog.setWindowTitle("Редактирование поставщика");
        supplierDialog.setWindowFlags(Qt::Window);
        supplierDialog.setData(supplier);
        if (!supplierDialog.exec())
        {
            saveWinSizes("SupplierDialog", supplierDialog.height(), supplierDialog.width());
            return;
        }
        if (!Database::removeContactsBySupplier(supplierId))
        {
            QMessageBox::critical(this, "Ошибка", "Сбой доступа к базе данных");
            return;
        }
        removeContactsBySupplier(supplierId);
        supplier->set_name(supplierDialog.name_lineEdit->text());
        supplier->set_remark(supplierDialog.remarkTextEdit->toPlainText());
        supplier->clearPositions();
        for (const int positionId : supplierDialog.get_positionsList())
        {
            supplier->add_position(positionId);
        }
        for (Contact& contact : supplierDialog.get_contactsList())
        {
            contact.set_supplierId(supplierId);
            if (!Database::addContact(contact))
            {
                QMessageBox::critical(this, "Ошибка", "Сбой доступа к базе данных");
                return;
            }
            contact.set_id(Database::getLastId(Database::TABLE_CONTACTS));
            _contactsList.push_back(std::move(contact));
        }
        ui.suppliersTable->removeRow(currRow);
        addItemToSuppliersTable(supplier, currRow);
        ui.suppliersTable->selectRow(currRow);
        selectSupplierSlot();
        saveWinSizes("SupplierDialog", supplierDialog.height(), supplierDialog.width());
    }
}

void MainInterface::removeSupplierSlot()
{
    const int currRow = ui.suppliersTable->currentRow();
    
    if (currRow < 0)
        return;

    const int supplierId = ui.suppliersTable->item(currRow, 0)->data(Qt::UserRole).toInt();

    QMessageBox messageBox(QMessageBox::Question,
        "Удаление заказа",
        "Вы уверены что хотите удалить выбранного поставщика?",
        QMessageBox::Yes | QMessageBox::No,
        this);
    messageBox.setButtonText(QMessageBox::Yes, "Да, хочу");
    messageBox.setButtonText(QMessageBox::No, "Нет, я случайно");
    if (messageBox.exec() == QMessageBox::No)
        return;

    if (!Database::removeObject(supplierId, Database::TABLE_SUPPLIERS))
    {
        QMessageBox::critical(this, "Ошибка", "Не удалось удалить поставщика.\nСбой доступа к базе данных.");
        return;
    }

    Database::removeContactsBySupplier(supplierId);
    removeContactsBySupplier(supplierId);
    auto itSupplier = std::remove_if(
        _suppliersList.begin(),
        _suppliersList.end(),
        [&supplierId](const Supplier& supplier) {return supplierId == supplier.get_id(); });
    _suppliersList.erase(itSupplier, _suppliersList.end());
    clearSupplierDetails();
    ui.contactsTable->setEnabled(false);
    ui.positionsTable->setEnabled(false);
    ui.suppliersTable->removeRow(currRow);
    ui.suppliersTable->clearSelection();
}

void MainInterface::setSuppliersStatusSlot()
{
    const int currRow = ui.suppliersTable->currentRow();
    if (currRow < 0)
        return;

    const int supplierId = ui.suppliersTable->item(currRow, 0)->data(Qt::UserRole).toInt();
    if (Supplier* supplier = findSupplier(supplierId))
    {
        bool newStatus = supplier->is_status() ? false : true;
        supplier->set_status(newStatus);
        if (!Database::editSupplierStatus(supplierId, supplier->is_status()))
        {
            QMessageBox::critical(this, "Ошибка", "Сбой доступа к базе данных");
            return;
        }

        ui.suppliersTable->removeRow(currRow);
        if (!ui.isShowing_action->isChecked() && !supplier->is_status())
        {
            clearSupplierDetails();
            ui.suppliersTable->clearSelection();
            ui.contactsTable->setEnabled(false);
            ui.positionsTable->setEnabled(false);
            return;
        }
        addItemToSuppliersTable(supplier, currRow);
        ui.suppliersTable->selectRow(currRow);
        selectSupplierSlot();
    }
}

void MainInterface::addSupplierSlot()
{
    SupplierDialog suppDialog;
    suppDialog.setWindowTitle("Добавление поставщика");
    suppDialog.setWindowFlags(Qt::Window);
    if (!suppDialog.exec())
    {   
        Database::removeContactsBySupplier(-1);
        saveWinSizes("SupplierDialog", suppDialog.height(), suppDialog.width());
        return;
    }

    Supplier newSupplier;
    newSupplier.set_status(true);
    newSupplier.set_name(suppDialog.name_lineEdit->text());
    if (!suppDialog.remarkTextEdit->toPlainText().isEmpty())
        newSupplier.set_remark(suppDialog.remarkTextEdit->toPlainText());
    for (const int positionId : suppDialog.get_positionsList())
        newSupplier.add_position(positionId);
    if (!Database::addSupplier(newSupplier))
    {
        QMessageBox::critical(this, "Ошибка", "Не удалось добавить поставщика в базу данных");
        return;
    }
    newSupplier.set_id(Database::getLastId(Database::TABLE_SUPPLIERS));
    for (Contact& contact : suppDialog.get_contactsList())
    {
        contact.set_supplierId(newSupplier.get_id());
        if (!Database::editContact(contact))
            continue;
        _contactsList.push_back(std::move(contact));
    }
    _suppliersList.push_back(std::move(newSupplier));
    
    addItemToSuppliersTable(_suppliersList.back(), ui.suppliersTable->rowCount());
    ui.suppliersTable->selectRow(ui.suppliersTable->rowCount() - 1);
    selectSupplierSlot();
    saveWinSizes("SupplierDialog", suppDialog.height(), suppDialog.width());
}

void MainInterface::suppliersMenuRequestedSlot(QPoint pos)
{
    const int currRow = ui.suppliersTable->currentRow();
    _suppliersContextMenu->popup(ui.suppliersTable->viewport()->mapToGlobal(pos));
    if (currRow < 0)
    {
        _editSupplierAction->setEnabled(false);
        _removeSupplierAction->setEnabled(false);
        _setSuppliersStatusMenu->setEnabled(false);
        return;
    }
    else
    {
        _editSupplierAction->setEnabled(true);
        _removeSupplierAction->setEnabled(true);
        _setSuppliersStatusMenu->setEnabled(true);
    }

    const int supplierId = ui.suppliersTable->item(currRow, 0)->data(Qt::UserRole).toInt();
    if (Supplier* supplier = findSupplier(supplierId))
    {
        if (supplier->is_status())
            _setSuppliersStatusAction->setText("Неактуальный");
        else
            _setSuppliersStatusAction->setText("Актуальный");
    }
}

void MainInterface::contactsMenuRequestedSlot(QPoint pos)
{
    const int currRow = ui.contactsTable->currentRow();
    if (currRow < 0)
        return;
    _contactsContextMenu->popup(ui.contactsTable->viewport()->mapToGlobal(pos));
}

void MainInterface::openPositionsFormSlot()
{
    const int currRow = ui.suppliersTable->currentRow();
    PositionsForm positionsForm;
    positionsForm.setWindowTitle("Список всех позиций");
    positionsForm.setWindowFlags(Qt::Window);
    if (positionsForm.exec())
    {
        if (ui.searchLineEdit->text().isEmpty())
            setSuppliersTable(_suppliersList);
        else
            setSuppliersTable(_foundSupplierList);

        ui.suppliersTable->selectRow(currRow);
        selectSupplierSlot();
    }
    saveWinSizes("PositionsForm", positionsForm.height(), positionsForm.width());
}

void MainInterface::openAboutFormSlot()
{
    AboutForm aboutForm;
    aboutForm.setWindowTitle("О программе");
    aboutForm.setWindowFlags(Qt::MSWindowsFixedSizeDialogHint);
    aboutForm.setWindowModality(Qt::WindowModality::ApplicationModal);
    aboutForm.exec();
}

void MainInterface::selectSupplierSlot()
{
    clearSupplierDetails();
    const int currRow = ui.suppliersTable->currentRow();

    if (currRow < 0)
        return;

    ui.contactsTable->setEnabled(true);
    ui.positionsTable->setEnabled(true);

    int supplierId = ui.suppliersTable->item(currRow, 0)->data(Qt::UserRole).toInt();

    if (Supplier* supplier = findSupplier(supplierId))
    {
        ui.positionsTable->setEnabled(true);
        ui.contactsTable->setEnabled(true);
        setPositionsTable(supplier->get_positions());
        setContactsTable(supplierId);
        ui.remarkTextEdit->setPlainText(supplier->get_remark());
    }
}

void MainInterface::setSuppliersTableSlot()
{
    clearSupplierDetails();
    if (ui.searchLineEdit->text().isEmpty())
    {
        setSuppliersTable(_suppliersList);
        return;
    }
    else
    {
        searchSlot();
    }
}

void MainInterface::searchSlot()
{
    clearSupplierDetails();
    if (ui.searchLineEdit->text().isEmpty())
    {
        setSuppliersTable(_suppliersList);
        return;
    }

    if (ui.position_rBtn->isChecked())
        searchByPosition();
    else if (ui.supplier_rBtn->isChecked())
        searchBySupplier();
}

void MainInterface::showPathToDBSlot()
{
    QSettings settings("Goose", "SuppliersBase");
    QString pathToDB = settings.value("pathToDB").toString();
    QMessageBox::information(this, "Путь к базе данных", pathToDB);
}

void MainInterface::setPathToDBSlot()
{
    QString pathToDB = QFileDialog::getOpenFileName(this,
        "Указать базу данных",
        QDir::currentPath(),
        "Database(*.db)");
    if (pathToDB.isEmpty())
        return;
    QSettings settings("Goose", "SuppliersBase");
    settings.setValue("pathToDB", pathToDB);
    Database::initDatabase(pathToDB);
    clearSupplierDetails();
    setTables();
    setDataFromDB();
    setSuppliersTable(_suppliersList);
}

void MainInterface::copyPhoneSlot()
{
    const int currRow = ui.contactsTable->currentRow();
    if (currRow < 0)
        return;
    const int contactId = ui.contactsTable->item(currRow, 0)->data(Qt::UserRole).toInt();
    if (Contact* contact = findContact(contactId))
    {
        QClipboard* clipboard = QGuiApplication::clipboard();
        clipboard->setText(contact->get_phones());
    }
}

void MainInterface::copyEmailSlot()
{
    const int currRow = ui.contactsTable->currentRow();
    if (currRow < 0)
        return;
    const int contactId = ui.contactsTable->item(currRow, 0)->data(Qt::UserRole).toInt();
    if (Contact* contact = findContact(contactId))
    {
        QClipboard* clipboard = QGuiApplication::clipboard();
        clipboard->setText(contact->get_email());
    }
}
