/********************************************************************************
** Form generated from reading UI file 'ContactDialog.ui'
**
** Created by: Qt User Interface Compiler version 5.15.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_CONTACTDIALOG_H
#define UI_CONTACTDIALOG_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QVBoxLayout>

QT_BEGIN_NAMESPACE

class Ui_ContactDialog
{
public:
    QVBoxLayout *verticalLayout;
    QSpacerItem *verticalSpacer_2;
    QGridLayout *gridLayout;
    QLabel *label_2;
    QLabel *label;
    QLineEdit *phone_lineEdit;
    QLineEdit *name_lineEdit;
    QLineEdit *email_lineEdit;
    QLabel *email_lbl;
    QSpacerItem *verticalSpacer;
    QHBoxLayout *horizontalLayout;
    QPushButton *add_btn;
    QPushButton *save_btn;
    QSpacerItem *horizontalSpacer;
    QPushButton *cancel_btn;

    void setupUi(QDialog *ContactDialog)
    {
        if (ContactDialog->objectName().isEmpty())
            ContactDialog->setObjectName(QString::fromUtf8("ContactDialog"));
        ContactDialog->resize(373, 175);
        verticalLayout = new QVBoxLayout(ContactDialog);
        verticalLayout->setSpacing(6);
        verticalLayout->setContentsMargins(11, 11, 11, 11);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        verticalSpacer_2 = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout->addItem(verticalSpacer_2);

        gridLayout = new QGridLayout();
        gridLayout->setSpacing(10);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        label_2 = new QLabel(ContactDialog);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        QFont font;
        font.setPointSize(10);
        label_2->setFont(font);
        label_2->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        gridLayout->addWidget(label_2, 1, 0, 1, 1);

        label = new QLabel(ContactDialog);
        label->setObjectName(QString::fromUtf8("label"));
        label->setFont(font);
        label->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        gridLayout->addWidget(label, 0, 0, 1, 1);

        phone_lineEdit = new QLineEdit(ContactDialog);
        phone_lineEdit->setObjectName(QString::fromUtf8("phone_lineEdit"));
        phone_lineEdit->setFont(font);

        gridLayout->addWidget(phone_lineEdit, 1, 1, 1, 1);

        name_lineEdit = new QLineEdit(ContactDialog);
        name_lineEdit->setObjectName(QString::fromUtf8("name_lineEdit"));
        name_lineEdit->setFont(font);

        gridLayout->addWidget(name_lineEdit, 0, 1, 1, 1);

        email_lineEdit = new QLineEdit(ContactDialog);
        email_lineEdit->setObjectName(QString::fromUtf8("email_lineEdit"));
        email_lineEdit->setFont(font);

        gridLayout->addWidget(email_lineEdit, 2, 1, 1, 1);

        email_lbl = new QLabel(ContactDialog);
        email_lbl->setObjectName(QString::fromUtf8("email_lbl"));
        email_lbl->setFont(font);
        email_lbl->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        gridLayout->addWidget(email_lbl, 2, 0, 1, 1);


        verticalLayout->addLayout(gridLayout);

        verticalSpacer = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout->addItem(verticalSpacer);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setSpacing(6);
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        add_btn = new QPushButton(ContactDialog);
        add_btn->setObjectName(QString::fromUtf8("add_btn"));

        horizontalLayout->addWidget(add_btn);

        save_btn = new QPushButton(ContactDialog);
        save_btn->setObjectName(QString::fromUtf8("save_btn"));

        horizontalLayout->addWidget(save_btn);

        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer);

        cancel_btn = new QPushButton(ContactDialog);
        cancel_btn->setObjectName(QString::fromUtf8("cancel_btn"));

        horizontalLayout->addWidget(cancel_btn);


        verticalLayout->addLayout(horizontalLayout);

        QWidget::setTabOrder(name_lineEdit, phone_lineEdit);
        QWidget::setTabOrder(phone_lineEdit, email_lineEdit);
        QWidget::setTabOrder(email_lineEdit, add_btn);
        QWidget::setTabOrder(add_btn, save_btn);
        QWidget::setTabOrder(save_btn, cancel_btn);

        retranslateUi(ContactDialog);
        QObject::connect(add_btn, SIGNAL(clicked()), ContactDialog, SLOT(acceptSlot()));
        QObject::connect(save_btn, SIGNAL(clicked()), ContactDialog, SLOT(acceptSlot()));
        QObject::connect(cancel_btn, SIGNAL(clicked()), ContactDialog, SLOT(reject()));

        QMetaObject::connectSlotsByName(ContactDialog);
    } // setupUi

    void retranslateUi(QDialog *ContactDialog)
    {
        ContactDialog->setWindowTitle(QCoreApplication::translate("ContactDialog", "PhoneDialog", nullptr));
        label_2->setText(QCoreApplication::translate("ContactDialog", "\320\242\320\265\320\273\320\265\321\204\320\276\320\275", nullptr));
        label->setText(QCoreApplication::translate("ContactDialog", "\320\230\320\274\321\217", nullptr));
        email_lbl->setText(QCoreApplication::translate("ContactDialog", "E-mail", nullptr));
        add_btn->setText(QCoreApplication::translate("ContactDialog", "\320\224\320\276\320\261\320\260\320\262\320\270\321\202\321\214", nullptr));
        save_btn->setText(QCoreApplication::translate("ContactDialog", "\320\241\320\276\321\205\321\200\320\260\320\275\320\270\321\202\321\214", nullptr));
        cancel_btn->setText(QCoreApplication::translate("ContactDialog", "\320\236\321\202\320\274\320\265\320\275\320\260", nullptr));
    } // retranslateUi

};

namespace Ui {
    class ContactDialog: public Ui_ContactDialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_CONTACTDIALOG_H
