#ifndef CHAT_H
#define CHAT_H

#include <QMainWindow>
#include <QTcpServer>
#include <QTcpSocket>

namespace Ui {
class chat;
}

class chat : public QMainWindow
{
    Q_OBJECT

public:
    explicit chat(QWidget *parent = nullptr);
    ~chat();

private slots:
    void newConnection();
    void readyRead();
    void sendMessage();
    void clearChat();

private:
    Ui::chat *ui;
    QTcpServer *tcpServer;
    QTcpSocket *clientSocket;
};

#endif // MAINWINDOW_H


