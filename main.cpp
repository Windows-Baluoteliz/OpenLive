#include "stdafx.h"
#include "mainwindow.h"
#include "enterroom.h"
#include <QApplication>

CAgoraConfig gAgoraConfig;

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    //MainWindow w;
    //w.show();
    EnterRoom er;
    er.show();

    return a.exec();
}