#include "stdafx.h"
#include "inroom.h"
#include "ui_inroom.h"
#include "agoraobject.h"

InRoom::InRoom(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::InRoom)
{
    ui->setupUi(this);
    this->setWindowFlags(Qt::FramelessWindowHint | Qt::WindowSystemMenuHint | Qt::WindowMinMaxButtonsHint);
    //this->setAttribute(Qt::WA_TranslucentBackground);
}

InRoom::~InRoom()
{
    delete ui;
}

void InRoom::mousePressEvent(QMouseEvent *e)
{
    if(e->button() == Qt::LeftButton) {
        m_mousePosition = e->pos();
        if(m_mousePosition.x() < lnTitleWidth &&
           m_mousePosition.y() < lnTitleHeight)
            m_bMousePressed = true;
    }
}

void InRoom::mouseMoveEvent(QMouseEvent *e)
{
    if(m_bMousePressed == true) {
        QPoint movePos = e->globalPos() - m_mousePosition;
        move(movePos);
        e->accept();
    }
}

void InRoom::mouseReleaseEvent(QMouseEvent *e)
{
   m_bMousePressed = false;
}

void InRoom::joinchannel(const QString& qsChannel,uint uid)
{
    qDebug(__FUNCTION__);
    this->show();

    CAgoraObject::getInstance()->LocalVideoPreview((HWND)winId(),TRUE);
    CAgoraObject::getInstance()->joinChannel("",qsChannel,uid);
}

void InRoom::leavechannel()
{
    qDebug(__FUNCTION__);
    CAgoraObject::getInstance()->leaveChannel();
}
