/********************************************************************************
** Form generated from reading UI file 'enterroom.ui'
**
** Created by: Qt User Interface Compiler version 5.6.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_ENTERROOM_H
#define UI_ENTERROOM_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QCheckBox>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_wgEnterRoom
{
public:
    QLabel *lbChannel;
    QLabel *label;
    QPushButton *btnExit;
    QCheckBox *rbCamera;
    QCheckBox *rbMic;

    void setupUi(QWidget *wgEnterRoom)
    {
        if (wgEnterRoom->objectName().isEmpty())
            wgEnterRoom->setObjectName(QStringLiteral("wgEnterRoom"));
        wgEnterRoom->resize(1366, 768);
        wgEnterRoom->setStyleSheet(QLatin1String("QWidget {\n"
"	width:1366px;\n"
"	height:768px;\n"
"	image: url(:/uiresource/Open live-03.jpg);\n"
"}"));
        lbChannel = new QLabel(wgEnterRoom);
        lbChannel->setObjectName(QStringLiteral("lbChannel"));
        lbChannel->setGeometry(QRect(30, 30, 200, 44));
        QFont font;
        font.setFamily(QStringLiteral("HelveticaNeue"));
        font.setBold(true);
        font.setWeight(75);
        lbChannel->setFont(font);
        lbChannel->setStyleSheet(QLatin1String("QLabel {\n"
"	width:200px;\n"
"	height:44px;\n"
"	image: url(:/uiresource/Group 31.png);\n"
"	font-size:16px;\n"
"	font-family:HelveticaNeue;\n"
"	color:rgba(255,255,255,1);\n"
"	line-height:18px;\n"
"}"));
        lbChannel->setAlignment(Qt::AlignCenter);
        label = new QLabel(wgEnterRoom);
        label->setObjectName(QStringLiteral("label"));
        label->setGeometry(QRect(1024, 37, 264, 32));
        label->setStyleSheet(QLatin1String("QLabel {\n"
"	width:264px;\n"
"	height:32px;\n"
"	image: url(:/uiresource/Groupparam.png);\n"
"	border-radius:4px;\n"
"	opacity:0.4;\n"
"	font-size:12px;\n"
"	font-family:HelveticaNeue;\n"
"	color:rgba(238,238,238,1);\n"
"	line-height:18px;\n"
"}"));
        label->setAlignment(Qt::AlignCenter);
        btnExit = new QPushButton(wgEnterRoom);
        btnExit->setObjectName(QStringLiteral("btnExit"));
        btnExit->setGeometry(QRect(1298, 36, 32, 32));
        btnExit->setStyleSheet(QLatin1String("QPushButton:!hover {\n"
"width:32px;\n"
"height:32px;\n"
"image: url(:/uiresource/icon-exit.png);\n"
"border-image: url(:/uiresource/icon-exit.png);\n"
"}\n"
"\n"
"QPushButton:hover {\n"
"width:32px;\n"
"height:32px;\n"
"image: url(:/uiresource/icon-exit hover.png);\n"
"border-image: url(:/uiresource/icon-exit hover.png);\n"
"}"));
        rbCamera = new QCheckBox(wgEnterRoom);
        rbCamera->setObjectName(QStringLiteral("rbCamera"));
        rbCamera->setGeometry(QRect(624, 688, 50, 50));
        rbCamera->setStyleSheet(QLatin1String("QCheckBox::indicator{\n"
"	width:50px;\n"
"	height:50px;\n"
"}\n"
"\n"
"QCheckBox:indicator:checked:!hover {\n"
"	image: url(:/uiresource/icon-camera off.png);\n"
"}\n"
"QCheckBox:indicator:checked:hover {\n"
"	image: url(:/uiresource/icon-camera off hover.png);\n"
"}\n"
"\n"
"QCheckBox:indicator:unchecked:!hover {\n"
"	image: url(:/uiresource/icon-camera.png);\n"
"}\n"
"QCheckBox:indicator:unchecked:hover {\n"
"	image: url(:/uiresource/icon-camera hover.png);\n"
"}"));
        rbCamera->setCheckable(true);
        rbCamera->setChecked(false);
        rbMic = new QCheckBox(wgEnterRoom);
        rbMic->setObjectName(QStringLiteral("rbMic"));
        rbMic->setGeometry(QRect(693, 688, 50, 50));
        rbMic->setStyleSheet(QLatin1String("QCheckBox::indicator{\n"
"	width:50px;\n"
"	height:50px;\n"
"}\n"
"\n"
"QCheckBox:indicator:checked:!hover {\n"
"	image: url(:/uiresource/icon-microphone off.png);\n"
"}\n"
"QCheckBox:indicator:checked:hover {\n"
"	image: url(:/uiresource/icon-microphone off hover.png);\n"
"}\n"
"\n"
"QCheckBox:indicator:unchecked:!hover {\n"
"	image: url(:/uiresource/icon-microphone.png);\n"
"}\n"
"QCheckBox:indicator:unchecked:hover {\n"
"	image: url(:/uiresource/icon-microphone hover.png);\n"
"}"));
        rbMic->setCheckable(true);
        rbMic->setChecked(false);

        retranslateUi(wgEnterRoom);

        QMetaObject::connectSlotsByName(wgEnterRoom);
    } // setupUi

    void retranslateUi(QWidget *wgEnterRoom)
    {
        wgEnterRoom->setWindowTitle(QApplication::translate("wgEnterRoom", "Form", 0));
        lbChannel->setText(QApplication::translate("wgEnterRoom", "baluoteliz", 0));
        label->setText(QApplication::translate("wgEnterRoom", "SD-RTN: 10000ms. Video: 15fps 640x480", 0));
        btnExit->setText(QString());
        rbCamera->setText(QApplication::translate("wgEnterRoom", "RadioButton", 0));
        rbMic->setText(QApplication::translate("wgEnterRoom", "RadioButton", 0));
    } // retranslateUi

};

namespace Ui {
    class wgEnterRoom: public Ui_wgEnterRoom {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_ENTERROOM_H
