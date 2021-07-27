/********************************************************************************
** Form generated from reading UI file 'PositionDialog.ui'
**
** Created by: Qt User Interface Compiler version 5.15.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_POSITIONDIALOG_H
#define UI_POSITIONDIALOG_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QVBoxLayout>

QT_BEGIN_NAMESPACE

class Ui_PositionDialog
{
public:
    QVBoxLayout *verticalLayout;
    QSpacerItem *verticalSpacer_2;
    QGroupBox *name_GBox;
    QHBoxLayout *horizontalLayout_2;
    QLineEdit *name_lineEdit;
    QSpacerItem *verticalSpacer;
    QHBoxLayout *horizontalLayout;
    QPushButton *addOrSave_btn;
    QSpacerItem *horizontalSpacer;
    QPushButton *cancel_btn;

    void setupUi(QDialog *PositionDialog)
    {
        if (PositionDialog->objectName().isEmpty())
            PositionDialog->setObjectName(QString::fromUtf8("PositionDialog"));
        PositionDialog->resize(423, 171);
        verticalLayout = new QVBoxLayout(PositionDialog);
        verticalLayout->setSpacing(6);
        verticalLayout->setContentsMargins(11, 11, 11, 11);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        verticalSpacer_2 = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout->addItem(verticalSpacer_2);

        name_GBox = new QGroupBox(PositionDialog);
        name_GBox->setObjectName(QString::fromUtf8("name_GBox"));
        QFont font;
        font.setPointSize(10);
        name_GBox->setFont(font);
        name_GBox->setAlignment(Qt::AlignCenter);
        horizontalLayout_2 = new QHBoxLayout(name_GBox);
        horizontalLayout_2->setSpacing(6);
        horizontalLayout_2->setContentsMargins(11, 11, 11, 11);
        horizontalLayout_2->setObjectName(QString::fromUtf8("horizontalLayout_2"));
        name_lineEdit = new QLineEdit(name_GBox);
        name_lineEdit->setObjectName(QString::fromUtf8("name_lineEdit"));

        horizontalLayout_2->addWidget(name_lineEdit);


        verticalLayout->addWidget(name_GBox);

        verticalSpacer = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout->addItem(verticalSpacer);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setSpacing(6);
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        addOrSave_btn = new QPushButton(PositionDialog);
        addOrSave_btn->setObjectName(QString::fromUtf8("addOrSave_btn"));

        horizontalLayout->addWidget(addOrSave_btn);

        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer);

        cancel_btn = new QPushButton(PositionDialog);
        cancel_btn->setObjectName(QString::fromUtf8("cancel_btn"));

        horizontalLayout->addWidget(cancel_btn);


        verticalLayout->addLayout(horizontalLayout);


        retranslateUi(PositionDialog);
        QObject::connect(cancel_btn, SIGNAL(clicked()), PositionDialog, SLOT(reject()));
        QObject::connect(addOrSave_btn, SIGNAL(clicked()), PositionDialog, SLOT(acceptSlot()));

        QMetaObject::connectSlotsByName(PositionDialog);
    } // setupUi

    void retranslateUi(QDialog *PositionDialog)
    {
        PositionDialog->setWindowTitle(QCoreApplication::translate("PositionDialog", "PositionDialog", nullptr));
        name_GBox->setTitle(QCoreApplication::translate("PositionDialog", "\320\235\320\260\320\267\320\262\320\260\320\275\320\270\320\265 \320\277\320\276\320\267\320\270\321\206\320\270\320\270", nullptr));
        addOrSave_btn->setText(QCoreApplication::translate("PositionDialog", "\320\224\320\276\320\261\320\260\320\262\320\270\321\202\321\214", nullptr));
        cancel_btn->setText(QCoreApplication::translate("PositionDialog", "\320\236\321\202\320\274\320\265\320\275\320\260", nullptr));
    } // retranslateUi

};

namespace Ui {
    class PositionDialog: public Ui_PositionDialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_POSITIONDIALOG_H
