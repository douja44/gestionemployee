// chat.cpp
#include "chat.h"
#include "ui_chat.h"


chat::chat(QWidget *parent)
    : QMainWindow(parent),
      ui(new Ui::chat),
      tcpServer(new QTcpServer(this)),
      clientSocket(nullptr)
{
    ui->setupUi(this);


    connect(tcpServer, &QTcpServer::newConnection, this, &chat::newConnection);

    if (!tcpServer->listen(QHostAddress::Any, 12345)) {
        qDebug() << "Server could not start!";
    } else {
        qDebug() << "Server started on port 12345.";
    }
    connect(ui->sendButton, &QPushButton::clicked, this, &chat::sendMessage);
    connect(ui->clearButton, &QPushButton::clicked, this, &chat::clearChat);
}

chat::~chat()
{
    delete ui;
}

void chat::newConnection()
{
    if (tcpServer->hasPendingConnections()) {
        clientSocket = tcpServer->nextPendingConnection();
        connect(clientSocket, &QTcpSocket::readyRead, this, &chat::readyRead);
    }
}

void chat::readyRead()
{
    if (clientSocket->canReadLine()) {
        QString message = QString::fromUtf8(clientSocket->readAll().trimmed());
        ui->textEdit->append("Received: " + message);
    }
}

void chat::sendMessage()
{
    if (clientSocket && clientSocket->state() == QAbstractSocket::ConnectedState) {
        QString message = ui->lineEdit->text();
        ui->lineEdit->clear();
        clientSocket->write(message.toUtf8() + '\n');
        ui->textEdit->append("Sent: " + message);
    }
}

void chat::clearChat()
{
    ui->textEdit->clear();
}
