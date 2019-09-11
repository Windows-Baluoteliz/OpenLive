#include "stdafx.h"
#include "enterroom.h"
#include "ui_enterroom.h"
#include "agoraobject.h"

 EnterRoom::EnterRoom(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::wgEnterRoom)
{
    ui->setupUi(this);

    this->setWindowFlags(Qt::FramelessWindowHint | Qt::WindowSystemMenuHint | Qt::WindowMinMaxButtonsHint);
    //this->setAttribute(Qt::WA_TranslucentBackground);
}

EnterRoom::~EnterRoom()
{
    delete ui;
}

void EnterRoom::mousePressEvent(QMouseEvent *e)
{
    if(e->button() == Qt::LeftButton) {
        m_mousePosition = e->pos();
        if(m_mousePosition.x() < lnTitleWidth &&
           m_mousePosition.y() < lnTitleHeight)
            m_bMousePressed = true;
    }
}

void EnterRoom::mouseMoveEvent(QMouseEvent *e)
{
    if(m_bMousePressed == true) {
        QPoint movePos = e->globalPos() - m_mousePosition;
        move(movePos);
        e->accept();
    }
}

void EnterRoom::mouseReleaseEvent(QMouseEvent *e)
{
   m_bMousePressed = false;
}

void EnterRoom::joinchannel(const QString& qsChannel,uint uid)
{
    qDebug(__FUNCTION__);
    this->show();

    CAgoraObject::getInstance()->LocalVideoPreview((HWND)winId(),TRUE);
    CAgoraObject::getInstance()->joinChannel("",qsChannel,uid);
}

void EnterRoom::leavechannel()
{
    qDebug(__FUNCTION__);
    CAgoraObject::getInstance()->leaveChannel();
}
