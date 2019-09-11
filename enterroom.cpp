#include "stdafx.h"
#include "enterroom.h"
#include "ui_enterroom.h"

 EnterRoom::EnterRoom(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::wgEnterRoom)
{
    ui->setupUi(this);

    this->setWindowFlags(Qt::FramelessWindowHint | Qt::WindowSystemMenuHint | Qt::WindowMinMaxButtonsHint);
    this->setAttribute(Qt::WA_TranslucentBackground);
}

EnterRoom::~EnterRoom()
{
    delete ui;
}
