/*****************************************************************************
 * Globals.h
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

#ifndef GLOBALS_H
#define GLOBALS_H

#include <Qt>

namespace UJ
{

enum Modifier
{
#ifdef Q_OS_MAC
    MOD = Qt::META,
    OPT = Qt::ALT
#else
    MOD = Qt::ALT,
    OPT = Qt::META
#endif
};

enum KeyboardModifier
{
// On Macs,
#ifdef Q_OS_MAC
    ModModifier = Qt::ControlModifier
#else
    ModModifier = Qt::AltModifier
#endif
};

// Due to a bug in Qt, cmd and control keys are swapped on Macs even when we
// explicitly disable the swap. We need to swap it back.
enum Key
{
#ifdef Q_OS_MAC
    Key_Mod = Qt::Key_Control,
    Key_Control = Qt::Key_Meta,
    Key_Meta = Qt::Key_Control
#else
    Key_Mod = Qt::Key_Alt,
    Key_Control = Qt::Key_Control,
    Key_Meta = Qt::Key_Meta
#endif
};

namespace Connection
{

enum Type
{
    TypeTelnet,
    TypeSsh,
    TypeUnknown
};

}   // namespace Connection

namespace BBS
{

enum Encoding
{
    EncodingUnknown,
    EncodingBig5,
    EncodingGBK
};

enum AnsiColorKey
{
    ColorKeyCtrlU,
    ColorKeyDoubleEsc
};

enum Size
{
    SizeRowCount = 24,
    SizeColumnCount = 80
};

enum ColorIndex
{
    ColorIndexBackground = 0,
    ColorIndexForeground = 7
};

union CellAttribute
{
    ushort v;
    struct
    {
        uint fColorIndex    : 4;
        uint bColorIndex    : 4;
        uint bright         : 1;
        uint underlined     : 1;
        uint blinking       : 1;
        uint reversed       : 1;
        uint doubleByte     : 2;
        uint isUrl          : 1;
        uint isNothing      : 1;
    } f;
};

struct Cell
{
    uchar byte;
    CellAttribute attr;
};

}   // namespace BBS

}   // namespace UJ

#endif // GLOBALS_H
