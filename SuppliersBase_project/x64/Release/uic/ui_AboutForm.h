/********************************************************************************
** Form generated from reading UI file 'AboutForm.ui'
**
** Created by: Qt User Interface Compiler version 5.15.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_ABOUTFORM_H
#define UI_ABOUTFORM_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QFrame>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QVBoxLayout>

QT_BEGIN_NAMESPACE

class Ui_AboutForm
{
public:
    QVBoxLayout *verticalLayout;
    QHBoxLayout *horizontalLayout_15;
    QLabel *imageLogo_lbl;
    QLabel *headName_lbl;
    QHBoxLayout *horizontalLayout_16;
    QSpacerItem *horizontalSpacer_19;
    QLabel *version_lbl;
    QSpacerItem *horizontalSpacer_20;
    QLabel *label_3;
    QFrame *line;
    QHBoxLayout *horizontalLayout_17;
    QLabel *label_12;
    QSpacerItem *horizontalSpacer_21;
    QHBoxLayout *horizontalLayout_18;
    QLabel *goose_lbl;
    QLabel *dev_lbl;
    QSpacerItem *horizontalSpacer_22;
    QSpacerItem *verticalSpacer_2;
    QHBoxLayout *horizontalLayout_19;
    QLabel *info_lbl;
    QLineEdit *mail_lineEdit;
    QSpacerItem *verticalSpacer_3;
    QLabel *copyright_lbl1;
    QLabel *copyright_lbl2;
    QSpacerItem *verticalSpacer;
    QHBoxLayout *horizontalLayout_20;
    QSpacerItem *horizontalSpacer_25;
    QPushButton *closeButton;
    QSpacerItem *horizontalSpacer_26;

    void setupUi(QDialog *AboutForm)
    {
        if (AboutForm->objectName().isEmpty())
            AboutForm->setObjectName(QString::fromUtf8("AboutForm"));
        AboutForm->resize(465, 405);
        verticalLayout = new QVBoxLayout(AboutForm);
        verticalLayout->setSpacing(6);
        verticalLayout->setContentsMargins(11, 11, 11, 11);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        horizontalLayout_15 = new QHBoxLayout();
        horizontalLayout_15->setSpacing(6);
        horizontalLayout_15->setObjectName(QString::fromUtf8("horizontalLayout_15"));
        imageLogo_lbl = new QLabel(AboutForm);
        imageLogo_lbl->setObjectName(QString::fromUtf8("imageLogo_lbl"));
        QSizePolicy sizePolicy(QSizePolicy::Fixed, QSizePolicy::Fixed);
        sizePolicy.setHorizontalStretch(90);
        sizePolicy.setVerticalStretch(90);
        sizePolicy.setHeightForWidth(imageLogo_lbl->sizePolicy().hasHeightForWidth());
        imageLogo_lbl->setSizePolicy(sizePolicy);
        imageLogo_lbl->setMinimumSize(QSize(90, 90));
        imageLogo_lbl->setMaximumSize(QSize(90, 90));
        imageLogo_lbl->setPixmap(QPixmap(QString::fromUtf8(":/MainInterface/logo.png")));
        imageLogo_lbl->setScaledContents(true);

        horizontalLayout_15->addWidget(imageLogo_lbl);

        headName_lbl = new QLabel(AboutForm);
        headName_lbl->setObjectName(QString::fromUtf8("headName_lbl"));
        QSizePolicy sizePolicy1(QSizePolicy::Fixed, QSizePolicy::Fixed);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(headName_lbl->sizePolicy().hasHeightForWidth());
        headName_lbl->setSizePolicy(sizePolicy1);
        headName_lbl->setMinimumSize(QSize(272, 89));
        headName_lbl->setMaximumSize(QSize(272, 89));
        headName_lbl->setPixmap(QPixmap(QString::fromUtf8(":/MainInterface/headName.png")));
        headName_lbl->setScaledContents(true);

        horizontalLayout_15->addWidget(headName_lbl);


        verticalLayout->addLayout(horizontalLayout_15);

        horizontalLayout_16 = new QHBoxLayout();
        horizontalLayout_16->setSpacing(6);
        horizontalLayout_16->setObjectName(QString::fromUtf8("horizontalLayout_16"));
        horizontalSpacer_19 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_16->addItem(horizontalSpacer_19);

        version_lbl = new QLabel(AboutForm);
        version_lbl->setObjectName(QString::fromUtf8("version_lbl"));
        QFont font;
        font.setFamily(QString::fromUtf8("Calibri"));
        font.setPointSize(15);
        version_lbl->setFont(font);

        horizontalLayout_16->addWidget(version_lbl);

        horizontalSpacer_20 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_16->addItem(horizontalSpacer_20);


        verticalLayout->addLayout(horizontalLayout_16);

        label_3 = new QLabel(AboutForm);
        label_3->setObjectName(QString::fromUtf8("label_3"));
        QSizePolicy sizePolicy2(QSizePolicy::Expanding, QSizePolicy::Expanding);
        sizePolicy2.setHorizontalStretch(0);
        sizePolicy2.setVerticalStretch(0);
        sizePolicy2.setHeightForWidth(label_3->sizePolicy().hasHeightForWidth());
        label_3->setSizePolicy(sizePolicy2);
        QFont font1;
        font1.setFamily(QString::fromUtf8("Calibri"));
        font1.setPointSize(12);
        label_3->setFont(font1);
        label_3->setWordWrap(true);

        verticalLayout->addWidget(label_3);

        line = new QFrame(AboutForm);
        line->setObjectName(QString::fromUtf8("line"));
        line->setFrameShape(QFrame::HLine);
        line->setFrameShadow(QFrame::Sunken);

        verticalLayout->addWidget(line);

        horizontalLayout_17 = new QHBoxLayout();
        horizontalLayout_17->setSpacing(6);
        horizontalLayout_17->setObjectName(QString::fromUtf8("horizontalLayout_17"));
        label_12 = new QLabel(AboutForm);
        label_12->setObjectName(QString::fromUtf8("label_12"));

        horizontalLayout_17->addWidget(label_12);

        horizontalSpacer_21 = new QSpacerItem(20, 20, QSizePolicy::Fixed, QSizePolicy::Minimum);

        horizontalLayout_17->addItem(horizontalSpacer_21);

        horizontalLayout_18 = new QHBoxLayout();
        horizontalLayout_18->setSpacing(6);
        horizontalLayout_18->setObjectName(QString::fromUtf8("horizontalLayout_18"));
        goose_lbl = new QLabel(AboutForm);
        goose_lbl->setObjectName(QString::fromUtf8("goose_lbl"));
        goose_lbl->setMinimumSize(QSize(53, 40));
        goose_lbl->setMaximumSize(QSize(53, 40));
        goose_lbl->setPixmap(QPixmap(QString::fromUtf8(":/MainInterface/goose.png")));
        goose_lbl->setScaledContents(true);

        horizontalLayout_18->addWidget(goose_lbl);

        dev_lbl = new QLabel(AboutForm);
        dev_lbl->setObjectName(QString::fromUtf8("dev_lbl"));

        horizontalLayout_18->addWidget(dev_lbl);

        horizontalSpacer_22 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_18->addItem(horizontalSpacer_22);


        horizontalLayout_17->addLayout(horizontalLayout_18);


        verticalLayout->addLayout(horizontalLayout_17);

        verticalSpacer_2 = new QSpacerItem(20, 10, QSizePolicy::Minimum, QSizePolicy::Fixed);

        verticalLayout->addItem(verticalSpacer_2);

        horizontalLayout_19 = new QHBoxLayout();
        horizontalLayout_19->setSpacing(6);
        horizontalLayout_19->setObjectName(QString::fromUtf8("horizontalLayout_19"));
        info_lbl = new QLabel(AboutForm);
        info_lbl->setObjectName(QString::fromUtf8("info_lbl"));
        sizePolicy1.setHeightForWidth(info_lbl->sizePolicy().hasHeightForWidth());
        info_lbl->setSizePolicy(sizePolicy1);
        info_lbl->setMinimumSize(QSize(0, 0));

        horizontalLayout_19->addWidget(info_lbl);

        mail_lineEdit = new QLineEdit(AboutForm);
        mail_lineEdit->setObjectName(QString::fromUtf8("mail_lineEdit"));
        mail_lineEdit->setStyleSheet(QString::fromUtf8("background-color: rgba(255, 255, 255, 0);\n"
"border-color: rgba(255, 255, 255, 0);"));
        mail_lineEdit->setReadOnly(true);

        horizontalLayout_19->addWidget(mail_lineEdit);


        verticalLayout->addLayout(horizontalLayout_19);

        verticalSpacer_3 = new QSpacerItem(20, 10, QSizePolicy::Minimum, QSizePolicy::Fixed);

        verticalLayout->addItem(verticalSpacer_3);

        copyright_lbl1 = new QLabel(AboutForm);
        copyright_lbl1->setObjectName(QString::fromUtf8("copyright_lbl1"));
        QFont font2;
        font2.setFamily(QString::fromUtf8("Calibri"));
        font2.setPointSize(10);
        copyright_lbl1->setFont(font2);
        copyright_lbl1->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        verticalLayout->addWidget(copyright_lbl1);

        copyright_lbl2 = new QLabel(AboutForm);
        copyright_lbl2->setObjectName(QString::fromUtf8("copyright_lbl2"));
        copyright_lbl2->setFont(font2);
        copyright_lbl2->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        verticalLayout->addWidget(copyright_lbl2);

        verticalSpacer = new QSpacerItem(20, 23, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout->addItem(verticalSpacer);

        horizontalLayout_20 = new QHBoxLayout();
        horizontalLayout_20->setSpacing(6);
        horizontalLayout_20->setObjectName(QString::fromUtf8("horizontalLayout_20"));
        horizontalSpacer_25 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_20->addItem(horizontalSpacer_25);

        closeButton = new QPushButton(AboutForm);
        closeButton->setObjectName(QString::fromUtf8("closeButton"));

        horizontalLayout_20->addWidget(closeButton);

        horizontalSpacer_26 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_20->addItem(horizontalSpacer_26);


        verticalLayout->addLayout(horizontalLayout_20);


        retranslateUi(AboutForm);
        QObject::connect(closeButton, SIGNAL(clicked()), AboutForm, SLOT(reject()));

        QMetaObject::connectSlotsByName(AboutForm);
    } // setupUi

    void retranslateUi(QDialog *AboutForm)
    {
        AboutForm->setWindowTitle(QCoreApplication::translate("AboutForm", "AboutForm", nullptr));
        imageLogo_lbl->setText(QString());
        headName_lbl->setText(QString());
        version_lbl->setText(QCoreApplication::translate("AboutForm", "\320\222\320\265\321\200\321\201\320\270\321\217: 1.0", nullptr));
        label_3->setText(QString());
        label_12->setText(QCoreApplication::translate("AboutForm", "\320\240\320\260\320\267\321\200\320\260\320\261\320\276\321\202\320\260\320\275\320\276:", nullptr));
        goose_lbl->setText(QString());
        dev_lbl->setText(QCoreApplication::translate("AboutForm", " \320\220\320\275\320\264\321\200\320\265\320\271 \320\223\321\203\320\273\320\270\320\271", nullptr));
        info_lbl->setText(QCoreApplication::translate("AboutForm", "\320\237\320\276 \320\262\320\276\320\277\321\200\320\276\321\201\320\260\320\274 \320\270 \320\277\321\200\320\265\320\264\320\273\320\276\320\266\320\265\320\275\320\270\321\217\320\274 \320\277\320\270\321\201\320\260\321\202\321\214 \320\275\320\260 \321\215\320\273\320\265\320\272\321\202\321\200\320\276\320\275\320\275\321\203\321\216 \320\277\320\276\321\207\321\202\321\203:  ", nullptr));
        mail_lineEdit->setText(QCoreApplication::translate("AboutForm", "elizgerd@yandex.ru", nullptr));
        copyright_lbl1->setText(QCoreApplication::translate("AboutForm", "Copyright \302\251 2021 \320\220\320\275\320\264\321\200\320\265\320\271 \320\223\321\203\320\273\320\270\320\271", nullptr));
        copyright_lbl2->setText(QCoreApplication::translate("AboutForm", "\320\222\321\201\320\265 \320\277\321\200\320\260\320\262\320\260 \320\267\320\260\321\211\320\270\321\211\320\265\320\275\321\213", nullptr));
        closeButton->setText(QCoreApplication::translate("AboutForm", "\320\227\320\260\320\272\321\200\321\213\321\202\321\214", nullptr));
    } // retranslateUi

};

namespace Ui {
    class AboutForm: public Ui_AboutForm {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_ABOUTFORM_H
