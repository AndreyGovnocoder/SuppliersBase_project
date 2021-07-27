#include "PositionsForm.h"

PositionsForm::PositionsForm(QWidget *parent)
	: QDialog(parent)
{
	setupUi(this);
    setWindowSize();
    setContextMenu();
    setPositionsTable();
}

void PositionsForm::setBackground()
{
    QPixmap bkgnd(":/MainInterface/fon.png");
    bkgnd = bkgnd.scaled(size(), Qt::IgnoreAspectRatio, Qt::SmoothTransformation);
    QPalette palette;
    palette.setBrush(QPalette::Background, bkgnd);
    this->setPalette(palette);
}

void PositionsForm::resizeEvent(QResizeEvent* evt)
{
    QPixmap bkgnd(":/MainInterface/fon.png");
    bkgnd = bkgnd.scaled(size(), Qt::IgnoreAspectRatio, Qt::SmoothTransformation);
    QPalette p = palette();
    p.setBrush(QPalette::Background, bkgnd);
    setPalette(p);

    QDialog::resizeEvent(evt);
}

void PositionsForm::setWindowSize()
{
    QSettings settings("Goose", "SuppliersBase");
    settings.beginGroup("PositionsForm");
    const int height = settings.value("winHeight", this->height()).toInt();
    const int width = settings.value("winWidth", this->width()).toInt();
    settings.endGroup();
    this->resize(width, height);
}

void PositionsForm::setPositionsTable()
{
    positionsTable->setSortingEnabled(false);
    positionsTable->clearContents();
    positionsTable->setRowCount(0);

    for (const Position& position : MainInterface::get_positionsList())
    {
        if (position.is_active())
            addItemToPositionsTable(position, positionsTable->rowCount());
    }
    positionsTable->scrollToBottom();
    positionsTable->resizeColumnsToContents();
    positionsTable->hideColumn(0);
    positionsTable->horizontalHeader()->setSectionResizeMode(1, QHeaderView::Stretch);
    positionsTable->setSortingEnabled(true);
}

void PositionsForm::setPositionsTable(const std::vector<Position>& positionsList)
{
    positionsTable->setSortingEnabled(false);
    positionsTable->clearContents();
    positionsTable->setRowCount(0);

    for (const Position& position : positionsList)
    {
        if (position.is_active())
            addItemToPositionsTable(position, positionsTable->rowCount());
    }
    positionsTable->scrollToBottom();
    positionsTable->resizeColumnsToContents();
    positionsTable->hideColumn(0);
    positionsTable->horizontalHeader()->setSectionResizeMode(1, QHeaderView::Stretch);
    positionsTable->setSortingEnabled(true);
}

void PositionsForm::addItemToPositionsTable(const Position& position, const int row)
{
    QTableWidgetItem* positionIdItem = new QTableWidgetItem(QString::number(position.get_id()));
    positionIdItem->setData(Qt::UserRole, position.get_id());
    QTableWidgetItem* positionNameitem = new QTableWidgetItem(position.get_name());

    positionsTable->insertRow(row);
    positionsTable->setItem(row, 0, positionIdItem);
    positionsTable->setItem(row, 1, positionNameitem);
}

void PositionsForm::addItemToPositionsTable(const Position* position, const int row)
{
    QTableWidgetItem* positionIdItem = new QTableWidgetItem(QString::number(position->get_id()));
    positionIdItem->setData(Qt::UserRole, position->get_id());
    QTableWidgetItem* positionNameitem = new QTableWidgetItem(position->get_name());

    positionsTable->insertRow(row);
    positionsTable->setItem(row, 0, positionIdItem);
    positionsTable->setItem(row, 1, positionNameitem);
}

void PositionsForm::closeEvent(QCloseEvent* event)
{
    if (_isChanged)
    {
        accept();
    }
    else
    {
        reject();
    }
}

void PositionsForm::setContextMenu()
{
    _positionsContextMenu->addAction(_addPositionAction);
    _positionsContextMenu->addAction(_editPositionAction);
    _positionsContextMenu->addAction(_removePositionAction);

    connect(_addPositionAction, &QAction::triggered, this, &PositionsForm::addPositionSlot);
    connect(_editPositionAction, &QAction::triggered, this, &PositionsForm::editPositionSlot);
    connect(_removePositionAction, &QAction::triggered, this, &PositionsForm::removePositionSlot);
    connect(positionsTable, &QTableWidget::customContextMenuRequested, this, &PositionsForm::positionsMenuRequestedSlot);
}

bool PositionsForm::checkPositionInSuppliers(const int removablePositionId)
{
    for (const Supplier& supplier : MainInterface::get_suppliersList())
    {
        for (const int positionId : supplier.get_positions())
        {
            if (positionId == removablePositionId)
                return true;
        }
    }
    return false;
}

