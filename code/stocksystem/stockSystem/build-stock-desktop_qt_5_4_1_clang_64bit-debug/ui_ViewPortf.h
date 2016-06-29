/********************************************************************************
** Form generated from reading UI file 'ViewPortf.ui'
**
** Created by: Qt User Interface Compiler version 5.4.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_VIEWPORTF_H
#define UI_VIEWPORTF_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QScrollArea>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_ViewPortf
{
public:
    QLabel *label;
    QScrollArea *s;
    QWidget *scrollAreaWidgetContents_2;
    QPushButton *pushButton;

    void setupUi(QWidget *ViewPortf)
    {
        if (ViewPortf->objectName().isEmpty())
            ViewPortf->setObjectName(QStringLiteral("ViewPortf"));
        ViewPortf->resize(880, 559);
        label = new QLabel(ViewPortf);
        label->setObjectName(QStringLiteral("label"));
        label->setGeometry(QRect(350, 110, 231, 31));
        s = new QScrollArea(ViewPortf);
        s->setObjectName(QStringLiteral("s"));
        s->setGeometry(QRect(180, 200, 501, 261));
        s->setWidgetResizable(true);
        scrollAreaWidgetContents_2 = new QWidget();
        scrollAreaWidgetContents_2->setObjectName(QStringLiteral("scrollAreaWidgetContents_2"));
        scrollAreaWidgetContents_2->setGeometry(QRect(0, 0, 499, 259));
        s->setWidget(scrollAreaWidgetContents_2);
        pushButton = new QPushButton(ViewPortf);
        pushButton->setObjectName(QStringLiteral("pushButton"));
        pushButton->setGeometry(QRect(60, 20, 115, 32));

        retranslateUi(ViewPortf);

        QMetaObject::connectSlotsByName(ViewPortf);
    } // setupUi

    void retranslateUi(QWidget *ViewPortf)
    {
        ViewPortf->setWindowTitle(QApplication::translate("ViewPortf", "Form", 0));
        label->setText(QApplication::translate("ViewPortf", "<html><head/><body><p><span style=\" font-size:18pt; font-weight:600;\">Stock Portfolio</span></p><p><br/></p><p><span style=\" font-size:18pt; font-weight:600;\"><br/></span></p></body></html>", 0));
        pushButton->setText(QApplication::translate("ViewPortf", "Return", 0));
    } // retranslateUi

};

namespace Ui {
    class ViewPortf: public Ui_ViewPortf {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_VIEWPORTF_H
