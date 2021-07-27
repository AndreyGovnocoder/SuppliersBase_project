/********************************************************************************
** Form generated from reading UI file 'PositionsForm.ui'
**
** Created by: Qt User Interface Compiler version 5.15.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_POSITIONSFORM_H
#define UI_POSITIONSFORM_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QTableWidget>
#include <QtWidgets/QVBoxLayout>

QT_BEGIN_NAMESPACE

class Ui_PositionsForm
{
public:
    QVBoxLayout *verticalLayout;
    QGroupBox *search_GBox;
    QHBoxLayout *horizontalLayout_2;
    QLineEdit *search_lineEdit;
    QTableWidget *positionsTable;
    QHBoxLayout *horizontalLayout;
    QSpacerItem *horizontalSpacer;
    QPushButton *close_btn;

    void setupUi(QDialog *PositionsForm)
    {
        if (PositionsForm->objectName().isEmpty())
            PositionsForm->setObjectName(QString::fromUtf8("PositionsForm"));
        PositionsForm->resize(325, 284);
        verticalLayout = new QVBoxLayout(PositionsForm);
        verticalLayout->setSpacing(12);
        verticalLayout->setContentsMargins(11, 11, 11, 11);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        search_GBox = new QGroupBox(PositionsForm);
        search_GBox->setObjectName(QString::fromUtf8("search_GBox"));
        QFont font;
        font.setPointSize(10);
        search_GBox->setFont(font);
        search_GBox->setAlignment(Qt::AlignCenter);
        horizontalLayout_2 = new QHBoxLayout(search_GBox);
        horizontalLayout_2->setSpacing(6);
        horizontalLayout_2->setContentsMargins(11, 11, 11, 11);
        horizontalLayout_2->setObjectName(QString::fromUtf8("horizontalLayout_2"));
        search_lineEdit = new QLineEdit(search_GBox);
        search_lineEdit->setObjectName(QString::fromUtf8("search_lineEdit"));
        search_lineEdit->setFont(font);

        horizontalLayout_2->addWidget(search_lineEdit);


        verticalLayout->addWidget(search_GBox);

        positionsTable = new QTableWidget(PositionsForm);
        if (positionsTable->columnCount() < 2)
            positionsTable->setColumnCount(2);
        QTableWidgetItem *__qtablewidgetitem = new QTableWidgetItem();
        positionsTable->setHorizontalHeaderItem(0, __qtablewidgetitem);
        QTableWidgetItem *__qtablewidgetitem1 = new QTableWidgetItem();
        positionsTable->setHorizontalHeaderItem(1, __qtablewidgetitem1);
        positionsTable->setObjectName(QString::fromUtf8("positionsTable"));
        positionsTable->setContextMenuPolicy(Qt::CustomContextMenu);
        positionsTable->setAlternatingRowColors(true);
        positionsTable->setSelectionMode(QAbstractItemView::SingleSelection);
        positionsTable->setSelectionBehavior(QAbstractItemView::SelectRows);
        positionsTable->setVerticalScrollMode(QAbstractItemView::ScrollPerPixel);
        positionsTable->setHorizontalScrollMode(QAbstractItemView::ScrollPerPixel);
        positionsTable->horizontalHeader()->setStretchLastSection(true);

        verticalLayout->addWidget(positionsTable);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setSpacing(6);
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer);

        close_btn = new QPushButton(PositionsForm);
        close_btn->setObjectName(QString::fromUtf8("close_btn"));

        horizontalLayout->addWidget(close_btn);


        verticalLayout->addLayout(horizontalLayout);


        retranslateUi(PositionsForm);
        QObject::connect(close_btn, SIGNAL(clicked()), PositionsForm, SLOT(close()));
        QObject::connect(search_lineEdit, SIGNAL(textEdited(QString)), PositionsForm, SLOT(searchPositionsSlot()));

        QMetaObject::connectSlotsByName(PositionsForm);
    } // setupUi

    void retranslateUi(QDialog *PositionsForm)
    {
        PositionsForm->setWindowTitle(QCoreApplication::translate("PositionsForm", "PositionsForm", nullptr));
        search_GBox->setTitle(QCoreApplication::translate("PositionsForm", "\320\237\320\276\320\270\321\201\320\272", nullptr));
        QTableWidgetItem *___qtablewidgetitem = positionsTable->horizontalHeaderItem(0);
        ___qtablewidgetitem->setText(QCoreApplication::translate("PositionsForm", "id", nullptr));
        QTableWidgetItem *___qtablewidgetitem1 = positionsTable->horizontalHeaderItem(1);
        ___qtablewidgetitem1->setText(QCoreApplication::translate("PositionsForm", "\320\237\320\276\320\267\320\270\321\206\320\270\321\217", nullptr));
        close_btn->setText(QCoreApplication::translate("PositionsForm", "\320\227\320\260\320\272\321\200\321\213\321\202\321\214", nullptr));
    } // retranslateUi

};

namespace Ui {
    class PositionsForm: public Ui_PositionsForm {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_POSITIONSFORM_H
