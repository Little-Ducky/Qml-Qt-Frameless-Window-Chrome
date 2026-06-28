#ifndef MACUTILS_H
#define MACUTILS_H

#include <QObject>
#include <QPointF>
#include <QSize>

class MacUtils
{
public:
    MacUtils();

    static bool isInResizeArea(const QPointF& p, const QSizeF& size);
};

#endif // MACUTILS_H