void PositionsForm::addPositionSlot()
{
    PositionDialog positionDialog;
    positionDialog.setWindowTitle("Добавление позиции");
    positionDialog.setWindowFlags(Qt::Window);
    if (!positionDialog.exec())
    {
        MainInterface::saveWinSizes("PositionDialog", positionDialog.height(), positionDialog.width());
        return;
    }
    MainInterface::saveWinSizes("PositionDialog", positionDialog.height(), positionDialog.width());
    Position position(positionDialog.name_lineEdit->text(), true);
    if (Position* oldPosition = MainInterface::findPositionByName(position.get_name()))
    {
        oldPosition->set_active(true);
        if (!Database::editPosition(oldPosition))
        {
            QMessageBox::critical(this, "Ошибка", "Не удалось добавить позицию в базу данных");
            return;
        }
        addItemToPositionsTable(oldPosition, positionsTable->rowCount());
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
        addItemToPositionsTable(position, positionsTable->rowCount());
    }
    
    _isChanged = true;
    positionsTable->selectRow(positionsTable->rowCount() - 1);
}

void PositionsForm::editPositionSlot()
{
    const int currRow = positionsTable->currentRow();
    if (currRow < 0)
        return;
    const int positionId = positionsTable->item(currRow, 0)->data(Qt::UserRole).toInt();
    if (Position* position = MainInterface::findPosition(positionId))
    {
        PositionDialog positionDialog;
        positionDialog.setWindowTitle("Редактирование позиции");
        positionDialog.setWindowFlags(Qt::Window);
        positionDialog.setData(position->get_name());
        if (!positionDialog.exec())
        {
            MainInterface::saveWinSizes("PositionDialog", positionDialog.height(), positionDialog.width());
            return;
        }
        MainInterface::saveWinSizes("PositionDialog", positionDialog.height(), positionDialog.width());
        position->set_name(positionDialog.name_lineEdit->text());
        if (!Database::editPosition(position))
        {
            QMessageBox::critical(this, "Ошибка", "Сбой доступа к базе данных");
            return;
        }
        _isChanged = true;
        positionsTable->removeRow(currRow);
        addItemToPositionsTable(position, currRow);
        positionsTable->selectRow(currRow);
    }
}

void PositionsForm::removePositionSlot()
{
    const int currRow = positionsTable->currentRow();
    if (currRow < 0)
        return;
    const int positionId = positionsTable->item(currRow, 0)->data(Qt::UserRole).toInt();
    if (Position* position = MainInterface::findPosition(positionId))
    {
        QMessageBox messageBox(QMessageBox::Question,
            "Удаление позиции",
            "Вы уверены что хотите удалить выбранную позицию?",
            QMessageBox::Yes | QMessageBox::No,
            this);
        messageBox.setButtonText(QMessageBox::Yes, "Да, хочу");
        messageBox.setButtonText(QMessageBox::No, "Нет, я случайно");
        if (messageBox.exec() == QMessageBox::No)
            return;

        if (checkPositionInSuppliers(positionId))
        {
            position->set_active(false);
            if (!Database::editPosition(position))
            {
                QMessageBox::critical(this, "Ошибка", "Не удалось удалить позицию.\nСбой доступа к базе данных.");
                return;
            }
        }
        else
        {
            if (!Database::removeObject(positionId, Database::TABLE_POSITIONS))
            {
                QMessageBox::critical(this, "Ошибка", "Не удалось удалить позицию.\nСбой доступа к базе данных.");
                return;
            }
            auto itSupplier = std::remove_if(
                MainInterface::get_positionsList().begin(),
                MainInterface::get_positionsList().end(),
                [&positionId](const Position& position) {return positionId == position.get_id(); });
            MainInterface::get_positionsList().erase(itSupplier, MainInterface::get_positionsList().end());
        }
        _isChanged = true;
        positionsTable->removeRow(currRow);
        positionsTable->clearSelection();
    }
}

void PositionsForm::searchPositionsSlot()
{
    _foundPositions.clear();
    QString searchText = search_lineEdit->text();
    if (searchText.isEmpty())
    {
        setPositionsTable();
        return;
    }
    const int one = 1;
    for (const Position& position : MainInterface::get_positionsList())
    {
        const QString name = position.get_name().toLower();
        for (size_t k = 0; k < searchText.size(); ++k)
        {
            if (k == name.size())
                break;
            if (searchText.at(k) != name.at(k))
                break;
            if (k == searchText.size() - one)
                _foundPositions.push_back(position);
        }
    }

    for (const Position& position : MainInterface::get_positionsList())
    {
        const int positionId = position.get_id();
        const QString name = position.get_name().toLower();
        const QStringList nameWordsList = name.split(" ");
        for (size_t n = 1; n < nameWordsList.size(); ++n)
        {
            for (size_t k = 0; k < searchText.size(); ++k)
            {
                if (k == nameWordsList[n].size())
                    break;
                if (searchText.at(k) != nameWordsList[n].at(k))
                    break;
                if (k == searchText.size() - one)
                {
                    bool duplicate = false;
                    auto it = std::find_if(
                        _foundPositions.begin(),
                        _foundPositions.end(),
                        [&positionId](const Position& position) {return positionId == position.get_id(); });
                    duplicate = (it == _foundPositions.end()) ? false : true;

                    if (!duplicate)
                        _foundPositions.push_back(position);
                }
            }
        }
    }

    setPositionsTable(_foundPositions);
}

void PositionsForm::positionsMenuRequestedSlot(QPoint pos)
{
    _positionsContextMenu->popup(positionsTable->viewport()->mapToGlobal(pos));
}
