/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.6.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QRadioButton>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralWidget;
    QPushButton *btnmin;
    QPushButton *btnclose;
    QPushButton *btnset;
    QPushButton *btnjoin;
    QLineEdit *leditRoomId;
    QRadioButton *rbLive;
    QLabel *laLive;
    QLabel *lbLiveLogo;
    QLabel *lbguideLogo;
    QLabel *lbguide;
    QRadioButton *rbguide;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QStringLiteral("MainWindow"));
        MainWindow->resize(736, 536);
        MainWindow->setMinimumSize(QSize(0, 0));
        MainWindow->setMaximumSize(QSize(736, 536));
        MainWindow->setBaseSize(QSize(0, 0));
        QFont font;
        font.setFamily(QString::fromUtf8("\345\276\256\350\275\257\351\233\205\351\273\221 Light"));
        MainWindow->setFont(font);
        MainWindow->setStyleSheet(QStringLiteral("background-image: url(:/uiresource/Open live-win.jpg);"));
        centralWidget = new QWidget(MainWindow);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        centralWidget->setStyleSheet(QStringLiteral("background-image: url(:/uiresource/pic-win01.png);"));
        btnmin = new QPushButton(centralWidget);
        btnmin->setObjectName(QStringLiteral("btnmin"));
        btnmin->setGeometry(QRect(652, 39, 18, 18));
        btnmin->setStyleSheet(QLatin1String("QPushButton#btnmin {\n"
"	border-image: url(:/uiresource/min-normal.png);\n"
"}\n"
"\n"
"QPushButton#btnmin:hover {\n"
"	border-image: url(:/uiresource/min-hover.png);\n"
"}\n"
"\n"
"QPushButton#btnmin:pressed {\n"
"	border-image: url(:/uiresource/min-pushed.png);\n"
"}"));
        btnclose = new QPushButton(centralWidget);
        btnclose->setObjectName(QStringLiteral("btnclose"));
        btnclose->setEnabled(true);
        btnclose->setGeometry(QRect(680, 39, 18, 18));
        btnclose->setAutoFillBackground(false);
        btnclose->setStyleSheet(QLatin1String("QPushButton#btnclose {\n"
"border-image: url(:/uiresource/close-normal.png);\n"
"}\n"
"QPushButton#btnclose:hover {\n"
"border-image: url(:/uiresource/close-hover.png);\n"
"}\n"
"QPushButton#btnclose:pressed {\n"
"border-image: url(:/uiresource/close-pushed.png);\n"
"}\n"
""));
        btnset = new QPushButton(centralWidget);
        btnset->setObjectName(QStringLiteral("btnset"));
        btnset->setGeometry(QRect(388, 32, 32, 32));
        btnset->setStyleSheet(QLatin1String("QPushButton#btnset{\n"
"border-image: url(:/uiresource/icon-setting.png);\n"
"background-image: url(:/uiresource/icon-setting.png);\n"
"}\n"
"QPushButton#btnset:hover{\n"
"	background-image: url(:/uiresource/icon-setting hover.png);\n"
"	border-image: url(:/uiresource/icon-setting hover.png);\n"
"}\n"
"QPushButton#btnset:pressed{\n"
"border-image: url(:/uiresource/icon-setting.png);\n"
"background-image: url(:/uiresource/icon-setting.png);\n"
"}\n"
""));
        btnjoin = new QPushButton(centralWidget);
        btnjoin->setObjectName(QStringLiteral("btnjoin"));
        btnjoin->setGeometry(QRect(411, 390, 260, 44));
        QFont font1;
        font1.setFamily(QString::fromUtf8("\345\276\256\350\275\257\351\233\205\351\273\221"));
        font1.setPointSize(9);
        font1.setBold(false);
        font1.setItalic(false);
        font1.setWeight(9);
        btnjoin->setFont(font1);
        btnjoin->setStyleSheet(QString::fromUtf8("QPushButton#btnjoin{\n"
"border-image: url(:/uiresource/button-default.png);\n"
"background-image: url(:/uiresource/button-default.png);\n"
"color: rgb(255, 255, 255);\n"
"font: 75 9pt \"\345\276\256\350\275\257\351\233\205\351\273\221\";\n"
"}\n"
"\n"
"QPushButton#btnjoin:hover{\n"
"border-image: url(:/uiresource/button-hover.png);\n"
"background-image: url(:/uiresource/button-hover.png);\n"
"color: rgb(0, 0, 0);\n"
"font: 75 9pt \"\345\276\256\350\275\257\351\233\205\351\273\221\";\n"
"}\n"
"\n"
"QPushButton#btnjoin:pressed{\n"
"border-image: url(:/uiresource/button-default.png);\n"
"background-image: url(:/uiresource/button-default.png);\n"
"color: rgb(255, 255, 255);\n"
"font: 75 9pt \"\345\276\256\350\275\257\351\233\205\351\273\221\";\n"
"}"));
        leditRoomId = new QLineEdit(centralWidget);
        leditRoomId->setObjectName(QStringLiteral("leditRoomId"));
        leditRoomId->setGeometry(QRect(416, 340, 250, 25));
        QFont font2;
        font2.setFamily(QString::fromUtf8("\345\276\256\350\275\257\351\233\205\351\273\221"));
        leditRoomId->setFont(font2);
        leditRoomId->setStyleSheet(QString::fromUtf8("QLineEdit#leditRoomId{\n"
"     padding-left: 20px;\n"
" }\n"
"\n"
" QLineEdit:!hover#leditRoomId{\n"
"     border: 1px solid #ffffff;\n"
"     border-radius: 2px;\n"
"     font-family: \345\276\256\350\275\257\351\233\205\351\273\221;\n"
"     font-size: 14px;\n"
"	 background-color: #fafafa;\n"
"	 color: #999999;\n"
"	 border-image: url(:/uiresource/channel_name_edittext.png);\n"
"	 background-image: url(:/uiresource/channel_name_edittext.png);\n"
" }\n"
"\n"
" QLineEdit:hover#leditRoomId{\n"
"     border: 1px solid #0e88eb;\n"
"     border-radius: 2px;\n"
"     font-family: \345\276\256\350\275\257\351\233\205\351\273\221;\n"
"     font-size: 14px;\n"
"	 background-color: #fafafa;\n"
"	 color: #999999;\n"
"	 border-image: url(:/uiresource/channel_name_edittext.png);\n"
"	 background-image: url(:/uiresource/channel_name_edittext.png);\n"
" }\n"
"\n"
" QLineEdit:focus#leditRoomId{\n"
"     border: 1px solid #0e88eb;\n"
"     border-radius: 2px;\n"
"     font-family: \345\276\256\350\275\257\351\233\205\351\273"
                        "\221;\n"
"     font-size: 14px;\n"
"	 background-color: #ffffff;\n"
"	 color: #999999;\n"
" }"));
        leditRoomId->setAlignment(Qt::AlignCenter);
        rbLive = new QRadioButton(centralWidget);
        rbLive->setObjectName(QStringLiteral("rbLive"));
        rbLive->setGeometry(QRect(429, 259, 14, 14));
        rbLive->setStyleSheet(QLatin1String("QRadioButton::indicator{\n"
"	width:14px;\n"
"	height:14px;\n"
"}\n"
"\n"
"QRadioButton::indicator::checked {\n"
"	background-image: url(:/uiresource/radio_checked.png);\n"
"}\n"
"QRadioButton::indicator:checked:hover {\n"
"	background-image: url(:/uiresource/radio_checked.png);\n"
"}\n"
"\n"
"QRadioButton::indicator::unchecked {\n"
"	background-image: url(:/uiresource/radio_unchecked.png);\n"
"}\n"
"QRadioButton::indicator:unchecked :hover {\n"
"	background-image: url(:/uiresource/radio_unchecked.png);\n"
"}"));
        rbLive->setChecked(true);
        laLive = new QLabel(centralWidget);
        laLive->setObjectName(QStringLiteral("laLive"));
        laLive->setGeometry(QRect(448, 256, 56, 20));
        QFont font3;
        font3.setFamily(QString::fromUtf8("\345\271\274\345\234\206"));
        font3.setPointSize(9);
        font3.setBold(true);
        font3.setWeight(75);
        laLive->setFont(font3);
        laLive->setStyleSheet(QLatin1String("QLabel{\n"
"background-image: url(:/uiresource/white.png);\n"
"color:#44A2FC\n"
"}"));
        laLive->setAlignment(Qt::AlignCenter);
        lbLiveLogo = new QLabel(centralWidget);
        lbLiveLogo->setObjectName(QStringLiteral("lbLiveLogo"));
        lbLiveLogo->setGeometry(QRect(416, 126, 100, 118));
        lbLiveLogo->setStyleSheet(QLatin1String("QLabel{\n"
"background-image: url(:/uiresource/pic-live 02.png);\n"
"}"));
        lbguideLogo = new QLabel(centralWidget);
        lbguideLogo->setObjectName(QStringLiteral("lbguideLogo"));
        lbguideLogo->setGeometry(QRect(566, 126, 100, 118));
        lbguideLogo->setStyleSheet(QLatin1String("QLabel{\n"
"	background-image: url(:/uiresource/pic-guide 01.png);\n"
"}"));
        lbguide = new QLabel(centralWidget);
        lbguide->setObjectName(QStringLiteral("lbguide"));
        lbguide->setGeometry(QRect(598, 256, 56, 20));
        QFont font4;
        font4.setFamily(QString::fromUtf8("\345\271\274\345\234\206"));
        font4.setBold(true);
        font4.setWeight(75);
        lbguide->setFont(font4);
        lbguide->setStyleSheet(QLatin1String("QLabel{\n"
"background-image: url(:/uiresource/white.png);\n"
"color:#999999\n"
"}"));
        rbguide = new QRadioButton(centralWidget);
        rbguide->setObjectName(QStringLiteral("rbguide"));
        rbguide->setGeometry(QRect(579, 259, 14, 14));
        rbguide->setStyleSheet(QLatin1String("QRadioButton::indicator{\n"
"	width:14px;\n"
"	height:14px;\n"
"}\n"
"\n"
"QRadioButton::indicator::checked {\n"
"	background-image: url(:/uiresource/radio_checked.png);\n"
"}\n"
"QRadioButton::indicator:checked:hover{\n"
"	background-image: url(:/uiresource/radio_checked.png);\n"
"}\n"
"\n"
"QRadioButton::indicator::unchecked {\n"
"	background-image: url(:/uiresource/radio_unchecked.png);\n"
"}\n"
"QRadioButton::indicator:unchecked:hover {\n"
"	background-image: url(:/uiresource/radio_unchecked.png);\n"
"}"));
        MainWindow->setCentralWidget(centralWidget);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QApplication::translate("MainWindow", "MainWindow", 0));
        btnmin->setText(QString());
        btnclose->setText(QString());
        btnset->setText(QString());
        btnjoin->setText(QApplication::translate("MainWindow", "Start Live Broadcast", 0));
        leditRoomId->setText(QString());
        leditRoomId->setPlaceholderText(QApplication::translate("MainWindow", "Pick a topic to chat", 0));
        rbLive->setText(QString());
        laLive->setText(QApplication::translate("MainWindow", "\346\210\221\346\230\257\344\270\273\346\222\255", 0));
        lbLiveLogo->setText(QString());
        lbguideLogo->setText(QString());
        lbguide->setText(QApplication::translate("MainWindow", "\346\210\221\346\230\257\350\247\202\344\274\227", 0));
        rbguide->setText(QApplication::translate("MainWindow", "RadioButton", 0));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
