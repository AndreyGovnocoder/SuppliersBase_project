/********************************************************************************
** Form generated from reading UI file 'SupplierDialog.ui'
**
** Created by: Qt User Interface Compiler version 5.15.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_SUPPLIERDIALOG_H
#define UI_SUPPLIERDIALOG_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QDialog>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QTableWidget>
#include <QtWidgets/QTextEdit>
#include <QtWidgets/QVBoxLayout>

QT_BEGIN_NAMESPACE

class Ui_SupplierDialog
{
public:
    QVBoxLayout *verticalLayout_3;
    QHBoxLayout *horizontalLayout_6;
    QSpacerItem *horizontalSpacer_3;
    QGroupBox *nameGBox;
    QHBoxLayout *horizontalLayout_3;
    QLineEdit *name_lineEdit;
    QSpacerItem *horizontalSpacer_4;
    QGroupBox *suppDetails_GBox;
    QGridLayout *gridLayout;
    QVBoxLayout *verticalLayout;
    QHBoxLayout *horizontalLayout_4;
    QSpacerItem *horizontalSpacer_10;
    QPushButton *addNewPosition_btn;
    QPushButton *openPositionsForm_btn;
    QSpacerItem *horizontalSpacer_11;
    QHBoxLayout *horizontalLayout_7;
    QSpacerItem *horizontalSpacer_12;
    QComboBox *positionsCBox;
    QSpacerItem *horizontalSpacer_13;
    QHBoxLayout *horizontalLayout_5;
    QSpacerItem *horizontalSpacer;
    QPushButton *addPosition_btn;
    QPushButton *removePosition_btn;
    QSpacerItem *horizontalSpacer_2;
    QHBoxLayout *horizontalLayout_2;
    QSpacerItem *horizontalSpacer_8;
    QTableWidget *positionsTable;
    QSpacerItem *horizontalSpacer_9;
    QTableWidget *contactsTable;
    QGroupBox *remarkGBox;
    QVBoxLayout *verticalLayout_2;
    QTextEdit *remarkTextEdit;
    QHBoxLayout *horizontalLayout;
    QSpacerItem *horizontalSpacer_6;
    QPushButton *addOrSave_btn;
    QSpacerItem *horizontalSpacer_5;
    QPushButton *cancel_btn;
    QSpacerItem *horizontalSpacer_7;

    void setupUi(QDialog *SupplierDialog)
    {
        if (SupplierDialog->objectName().isEmpty())
            SupplierDialog->setObjectName(QString::fromUtf8("SupplierDialog"));
        SupplierDialog->resize(939, 660);
        verticalLayout_3 = new QVBoxLayout(SupplierDialog);
        verticalLayout_3->setSpacing(6);
        verticalLayout_3->setContentsMargins(11, 11, 11, 11);
        verticalLayout_3->setObjectName(QString::fromUtf8("verticalLayout_3"));
        horizontalLayout_6 = new QHBoxLayout();
        horizontalLayout_6->setSpacing(6);
        horizontalLayout_6->setObjectName(QString::fromUtf8("horizontalLayout_6"));
        horizontalSpacer_3 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_6->addItem(horizontalSpacer_3);

        nameGBox = new QGroupBox(SupplierDialog);
        nameGBox->setObjectName(QString::fromUtf8("nameGBox"));
        QFont font;
        font.setPointSize(10);
        nameGBox->setFont(font);
        horizontalLayout_3 = new QHBoxLayout(nameGBox);
        horizontalLayout_3->setSpacing(6);
        horizontalLayout_3->setContentsMargins(11, 11, 11, 11);
        horizontalLayout_3->setObjectName(QString::fromUtf8("horizontalLayout_3"));
        name_lineEdit = new QLineEdit(nameGBox);
        name_lineEdit->setObjectName(QString::fromUtf8("name_lineEdit"));
        name_lineEdit->setMinimumSize(QSize(350, 0));
        name_lineEdit->setFont(font);

        horizontalLayout_3->addWidget(name_lineEdit);


        horizontalLayout_6->addWidget(nameGBox);

        horizontalSpacer_4 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_6->addItem(horizontalSpacer_4);


        verticalLayout_3->addLayout(horizontalLayout_6);

        suppDetails_GBox = new QGroupBox(SupplierDialog);
        suppDetails_GBox->setObjectName(QString::fromUtf8("suppDetails_GBox"));
        gridLayout = new QGridLayout(suppDetails_GBox);
        gridLayout->setSpacing(6);
        gridLayout->setContentsMargins(11, 11, 11, 11);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        gridLayout->setHorizontalSpacing(10);
        verticalLayout = new QVBoxLayout();
        verticalLayout->setSpacing(10);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        verticalLayout->setSizeConstraint(QLayout::SetFixedSize);
        horizontalLayout_4 = new QHBoxLayout();
        horizontalLayout_4->setSpacing(6);
        horizontalLayout_4->setObjectName(QString::fromUtf8("horizontalLayout_4"));
        horizontalLayout_4->setSizeConstraint(QLayout::SetFixedSize);
        horizontalSpacer_10 = new QSpacerItem(40, 20, QSizePolicy::Preferred, QSizePolicy::Minimum);

        horizontalLayout_4->addItem(horizontalSpacer_10);

        addNewPosition_btn = new QPushButton(suppDetails_GBox);
        addNewPosition_btn->setObjectName(QString::fromUtf8("addNewPosition_btn"));
        QSizePolicy sizePolicy(QSizePolicy::Minimum, QSizePolicy::Fixed);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(addNewPosition_btn->sizePolicy().hasHeightForWidth());
        addNewPosition_btn->setSizePolicy(sizePolicy);

        horizontalLayout_4->addWidget(addNewPosition_btn);

        openPositionsForm_btn = new QPushButton(suppDetails_GBox);
        openPositionsForm_btn->setObjectName(QString::fromUtf8("openPositionsForm_btn"));
        sizePolicy.setHeightForWidth(openPositionsForm_btn->sizePolicy().hasHeightForWidth());
        openPositionsForm_btn->setSizePolicy(sizePolicy);

        horizontalLayout_4->addWidget(openPositionsForm_btn);

        horizontalSpacer_11 = new QSpacerItem(40, 20, QSizePolicy::Preferred, QSizePolicy::Minimum);

        horizontalLayout_4->addItem(horizontalSpacer_11);


        verticalLayout->addLayout(horizontalLayout_4);

        horizontalLayout_7 = new QHBoxLayout();
        horizontalLayout_7->setSpacing(6);
        horizontalLayout_7->setObjectName(QString::fromUtf8("horizontalLayout_7"));
        horizontalSpacer_12 = new QSpacerItem(40, 20, QSizePolicy::Preferred, QSizePolicy::Minimum);

        horizontalLayout_7->addItem(horizontalSpacer_12);

        positionsCBox = new QComboBox(suppDetails_GBox);
        positionsCBox->setObjectName(QString::fromUtf8("positionsCBox"));
        QSizePolicy sizePolicy1(QSizePolicy::Preferred, QSizePolicy::Fixed);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(positionsCBox->sizePolicy().hasHeightForWidth());
        positionsCBox->setSizePolicy(sizePolicy1);
        positionsCBox->setFont(font);
        positionsCBox->setEditable(true);

        horizontalLayout_7->addWidget(positionsCBox);

        horizontalSpacer_13 = new QSpacerItem(40, 20, QSizePolicy::Preferred, QSizePolicy::Minimum);

        horizontalLayout_7->addItem(horizontalSpacer_13);


        verticalLayout->addLayout(horizontalLayout_7);

        horizontalLayout_5 = new QHBoxLayout();
        horizontalLayout_5->setSpacing(10);
        horizontalLayout_5->setObjectName(QString::fromUtf8("horizontalLayout_5"));
        horizontalLayout_5->setSizeConstraint(QLayout::SetFixedSize);
        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Preferred, QSizePolicy::Minimum);

        horizontalLayout_5->addItem(horizontalSpacer);

        addPosition_btn = new QPushButton(suppDetails_GBox);
        addPosition_btn->setObjectName(QString::fromUtf8("addPosition_btn"));
        sizePolicy.setHeightForWidth(addPosition_btn->sizePolicy().hasHeightForWidth());
        addPosition_btn->setSizePolicy(sizePolicy);

        horizontalLayout_5->addWidget(addPosition_btn);

        removePosition_btn = new QPushButton(suppDetails_GBox);
        removePosition_btn->setObjectName(QString::fromUtf8("removePosition_btn"));
        sizePolicy.setHeightForWidth(removePosition_btn->sizePolicy().hasHeightForWidth());
        removePosition_btn->setSizePolicy(sizePolicy);

        horizontalLayout_5->addWidget(removePosition_btn);

        horizontalSpacer_2 = new QSpacerItem(40, 20, QSizePolicy::Fixed, QSizePolicy::Minimum);

        horizontalLayout_5->addItem(horizontalSpacer_2);


        verticalLayout->addLayout(horizontalLayout_5);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setSpacing(6);
        horizontalLayout_2->setObjectName(QString::fromUtf8("horizontalLayout_2"));
        horizontalSpacer_8 = new QSpacerItem(40, 20, QSizePolicy::Preferred, QSizePolicy::Minimum);

        horizontalLayout_2->addItem(horizontalSpacer_8);

        positionsTable = new QTableWidget(suppDetails_GBox);
        if (positionsTable->columnCount() < 2)
            positionsTable->setColumnCount(2);
        QTableWidgetItem *__qtablewidgetitem = new QTableWidgetItem();
        positionsTable->setHorizontalHeaderItem(0, __qtablewidgetitem);
        QTableWidgetItem *__qtablewidgetitem1 = new QTableWidgetItem();
        positionsTable->setHorizontalHeaderItem(1, __qtablewidgetitem1);
        positionsTable->setObjectName(QString::fromUtf8("positionsTable"));
        QSizePolicy sizePolicy2(QSizePolicy::Preferred, QSizePolicy::Expanding);
        sizePolicy2.setHorizontalStretch(0);
        sizePolicy2.setVerticalStretch(0);
        sizePolicy2.setHeightForWidth(positionsTable->sizePolicy().hasHeightForWidth());
        positionsTable->setSizePolicy(sizePolicy2);
        positionsTable->setMinimumSize(QSize(350, 0));
        positionsTable->setEditTriggers(QAbstractItemView::NoEditTriggers);
        positionsTable->setAlternatingRowColors(true);
        positionsTable->setSelectionMode(QAbstractItemView::SingleSelection);
        positionsTable->setSelectionBehavior(QAbstractItemView::SelectRows);
        positionsTable->setVerticalScrollMode(QAbstractItemView::ScrollPerPixel);
        positionsTable->setHorizontalScrollMode(QAbstractItemView::ScrollPerPixel);
        positionsTable->setGridStyle(Qt::SolidLine);
        positionsTable->horizontalHeader()->setStretchLastSection(true);

        horizontalLayout_2->addWidget(positionsTable);

        horizontalSpacer_9 = new QSpacerItem(40, 20, QSizePolicy::Preferred, QSizePolicy::Minimum);

        horizontalLayout_2->addItem(horizontalSpacer_9);


        verticalLayout->addLayout(horizontalLayout_2);


        gridLayout->addLayout(verticalLayout, 0, 0, 2, 1);

        contactsTable = new QTableWidget(suppDetails_GBox);
        if (contactsTable->columnCount() < 4)
            contactsTable->setColumnCount(4);
        QTableWidgetItem *__qtablewidgetitem2 = new QTableWidgetItem();
        contactsTable->setHorizontalHeaderItem(0, __qtablewidgetitem2);
        QTableWidgetItem *__qtablewidgetitem3 = new QTableWidgetItem();
        contactsTable->setHorizontalHeaderItem(1, __qtablewidgetitem3);
        QTableWidgetItem *__qtablewidgetitem4 = new QTableWidgetItem();
        contactsTable->setHorizontalHeaderItem(2, __qtablewidgetitem4);
        QTableWidgetItem *__qtablewidgetitem5 = new QTableWidgetItem();
        contactsTable->setHorizontalHeaderItem(3, __qtablewidgetitem5);
        contactsTable->setObjectName(QString::fromUtf8("contactsTable"));
        QSizePolicy sizePolicy3(QSizePolicy::Expanding, QSizePolicy::Expanding);
        sizePolicy3.setHorizontalStretch(0);
        sizePolicy3.setVerticalStretch(0);
        sizePolicy3.setHeightForWidth(contactsTable->sizePolicy().hasHeightForWidth());
        contactsTable->setSizePolicy(sizePolicy3);
        contactsTable->setContextMenuPolicy(Qt::CustomContextMenu);
        contactsTable->setEditTriggers(QAbstractItemView::NoEditTriggers);
        contactsTable->setAlternatingRowColors(true);
        contactsTable->setSelectionMode(QAbstractItemView::SingleSelection);
        contactsTable->setSelectionBehavior(QAbstractItemView::SelectRows);
        contactsTable->setVerticalScrollMode(QAbstractItemView::ScrollPerPixel);
        contactsTable->setHorizontalScrollMode(QAbstractItemView::ScrollPerPixel);
        contactsTable->setGridStyle(Qt::SolidLine);
        contactsTable->horizontalHeader()->setStretchLastSection(true);

        gridLayout->addWidget(contactsTable, 0, 1, 1, 1);


        verticalLayout_3->addWidget(suppDetails_GBox);

        remarkGBox = new QGroupBox(SupplierDialog);
        remarkGBox->setObjectName(QString::fromUtf8("remarkGBox"));
        remarkGBox->setMaximumSize(QSize(16777215, 120));
        remarkGBox->setFont(font);
        verticalLayout_2 = new QVBoxLayout(remarkGBox);
        verticalLayout_2->setSpacing(6);
        verticalLayout_2->setContentsMargins(11, 11, 11, 11);
        verticalLayout_2->setObjectName(QString::fromUtf8("verticalLayout_2"));
        remarkTextEdit = new QTextEdit(remarkGBox);
        remarkTextEdit->setObjectName(QString::fromUtf8("remarkTextEdit"));
        remarkTextEdit->setMaximumSize(QSize(16777215, 80));

        verticalLayout_2->addWidget(remarkTextEdit);


        verticalLayout_3->addWidget(remarkGBox);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setSpacing(6);
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        horizontalSpacer_6 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer_6);

        addOrSave_btn = new QPushButton(SupplierDialog);
        addOrSave_btn->setObjectName(QString::fromUtf8("addOrSave_btn"));

        horizontalLayout->addWidget(addOrSave_btn);

        horizontalSpacer_5 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer_5);

        cancel_btn = new QPushButton(SupplierDialog);
        cancel_btn->setObjectName(QString::fromUtf8("cancel_btn"));

        horizontalLayout->addWidget(cancel_btn);

        horizontalSpacer_7 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer_7);


        verticalLayout_3->addLayout(horizontalLayout);


        retranslateUi(SupplierDialog);
        QObject::connect(addPosition_btn, SIGNAL(clicked()), SupplierDialog, SLOT(addPositionToTableSlot()));
        QObject::connect(openPositionsForm_btn, SIGNAL(clicked()), SupplierDialog, SLOT(openPositionsFormSlot()));
        QObject::connect(addOrSave_btn, SIGNAL(clicked()), SupplierDialog, SLOT(acceptSlot()));
        QObject::connect(cancel_btn, SIGNAL(clicked()), SupplierDialog, SLOT(reject()));
        QObject::connect(addNewPosition_btn, SIGNAL(clicked()), SupplierDialog, SLOT(addNewPositionSlot()));
        QObject::connect(removePosition_btn, SIGNAL(clicked()), SupplierDialog, SLOT(removePositionFromTableSlot()));

        QMetaObject::connectSlotsByName(SupplierDialog);
    } // setupUi

    void retranslateUi(QDialog *SupplierDialog)
    {
        SupplierDialog->setWindowTitle(QCoreApplication::translate("SupplierDialog", "SupplierDialog", nullptr));
        nameGBox->setTitle(QCoreApplication::translate("SupplierDialog", "\320\237\320\276\321\201\321\202\320\260\320\262\321\211\320\270\320\272", nullptr));
        suppDetails_GBox->setTitle(QString());
        addNewPosition_btn->setText(QCoreApplication::translate("SupplierDialog", "\320\224\320\276\320\261\320\260\320\262\320\270\321\202\321\214 \320\275\320\276\320\262\321\203\321\216 \320\277\320\276\320\267\320\270\321\206\320\270\321\216", nullptr));
        openPositionsForm_btn->setText(QCoreApplication::translate("SupplierDialog", "\320\236\321\202\320\272\321\200\321\213\321\202\321\214 \321\201\320\277\320\270\321\201\320\276\320\272 \320\262\321\201\320\265\321\205 \320\277\320\276\320\267\320\270\321\206\320\270\320\271", nullptr));
#if QT_CONFIG(tooltip)
        positionsCBox->setToolTip(QCoreApplication::translate("SupplierDialog", "<html><head/><body><p>\320\222\320\262\320\265\320\264\320\270\321\202\320\265 \320\277\320\276\320\267\320\270\321\206\320\270\321\216. </p><p>\320\225\321\201\320\273\320\270 \320\277\320\276\320\267\320\270\321\206\320\270\321\217 \320\276\321\202\321\201\321\203\321\202\321\201\321\202\320\262\321\203\320\265\321\202, \320\275\320\260\320\266\320\274\320\270\321\202\320\265 &quot;\320\224\320\276\320\261\320\260\320\262\320\270\321\202\321\214 \320\275\320\276\320\262\321\203\321\216 \320\277\320\276\320\267\320\270\321\206\320\270\321\216&quot;</p></body></html>", nullptr));
#endif // QT_CONFIG(tooltip)
        addPosition_btn->setText(QCoreApplication::translate("SupplierDialog", "\320\224\320\276\320\261\320\260\320\262\320\270\321\202\321\214 \320\277\320\276\320\267\320\270\321\206\320\270\321\216 \320\262 \321\202\320\260\320\261\320\273\320\270\321\206\321\203", nullptr));
        removePosition_btn->setText(QCoreApplication::translate("SupplierDialog", "\320\243\320\264\320\260\320\273\320\270\321\202\321\214 \320\277\320\276\320\267\320\270\321\206\320\270\321\216 \320\270\320\267 \321\202\320\260\320\261\320\273\320\270\321\206\321\213", nullptr));
        QTableWidgetItem *___qtablewidgetitem = positionsTable->horizontalHeaderItem(0);
        ___qtablewidgetitem->setText(QCoreApplication::translate("SupplierDialog", "id", nullptr));
        QTableWidgetItem *___qtablewidgetitem1 = positionsTable->horizontalHeaderItem(1);
        ___qtablewidgetitem1->setText(QCoreApplication::translate("SupplierDialog", "\320\237\320\276\320\267\320\270\321\206\320\270\321\217", nullptr));
        QTableWidgetItem *___qtablewidgetitem2 = contactsTable->horizontalHeaderItem(0);
        ___qtablewidgetitem2->setText(QCoreApplication::translate("SupplierDialog", "id", nullptr));
        QTableWidgetItem *___qtablewidgetitem3 = contactsTable->horizontalHeaderItem(1);
        ___qtablewidgetitem3->setText(QCoreApplication::translate("SupplierDialog", "\320\230\320\274\321\217", nullptr));
        QTableWidgetItem *___qtablewidgetitem4 = contactsTable->horizontalHeaderItem(2);
        ___qtablewidgetitem4->setText(QCoreApplication::translate("SupplierDialog", "\320\242\320\265\320\273\320\265\321\204\320\276\320\275", nullptr));
        QTableWidgetItem *___qtablewidgetitem5 = contactsTable->horizontalHeaderItem(3);
        ___qtablewidgetitem5->setText(QCoreApplication::translate("SupplierDialog", "E-mail", nullptr));
        remarkGBox->setTitle(QCoreApplication::translate("SupplierDialog", "\320\237\321\200\320\270\320\274\320\265\321\207\320\260\320\275\320\270\320\265", nullptr));
        addOrSave_btn->setText(QCoreApplication::translate("SupplierDialog", "\320\224\320\276\320\261\320\260\320\262\320\270\321\202\321\214", nullptr));
        cancel_btn->setText(QCoreApplication::translate("SupplierDialog", "\320\236\321\202\320\274\320\265\320\275\320\260", nullptr));
    } // retranslateUi

};

namespace Ui {
    class SupplierDialog: public Ui_SupplierDialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_SUPPLIERDIALOG_H
