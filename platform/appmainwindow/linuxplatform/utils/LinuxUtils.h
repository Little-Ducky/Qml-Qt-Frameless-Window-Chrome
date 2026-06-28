#ifndef LINUXUTILS_H
#define LINUXUTILS_H

#include "appmainwindow/AppMainWindow.h"

class LinuxUtils
{
public:
    LinuxUtils();

    static Qt::Edges resizeEdges(const QPointF &pos, const QSizeF& size);
};

#endif // LINUXUTILS_H
