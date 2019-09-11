/********************************************************************************
** Form generated from reading UI file 'roomsettings.ui'
**
** Created by: Qt User Interface Compiler version 5.6.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_ROOMSETTINGS_H
#define UI_ROOMSETTINGS_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_roomsettings
{
public:
    QWidget *centralwidget;
    QPushButton *btnlastpage;
    QPushButton *optVideo;
    QPushButton *optAudio;
    QComboBox *cbVideoProfile;
    QComboBox *cbRecordDevices;
    QComboBox *cbPlayDevices;
    QComboBox *cbVideoDevices;
    QLabel *lbName;

    void setupUi(QMainWindow *roomsettings)
    {
        if (roomsettings->objectName().isEmpty())
            roomsettings->setObjectName(QStringLiteral("roomsettings"));
        roomsettings->resize(736, 536);
        roomsettings->setMouseTracking(true);
        roomsettings->setStyleSheet(QStringLiteral(""));
        centralwidget = new QWidget(roomsettings);
        centralwidget->setObjectName(QStringLiteral("centralwidget"));
        centralwidget->setStyleSheet(QStringLiteral("background-image: url(:/uiresource/pic-win03.png);"));
        btnlastpage = new QPushButton(centralwidget);
        btnlastpage->setObjectName(QStringLiteral("btnlastpage"));
        btnlastpage->setGeometry(QRect(389, 31, 30, 30));
        btnlastpage->setStyleSheet(QLatin1String("QPushButton:!hover{\n"
"border-image: url(:/uiresource/icon-back.png);\n"
"background-image: url(:/uiresource/icon-back.png);\n"
"}\n"
"\n"
"QPushButton:hover{\n"
"border-image: url(:/uiresource/icon-back hover.png);\n"
"background-image: url(:/uiresource/icon-back hover.png);\n"
"}\n"
"\n"
"QPushButton:pressed{\n"
"border-image: url(:/uiresource/icon-back.png);\n"
"background-image: url(:/uiresource/icon-back.png);\n"
"}"));
        optVideo = new QPushButton(centralwidget);
        optVideo->setObjectName(QStringLiteral("optVideo"));
        optVideo->setGeometry(QRect(647, 344, 50, 30));
        optVideo->setStyleSheet(QLatin1String("QPushButton:!hover {\n"
"border-image: url(:/uiresource/switch-off.png);\n"
"background-image: url(:/uiresource/switch-off.png);\n"
"}\n"
"\n"
"QPushButton:hover {\n"
"border-image: url(:/uiresource/switch-off.png);\n"
"background-image: url(:/uiresource/switch-off.png);\n"
"}"));
        optVideo->setCheckable(false);
        optAudio = new QPushButton(centralwidget);
        optAudio->setObjectName(QStringLiteral("optAudio"));
        optAudio->setGeometry(QRect(647, 300, 50, 30));
        optAudio->setStyleSheet(QLatin1String("QPushButton:!hover {\n"
"border-image: url(:/uiresource/switch-off.png);\n"
"background-image: url(:/uiresource/switch-off.png);\n"
"}\n"
"\n"
"QPushButton:hover {\n"
"border-image: url(:/uiresource/switch-off.png);\n"
"background-image: url(:/uiresource/switch-off.png);\n"
"}"));
        cbVideoProfile = new QComboBox(centralwidget);
        cbVideoProfile->setObjectName(QStringLiteral("cbVideoProfile"));
        cbVideoProfile->setGeometry(QRect(503, 122, 194, 32));
        cbVideoProfile->setStyleSheet(QString::fromUtf8("QComboBox {\n"
"font-family: \"\345\276\256\350\275\257\351\233\205\351\273\221\"; \n"
"font-size: 13px; \n"
"padding: 3px 0x 3px 5px;\n"
"border-image: url(:/uiresource/box-01.png);\n"
"}\n"
"\n"
"QComboBox:hover {\n"
"font-family: \"\345\276\256\350\275\257\351\233\205\351\273\221\"; \n"
"font-size: 13px; \n"
"padding: 3px 0x 3px 5px;\n"
"border-image: url(:/uiresource/box-02.png);\n"
"}\n"
"\n"
"QComboBox:pressed {\n"
"font-family: \"\345\276\256\350\275\257\351\233\205\351\273\221\"; \n"
"font-size: 13px; \n"
"padding: 3px 0x 3px 5px;\n"
"border-image: url(:/uiresource/box-03.png);\n"
"}\n"
"\n"
"QComboBox::drop-down {\n"
"subcontrol-origin: padding; \n"
"subcontrol-position: top right; width: 30 px; \n"
"border: 0px;\n"
"}\n"
"\n"
"QComboBox::down-arrow::!on {\n"
"image: url(:/uiresource/dropdow-01.png);\n"
"}\n"
"QComboBox::down-arrow::hover {\n"
"image: url(:/uiresource/dropdown-02.png);\n"
"}\n"
"QComboBox::down-arrow::on {\n"
"image: url(:/uiresource/dropdown-03.png);\n"
"}\n"
"\n"
"QListView {\n"
"fo"
                        "nt-family: \"\345\276\256\350\275\257\351\233\205\351\273\221\"; \n"
"font-size: 13px; \n"
"outline: 0px;\n"
"background-image: url(:/uiresource/list.png);\n"
"border-image: url(:/uiresource/list.png);\n"
"image: url(:/uiresource/list.png);\n"
"}\n"
"\n"
"QListView::item {\n"
"padding: 3px 0x 3px 5px; \n"
"border-width: 0px;\n"
"}\n"
"\n"
"QListView::item:selected {\n"
"background-color: rgb(74, 144, 226);\n"
"}"));
        cbRecordDevices = new QComboBox(centralwidget);
        cbRecordDevices->setObjectName(QStringLiteral("cbRecordDevices"));
        cbRecordDevices->setGeometry(QRect(503, 166, 194, 32));
        cbRecordDevices->setStyleSheet(QString::fromUtf8("QComboBox {\n"
"font-family: \"\345\276\256\350\275\257\351\233\205\351\273\221\"; \n"
"font-size: 13px; \n"
"padding: 3px 0x 3px 5px;\n"
"border-image: url(:/uiresource/box-01.png);\n"
"}\n"
"\n"
"QComboBox:hover {\n"
"font-family: \"\345\276\256\350\275\257\351\233\205\351\273\221\"; \n"
"font-size: 13px; \n"
"padding: 3px 0x 3px 5px;\n"
"border-image: url(:/uiresource/box-02.png);\n"
"}\n"
"\n"
"QComboBox:pressed {\n"
"font-family: \"\345\276\256\350\275\257\351\233\205\351\273\221\"; \n"
"font-size: 13px; \n"
"padding: 3px 0x 3px 5px;\n"
"border-image: url(:/uiresource/box-03.png);\n"
"}\n"
"\n"
"QComboBox::drop-down {\n"
"subcontrol-origin: padding; \n"
"subcontrol-position: top right; width: 30 px; \n"
"border: 0px;\n"
"}\n"
"\n"
"QComboBox::down-arrow::!on {\n"
"image: url(:/uiresource/dropdow-01.png);\n"
"}\n"
"QComboBox::down-arrow::hover {\n"
"image: url(:/uiresource/dropdown-02.png);\n"
"}\n"
"QComboBox::down-arrow::on {\n"
"image: url(:/uiresource/dropdown-03.png);\n"
"}\n"
"\n"
"QListView {\n"
"fo"
                        "nt-family: \"\345\276\256\350\275\257\351\233\205\351\273\221\"; \n"
"font-size: 13px; \n"
"outline: 0px;\n"
"background-image: url(:/uiresource/list.png);\n"
"border-image: url(:/uiresource/list.png);\n"
"image: url(:/uiresource/list.png);\n"
"}\n"
"\n"
"QListView::item {\n"
"padding: 3px 0x 3px 5px; \n"
"border-width: 0px;\n"
"}\n"
"\n"
"QListView::item:selected {\n"
"background-color: rgb(74, 144, 226);\n"
"}"));
        cbPlayDevices = new QComboBox(centralwidget);
        cbPlayDevices->setObjectName(QStringLiteral("cbPlayDevices"));
        cbPlayDevices->setGeometry(QRect(503, 255, 194, 32));
        cbPlayDevices->setStyleSheet(QString::fromUtf8("QComboBox {\n"
"font-family: \"\345\276\256\350\275\257\351\233\205\351\273\221\"; \n"
"font-size: 13px; \n"
"padding: 3px 0x 3px 5px;\n"
"border-image: url(:/uiresource/box-01.png);\n"
"}\n"
"\n"
"QComboBox:hover {\n"
"font-family: \"\345\276\256\350\275\257\351\233\205\351\273\221\"; \n"
"font-size: 13px; \n"
"padding: 3px 0x 3px 5px;\n"
"border-image: url(:/uiresource/box-02.png);\n"
"}\n"
"\n"
"QComboBox:pressed {\n"
"font-family: \"\345\276\256\350\275\257\351\233\205\351\273\221\"; \n"
"font-size: 13px; \n"
"padding: 3px 0x 3px 5px;\n"
"border-image: url(:/uiresource/box-03.png);\n"
"}\n"
"\n"
"QComboBox::drop-down {\n"
"subcontrol-origin: padding; \n"
"subcontrol-position: top right; width: 30 px; \n"
"border: 0px;\n"
"}\n"
"\n"
"QComboBox::down-arrow::!on {\n"
"image: url(:/uiresource/dropdow-01.png);\n"
"}\n"
"QComboBox::down-arrow::hover {\n"
"image: url(:/uiresource/dropdown-02.png);\n"
"}\n"
"QComboBox::down-arrow::on {\n"
"image: url(:/uiresource/dropdown-03.png);\n"
"}\n"
"\n"
"QListView {\n"
"fo"
                        "nt-family: \"\345\276\256\350\275\257\351\233\205\351\273\221\"; \n"
"font-size: 13px; \n"
"outline: 0px;\n"
"background-image: url(:/uiresource/list.png);\n"
"border-image: url(:/uiresource/list.png);\n"
"image: url(:/uiresource/list.png);\n"
"}\n"
"\n"
"QListView::item {\n"
"padding: 3px 0x 3px 5px; \n"
"border-width: 0px;\n"
"}\n"
"\n"
"QListView::item:selected {\n"
"background-color: rgb(74, 144, 226);\n"
"}"));
        cbVideoDevices = new QComboBox(centralwidget);
        cbVideoDevices->setObjectName(QStringLiteral("cbVideoDevices"));
        cbVideoDevices->setGeometry(QRect(503, 210, 194, 32));
        cbVideoDevices->setStyleSheet(QString::fromUtf8("QComboBox {\n"
"font-family: \"\345\276\256\350\275\257\351\233\205\351\273\221\"; \n"
"font-size: 13px; \n"
"padding: 3px 0x 3px 5px;\n"
"border-image: url(:/uiresource/box-01.png);\n"
"}\n"
"\n"
"QComboBox:hover {\n"
"font-family: \"\345\276\256\350\275\257\351\233\205\351\273\221\"; \n"
"font-size: 13px; \n"
"padding: 3px 0x 3px 5px;\n"
"border-image: url(:/uiresource/box-02.png);\n"
"}\n"
"\n"
"QComboBox:pressed {\n"
"font-family: \"\345\276\256\350\275\257\351\233\205\351\273\221\"; \n"
"font-size: 13px; \n"
"padding: 3px 0x 3px 5px;\n"
"border-image: url(:/uiresource/box-03.png);\n"
"}\n"
"\n"
"QComboBox::drop-down {\n"
"subcontrol-origin: padding; \n"
"subcontrol-position: top right; width: 30 px; \n"
"border: 0px;\n"
"}\n"
"\n"
"QComboBox::down-arrow::!on {\n"
"image: url(:/uiresource/dropdow-01.png);\n"
"}\n"
"QComboBox::down-arrow::hover {\n"
"image: url(:/uiresource/dropdown-02.png);\n"
"}\n"
"QComboBox::down-arrow::on {\n"
"image: url(:/uiresource/dropdown-03.png);\n"
"}\n"
"\n"
"QListView {\n"
"fo"
                        "nt-family: \"\345\276\256\350\275\257\351\233\205\351\273\221\"; \n"
"font-size: 13px; \n"
"outline: 0px;\n"
"background-image: url(:/uiresource/list.png);\n"
"border-image: url(:/uiresource/list.png);\n"
"image: url(:/uiresource/list.png);\n"
"}\n"
"\n"
"QListView::item {\n"
"padding: 3px 0x 3px 5px; \n"
"border-width: 0px;\n"
"}\n"
"\n"
"QListView::item:selected {\n"
"background-color: rgb(74, 144, 226);\n"
"}"));
        lbName = new QLabel(centralwidget);
        lbName->setObjectName(QStringLiteral("lbName"));
        lbName->setGeometry(QRect(600, 87, 97, 16));
        QFont font;
        font.setFamily(QString::fromUtf8("\345\271\274\345\234\206"));
        font.setBold(true);
        font.setWeight(75);
        lbName->setFont(font);
        lbName->setStyleSheet(QLatin1String("QLabel{\n"
"	background-image: url(:/uiresource/white.png);\n"
"	color:#666666;\n"
"}"));
        lbName->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);
        roomsettings->setCentralWidget(centralwidget);

        retranslateUi(roomsettings);

        QMetaObject::connectSlotsByName(roomsettings);
    } // setupUi

    void retranslateUi(QMainWindow *roomsettings)
    {
        roomsettings->setWindowTitle(QApplication::translate("roomsettings", "MainWindow", 0));
        btnlastpage->setText(QString());
        optVideo->setText(QString());
        optAudio->setText(QString());
        lbName->setText(QApplication::translate("roomsettings", "TextLabel", 0));
    } // retranslateUi

};

namespace Ui {
    class roomsettings: public Ui_roomsettings {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_ROOMSETTINGS_H
