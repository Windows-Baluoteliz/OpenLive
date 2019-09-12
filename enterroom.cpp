#include "stdafx.h"
#include "enterroom.h"
#include "ui_enterroom.h"
#include "agoraobject.h"
#include "qgraphicseffect.h"

 EnterRoom::EnterRoom(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::wgEnterRoom),
    m_pLastWnd(Q_NULLPTR)
{
    ui->setupUi(this);

    this->setWindowFlags(Qt::FramelessWindowHint | Qt::WindowSystemMenuHint |
                         Qt::WindowMinMaxButtonsHint | Qt::WindowStaysOnTopHint);
    this->setAttribute(Qt::WA_TranslucentBackground);
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

void EnterRoom::joinchannel(QMainWindow* pLastWnd,const QString& qsChannel,uint uid)
{
    qDebug(__FUNCTION__);
    m_pLastWnd = pLastWnd;
    ui->lbChannel->setText(qsChannel);
    this->show();
}

void EnterRoom::leavechannel()
{
    qDebug(__FUNCTION__);
}

void EnterRoom::setChannelName(const QString& qsChannel,uint uid)
{
    QString qsParam(qsChannel);
    qsParam.append(" ");
    qsParam.append(QString::number(uid));
    ui->lbChannel->setText(qsParam);
}

void EnterRoom::setParam(const QString& qsParam)
{
    ui->lbParam->setText(qsParam);
}

void EnterRoom::on_btnExit_clicked()
{
    connect(this,SIGNAL(sender_exitChannel()),m_pLastWnd,SLOT(receive_exitChannel()));
    emit sender_exitChannel();
    this->hide();
}

void EnterRoom::on_rbCamera_stateChanged(int arg1)
{
    if(arg1 == Qt::Unchecked)
        CAgoraObject::getInstance()->MuteLocalVideo(FALSE);
    else if(arg1 == Qt::Checked)
        CAgoraObject::getInstance()->MuteLocalVideo(TRUE);
}

void EnterRoom::on_rbMic_stateChanged(int arg1)
{
    if(arg1 == Qt::Unchecked)
        CAgoraObject::getInstance()->MuteLocalAudio(FALSE);
    else if(arg1 == Qt::Checked)
        CAgoraObject::getInstance()->MuteLocalAudio(TRUE);
}
