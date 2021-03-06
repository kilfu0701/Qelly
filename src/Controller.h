/*****************************************************************************
 * Controller.h
 *
 * Created: 09/10 2011 by uranusjr
 *
 * Copyright 2011 uranusjr. All rights reserved.
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

#ifndef CONTROLLER_H
#define CONTROLLER_H

#include <QObject>
#include <QPointer>

namespace UJ
{

namespace Qelly
{

class MainWindow;
class PreferencesWindow;
class View;

class Controller : public QObject
{
    Q_OBJECT

public:
    explicit Controller(QObject *parent = 0);
    virtual ~Controller();

public slots:
    void connectWithAddress(QString address);
    void focusAddressField();
    void addTab();
    void closeTab();
    void closeTab(int index);
    void closeWindow();
    void copy();
    void paste();
    void pasteColor();
    void onAddressReturnPressed();
    void changeAddressField(const QString &address);
    void showPreferencesWindow();

private slots:
    void updateAll();

private:
    View *currentView() const;
    View *viewInTab(int index) const;
    MainWindow *_window;
    QPointer<PreferencesWindow> _preferencesWindow;
};

}   // namespace Qelly

}   // namespace UJ

#endif // CONTROLLER_H
