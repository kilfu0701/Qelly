/*****************************************************************************
 * AbstractConnection.h
 *
 * Created: 05/10 2011 by uranusjr
 *
 * Copyright 2013 uranusjr. All rights reserved.
 *
 * This file may be distributed under the terms of GNU Public License version
 * 3 (GPL v3) as defined by the Free Software Foundation (FSF). A copy of the
 * license should have been included with this file, or the project in which
 * this file belongs to. You may also find the details of GPL v3 at:
 * http://www.gnu.org/licenses/gpl-3.0.txt
 *
 * If you have any questions regarding the use of this file, feel free to
 * contact the author of this file, or the owner of the project in which
 * this file belongs to.
 *****************************************************************************/

#ifndef ABSTRACTCONNECTION_H
#define ABSTRACTCONNECTION_H

#include <QObject>

namespace UJ
{

class Terminal;

namespace Connection
{

class Site;

class AbstractConnection : public QObject
{
    Q_OBJECT

public:
    explicit AbstractConnection(QObject *parent = 0);
    virtual bool connectTo(Site *s);
    virtual bool connectTo(const QString &address, qint16 port) = 0;
    static const qint16 DefaultPort = -1;

public slots:
    virtual void close() = 0;
    virtual void reconnect() = 0;
    virtual void sendBytes(QByteArray bytes) = 0;

protected:
    Site *_site;
    QString _name;
    QString _address;
    // NOTE: Need an image member for tab icon...
    //       Haven't decided which class, maybe QIcon?
    bool _isConnected;
    bool _isProcessing;

protected slots:
    virtual void processBytes(QByteArray bytes) = 0;

signals:
    void connected();
    void disconnected();
    void receivedBytes(QByteArray data);
    void processedBytes(QByteArray bytes);

public: // Getters & Setters
    virtual inline Site *site()
    {
        return _site;
    }
    virtual void setSite(Site *site);
    virtual inline QString name()
    {
        return _name;
    }
    virtual inline void setName(const QString &name)
    {
        _name = name;
    }
    virtual inline QString address()
    {
        return _address;
    }
    virtual inline void setAddress(const QString &address)
    {
        _address = address;
    }
    virtual inline bool isConnected()
    {
        return _isConnected;
    }
    virtual inline void setConnected(bool isConnected)
    {
        // NOTE: Should change the icon image here...
        _isConnected = isConnected;
    }
    virtual inline bool isProcessing()
    {
        return _isProcessing;
    }
    virtual inline void setProcessing(bool isProcessing)
    {
        _isProcessing = isProcessing;
    }
};

}   // namespace Connection

}   // namespace UJ

#endif // ABSTRACTCONNECTION_H
