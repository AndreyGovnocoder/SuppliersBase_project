/********************************************************************************
** Form generated from reading UI file 'MainInterface.ui'
**
** Created by: Qt User Interface Compiler version 5.15.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAININTERFACE_H
#define UI_MAININTERFACE_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenu>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QRadioButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QTableWidget>
#include <QtWidgets/QTextEdit>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainInterfaceClass
{
public:
    QAction *isShowing_action;
    QAction *setPathToDB_action;
    QAction *showPathToDB_action;
    QWidget *centralWidget;
    QVBoxLayout *verticalLayout_2;
    QGroupBox *searchGBox;
    QHBoxLayout *horizontalLayout_3;
    QLineEdit *searchLineEdit;
    QRadioButton *position_rBtn;
    QRadioButton *supplier_rBtn;
    QSpacerItem *horizontalSpacer;
    QTableWidget *suppliersTable;
    QHBoxLayout *horizontalLayout_2;
    QTableWidget *positionsTable;
    QVBoxLayout *verticalLayout;
    QTableWidget *contactsTable;
    QGroupBox *remarkGBox;
    QHBoxLayout *horizontalLayout_5;
    QTextEdit *remarkTextEdit;
    QHBoxLayout *horizontalLayout_4;
    QSpacerItem *horizontalSpacer_2;
    QPushButton *close_btn;
    QSpacerItem *horizontalSpacer_3;
    QMenuBar *menuBar;
    QMenu *Options_menu;
    QMenu *showActiveSupp_action;
    QMenu *database_menu;

    void setupUi(QMainWindow *MainInterfaceClass)
    {
        if (MainInterfaceClass->objectName().isEmpty())
            MainInterfaceClass->setObjectName(QString::fromUtf8("MainInterfaceClass"));
        MainInterfaceClass->resize(947, 777);
        isShowing_action = new QAction(MainInterfaceClass);
        isShowing_action->setObjectName(QString::fromUtf8("isShowing_action"));
        isShowing_action->setCheckable(true);
        isShowing_action->setChecked(true);
        setPathToDB_action = new QAction(MainInterfaceClass);
        setPathToDB_action->setObjectName(QString::fromUtf8("setPathToDB_action"));
        showPathToDB_action = new QAction(MainInterfaceClass);
        showPathToDB_action->setObjectName(QString::fromUtf8("showPathToDB_action"));
        centralWidget = new QWidget(MainInterfaceClass);
        centralWidget->setObjectName(QString::fromUtf8("centralWidget"));
        verticalLayout_2 = new QVBoxLayout(centralWidget);
        verticalLayout_2->setSpacing(6);
        verticalLayout_2->setContentsMargins(11, 11, 11, 11);
        verticalLayout_2->setObjectName(QString::fromUtf8("verticalLayout_2"));
        searchGBox = new QGroupBox(centralWidget);
        searchGBox->setObjectName(QString::fromUtf8("searchGBox"));
        QFont font;
        font.setPointSize(10);
        searchGBox->setFont(font);
        searchGBox->setFlat(false);
        horizontalLayout_3 = new QHBoxLayout(searchGBox);
        horizontalLayout_3->setSpacing(12);
        horizontalLayout_3->setContentsMargins(11, 11, 11, 11);
        horizontalLayout_3->setObjectName(QString::fromUtf8("horizontalLayout_3"));
        searchLineEdit = new QLineEdit(searchGBox);
        searchLineEdit->setObjectName(QString::fromUtf8("searchLineEdit"));
        searchLineEdit->setFont(font);

        horizontalLayout_3->addWidget(searchLineEdit);

        position_rBtn = new QRadioButton(searchGBox);
        position_rBtn->setObjectName(QString::fromUtf8("position_rBtn"));
        position_rBtn->setFont(font);
        position_rBtn->setChecked(true);

        horizontalLayout_3->addWidget(position_rBtn);

        supplier_rBtn = new QRadioButton(searchGBox);
        supplier_rBtn->setObjectName(QString::fromUtf8("supplier_rBtn"));
        supplier_rBtn->setFont(font);

        horizontalLayout_3->addWidget(supplier_rBtn);

        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_3->addItem(horizontalSpacer);


        verticalLayout_2->addWidget(searchGBox);

        suppliersTable = new QTableWidget(centralWidget);
        if (suppliersTable->columnCount() < 3)
            suppliersTable->setColumnCount(3);
        QTableWidgetItem *__qtablewidgetitem = new QTableWidgetItem();
        suppliersTable->setHorizontalHeaderItem(0, __qtablewidgetitem);
        QTableWidgetItem *__qtablewidgetitem1 = new QTableWidgetItem();
        suppliersTable->setHorizontalHeaderItem(1, __qtablewidgetitem1);
        QTableWidgetItem *__qtablewidgetitem2 = new QTableWidgetItem();
        suppliersTable->setHorizontalHeaderItem(2, __qtablewidgetitem2);
        suppliersTable->setObjectName(QString::fromUtf8("suppliersTable"));
        suppliersTable->setContextMenuPolicy(Qt::CustomContextMenu);
        suppliersTable->setFrameShape(QFrame::StyledPanel);
        suppliersTable->setFrameShadow(QFrame::Sunken);
        suppliersTable->setEditTriggers(QAbstractItemView::SelectedClicked);
        suppliersTable->setDragDropMode(QAbstractItemView::NoDragDrop);
        suppliersTable->setAlternatingRowColors(true);
        suppliersTable->setSelectionMode(QAbstractItemView::SingleSelection);
        suppliersTable->setSelectionBehavior(QAbstractItemView::SelectRows);
        suppliersTable->setVerticalScrollMode(QAbstractItemView::ScrollPerPixel);
        suppliersTable->setHorizontalScrollMode(QAbstractItemView::ScrollPerPixel);
        suppliersTable->setSortingEnabled(true);
        suppliersTable->horizontalHeader()->setStretchLastSection(false);

        verticalLayout_2->addWidget(suppliersTable);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setSpacing(12);
        horizontalLayout_2->setObjectName(QString::fromUtf8("horizontalLayout_2"));
        positionsTable = new QTableWidget(centralWidget);
        if (positionsTable->columnCount() < 2)
            positionsTable->setColumnCount(2);
        QTableWidgetItem *__qtablewidgetitem3 = new QTableWidgetItem();
        positionsTable->setHorizontalHeaderItem(0, __qtablewidgetitem3);
        QTableWidgetItem *__qtablewidgetitem4 = new QTableWidgetItem();
        positionsTable->setHorizontalHeaderItem(1, __qtablewidgetitem4);
        positionsTable->setObjectName(QString::fromUtf8("positionsTable"));
        QSizePolicy sizePolicy(QSizePolicy::Preferred, QSizePolicy::Expanding);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(positionsTable->sizePolicy().hasHeightForWidth());
        positionsTable->setSizePolicy(sizePolicy);
        positionsTable->setFrameShape(QFrame::StyledPanel);
        positionsTable->setFrameShadow(QFrame::Sunken);
        positionsTable->setEditTriggers(QAbstractItemView::NoEditTriggers);
        positionsTable->setAlternatingRowColors(true);
        positionsTable->setSelectionMode(QAbstractItemView::SingleSelection);
        positionsTable->setSelectionBehavior(QAbstractItemView::SelectRows);
        positionsTable->setVerticalScrollMode(QAbstractItemView::ScrollPerPixel);
        positionsTable->setHorizontalScrollMode(QAbstractItemView::ScrollPerPixel);
        positionsTable->horizontalHeader()->setStretchLastSection(true);

        horizontalLayout_2->addWidget(positionsTable);

        verticalLayout = new QVBoxLayout();
        verticalLayout->setSpacing(6);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        contactsTable = new QTableWidget(centralWidget);
        if (contactsTable->columnCount() < 4)
            contactsTable->setColumnCount(4);
        QTableWidgetItem *__qtablewidgetitem5 = new QTableWidgetItem();
        contactsTable->setHorizontalHeaderItem(0, __qtablewidgetitem5);
        QTableWidgetItem *__qtablewidgetitem6 = new QTableWidgetItem();
        contactsTable->setHorizontalHeaderItem(1, __qtablewidgetitem6);
        QTableWidgetItem *__qtablewidgetitem7 = new QTableWidgetItem();
        contactsTable->setHorizontalHeaderItem(2, __qtablewidgetitem7);
        QTableWidgetItem *__qtablewidgetitem8 = new QTableWidgetItem();
        contactsTable->setHorizontalHeaderItem(3, __qtablewidgetitem8);
        contactsTable->setObjectName(QString::fromUtf8("contactsTable"));
        contactsTable->setContextMenuPolicy(Qt::CustomContextMenu);
        contactsTable->setFrameShape(QFrame::StyledPanel);
        contactsTable->setFrameShadow(QFrame::Sunken);
        contactsTable->setEditTriggers(QAbstractItemView::NoEditTriggers);
        contactsTable->setAlternatingRowColors(true);
        contactsTable->setSelectionMode(QAbstractItemView::SingleSelection);
        contactsTable->setSelectionBehavior(QAbstractItemView::SelectRows);
        contactsTable->setTextElideMode(Qt::ElideMiddle);
        contactsTable->setVerticalScrollMode(QAbstractItemView::ScrollPerPixel);
        contactsTable->setHorizontalScrollMode(QAbstractItemView::ScrollPerPixel);
        contactsTable->setSortingEnabled(true);
        contactsTable->horizontalHeader()->setStretchLastSection(true);

        verticalLayout->addWidget(contactsTable);


        horizontalLayout_2->addLayout(verticalLayout);


        verticalLayout_2->addLayout(horizontalLayout_2);

        remarkGBox = new QGroupBox(centralWidget);
        remarkGBox->setObjectName(QString::fromUtf8("remarkGBox"));
        remarkGBox->setMaximumSize(QSize(16777215, 120));
        remarkGBox->setFont(font);
        remarkGBox->setFlat(false);
        horizontalLayout_5 = new QHBoxLayout(remarkGBox);
        horizontalLayout_5->setSpacing(6);
        horizontalLayout_5->setContentsMargins(11, 11, 11, 11);
        horizontalLayout_5->setObjectName(QString::fromUtf8("horizontalLayout_5"));
        remarkTextEdit = new QTextEdit(remarkGBox);
        remarkTextEdit->setObjectName(QString::fromUtf8("remarkTextEdit"));
        QSizePolicy sizePolicy1(QSizePolicy::Expanding, QSizePolicy::Preferred);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(remarkTextEdit->sizePolicy().hasHeightForWidth());
        remarkTextEdit->setSizePolicy(sizePolicy1);
        remarkTextEdit->setMaximumSize(QSize(16777215, 80));
        remarkTextEdit->setFont(font);
        remarkTextEdit->setReadOnly(true);

        horizontalLayout_5->addWidget(remarkTextEdit);


        verticalLayout_2->addWidget(remarkGBox);

        horizontalLayout_4 = new QHBoxLayout();
        horizontalLayout_4->setSpacing(6);
        horizontalLayout_4->setObjectName(QString::fromUtf8("horizontalLayout_4"));
        horizontalSpacer_2 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_4->addItem(horizontalSpacer_2);

        close_btn = new QPushButton(centralWidget);
        close_btn->setObjectName(QString::fromUtf8("close_btn"));

        horizontalLayout_4->addWidget(close_btn);

        horizontalSpacer_3 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_4->addItem(horizontalSpacer_3);


        verticalLayout_2->addLayout(horizontalLayout_4);

        MainInterfaceClass->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(MainInterfaceClass);
        menuBar->setObjectName(QString::fromUtf8("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 947, 21));
        Options_menu = new QMenu(menuBar);
        Options_menu->setObjectName(QString::fromUtf8("Options_menu"));
        showActiveSupp_action = new QMenu(Options_menu);
        showActiveSupp_action->setObjectName(QString::fromUtf8("showActiveSupp_action"));
        database_menu = new QMenu(Options_menu);
        database_menu->setObjectName(QString::fromUtf8("database_menu"));
        MainInterfaceClass->setMenuBar(menuBar);

        menuBar->addAction(Options_menu->menuAction());
        Options_menu->addAction(database_menu->menuAction());
        Options_menu->addAction(showActiveSupp_action->menuAction());
        showActiveSupp_action->addAction(isShowing_action);
        database_menu->addAction(setPathToDB_action);
        database_menu->addAction(showPathToDB_action);

        retranslateUi(MainInterfaceClass);
        QObject::connect(suppliersTable, SIGNAL(itemPressed(QTableWidgetItem*)), MainInterfaceClass, SLOT(selectSupplierSlot()));
        QObject::connect(position_rBtn, SIGNAL(released()), MainInterfaceClass, SLOT(searchSlot()));
        QObject::connect(supplier_rBtn, SIGNAL(released()), MainInterfaceClass, SLOT(searchSlot()));
        QObject::connect(searchLineEdit, SIGNAL(textEdited(QString)), MainInterfaceClass, SLOT(searchSlot()));
        QObject::connect(close_btn, SIGNAL(clicked()), MainInterfaceClass, SLOT(close()));

        QMetaObject::connectSlotsByName(MainInterfaceClass);
    } // setupUi

    void retranslateUi(QMainWindow *MainInterfaceClass)
    {
        MainInterfaceClass->setWindowTitle(QCoreApplication::translate("MainInterfaceClass", "\320\232\320\276\320\275\321\202\320\260\320\272\321\202\321\213 \320\236\321\202\320\264\320\265\320\273\320\260 \320\227\320\260\320\272\321\203\320\277\320\276\320\272", nullptr));
        isShowing_action->setText(QCoreApplication::translate("MainInterfaceClass", "\320\237\320\276\320\272\320\260\320\267\321\213\320\262\320\260\321\202\321\214 \320\275\320\265\320\260\320\272\321\202\320\270\320\262\320\275\321\213\321\205 \320\277\320\276\321\201\321\202\320\260\320\262\321\211\320\270\320\272\320\276\320\262", nullptr));
        setPathToDB_action->setText(QCoreApplication::translate("MainInterfaceClass", "\320\243\320\272\320\260\320\267\320\260\321\202\321\214 \320\261\320\260\320\267\321\203 \320\264\320\260\320\275\320\275\321\213\321\205", nullptr));
        showPathToDB_action->setText(QCoreApplication::translate("MainInterfaceClass", "\320\242\320\265\320\272\321\203\321\211\320\270\320\271 \320\277\321\203\321\202\321\214 \320\272 \320\261\320\260\320\267\320\265 \320\264\320\260\320\275\320\275\321\213\321\205", nullptr));
        searchGBox->setTitle(QCoreApplication::translate("MainInterfaceClass", "\320\237\320\276\320\270\321\201\320\272", nullptr));
        position_rBtn->setText(QCoreApplication::translate("MainInterfaceClass", "\320\237\320\276\320\267\320\270\321\206\320\270\321\217", nullptr));
        supplier_rBtn->setText(QCoreApplication::translate("MainInterfaceClass", "\320\237\320\276\321\201\321\202\320\260\320\262\321\211\320\270\320\272", nullptr));
        QTableWidgetItem *___qtablewidgetitem = suppliersTable->horizontalHeaderItem(0);
        ___qtablewidgetitem->setText(QCoreApplication::translate("MainInterfaceClass", "_id", nullptr));
        QTableWidgetItem *___qtablewidgetitem1 = suppliersTable->horizontalHeaderItem(1);
        ___qtablewidgetitem1->setText(QCoreApplication::translate("MainInterfaceClass", "\320\237\320\276\321\201\321\202\320\260\320\262\321\211\320\270\320\272", nullptr));
        QTableWidgetItem *___qtablewidgetitem2 = suppliersTable->horizontalHeaderItem(2);
        ___qtablewidgetitem2->setText(QCoreApplication::translate("MainInterfaceClass", "\320\241\321\202\320\260\321\202\321\203\321\201", nullptr));
        QTableWidgetItem *___qtablewidgetitem3 = positionsTable->horizontalHeaderItem(0);
        ___qtablewidgetitem3->setText(QCoreApplication::translate("MainInterfaceClass", "_id", nullptr));
        QTableWidgetItem *___qtablewidgetitem4 = positionsTable->horizontalHeaderItem(1);
        ___qtablewidgetitem4->setText(QCoreApplication::translate("MainInterfaceClass", "\320\237\320\276\320\267\320\270\321\206\320\270\321\217", nullptr));
        QTableWidgetItem *___qtablewidgetitem5 = contactsTable->horizontalHeaderItem(0);
        ___qtablewidgetitem5->setText(QCoreApplication::translate("MainInterfaceClass", "_id", nullptr));
        QTableWidgetItem *___qtablewidgetitem6 = contactsTable->horizontalHeaderItem(1);
        ___qtablewidgetitem6->setText(QCoreApplication::translate("MainInterfaceClass", "\320\230\320\274\321\217", nullptr));
        QTableWidgetItem *___qtablewidgetitem7 = contactsTable->horizontalHeaderItem(2);
        ___qtablewidgetitem7->setText(QCoreApplication::translate("MainInterfaceClass", "\320\242\320\265\320\273\320\265\321\204\320\276\320\275", nullptr));
        QTableWidgetItem *___qtablewidgetitem8 = contactsTable->horizontalHeaderItem(3);
        ___qtablewidgetitem8->setText(QCoreApplication::translate("MainInterfaceClass", "E-mail", nullptr));
        remarkGBox->setTitle(QCoreApplication::translate("MainInterfaceClass", "\320\237\321\200\320\270\320\274\320\265\321\207\320\260\320\275\320\270\320\265", nullptr));
        close_btn->setText(QCoreApplication::translate("MainInterfaceClass", "\320\227\320\260\320\272\321\200\321\213\321\202\321\214", nullptr));
        Options_menu->setTitle(QCoreApplication::translate("MainInterfaceClass", "\320\235\320\260\321\201\321\202\321\200\320\276\320\271\320\272\320\270", nullptr));
        showActiveSupp_action->setTitle(QCoreApplication::translate("MainInterfaceClass", "\320\241\320\276\321\200\321\202\320\270\321\200\320\276\320\262\320\272\320\260", nullptr));
        database_menu->setTitle(QCoreApplication::translate("MainInterfaceClass", "\320\221\320\260\320\267\320\260 \320\264\320\260\320\275\320\275\321\213\321\205", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainInterfaceClass: public Ui_MainInterfaceClass {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAININTERFACE_H
