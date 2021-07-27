#include "MainInterface.h"
#include <QtWidgets/QApplication>
#include <qfile.h>
#include <QtWidgets/qmessagebox.h>
#include <QFileDialog>
#include <Qdebug>

QString getPathToDB()
{
    QMessageBox::warning(0, "Внимание", "Отсутствует доспут к базе данных. Пожалуйста, укажите путь к базе данных.");
    QString path = QFileDialog::getOpenFileName(0,
        "Указать базу данных",
        QDir::currentPath(),
        "Database(*.db)");
    return path;
}

int main(int argc, char *argv[])
{
    QApplication app(argc, argv);

    QCoreApplication::setOrganizationName("Goose");
    QCoreApplication::setOrganizationDomain("Elizgerd@yandex.ru");
    QCoreApplication::setApplicationName("SuppliersBase");
    QSettings settings("Goose", "SuppliersBase");
    QString pathToDB = settings.value("pathToDB").toString();
    
    if (!QFile(pathToDB).exists())
    {
        pathToDB = getPathToDB();

        if (pathToDB.isEmpty())
            return 0;

        settings.setValue("pathToDB", pathToDB);
    }
    Database::initDatabase(pathToDB);

    MainInterface mainInterface;
    mainInterface.show();
    return app.exec();
}
