#include "LinuxPlatform.h"

LinuxPlatform::LinuxPlatform(QWindow *parent)
    : AppMainWindow(parent)
{

}

bool LinuxPlatform::nativeEvent(const QByteArray& eventType,
                                void *message,
                                qintptr *result)
{
    return QQuickWindow::nativeEvent(eventType, message, result);
}

bool LinuxPlatform::event(QEvent *e)
{
    switch (e->type())
    {
    case QEvent::MouseMove:
    {
        auto *me = static_cast<QMouseEvent *>(e);

        const Qt::Edges edges = resizeEdges(me->position());

        if (edges == (Qt::LeftEdge | Qt::TopEdge) ||
            edges == (Qt::RightEdge | Qt::BottomEdge))
        {
            setCursor(Qt::SizeFDiagCursor);
            me->accept();
            return true;
        }

        if (edges == (Qt::RightEdge | Qt::TopEdge) ||
            edges == (Qt::LeftEdge | Qt::BottomEdge))
        {
            setCursor(Qt::SizeBDiagCursor);
            me->accept();
            return true;
        }

        if (edges & (Qt::LeftEdge | Qt::RightEdge))
        {
            setCursor(Qt::SizeHorCursor);
            me->accept();
            return true;
        }

        if (edges & (Qt::TopEdge | Qt::BottomEdge))
        {
            setCursor(Qt::SizeVerCursor);
            me->accept();
            return true;
        }

        unsetCursor();
        break;
    }

    case QEvent::MouseButtonPress:
    {
        auto *me = static_cast<QMouseEvent *>(e);

        if (me->button() != Qt::LeftButton)
            break;

        const Qt::Edges edges = resizeEdges(me->position());

        if (edges)
        {
            startSystemResize(edges);
            me->accept();
            return true;
        }

        const QPointF pt = me->position();

        if (pt.y() < m_appCaption->height() &&
            !m_appCaption->findInteractiveAt(
                contentItem(),
                pt.toPoint()))
        {
            startSystemMove();
            me->accept();
            return true;
        }

        break;
    }

    case QEvent::MouseButtonDblClick:
    {
        auto *me = static_cast<QMouseEvent *>(e);

        const Qt::Edges edges = resizeEdges(me->position());

        if (edges)
        {
            me->accept();
            return true;
        }

        const QPointF pt = me->position();

        if (me->button() == Qt::LeftButton &&
            pt.y() < m_appCaption->height() &&
            !m_appCaption->findInteractiveAt(
                contentItem(),
                pt.toPoint()))
        {
            m_appWindowController->toggleMaximized();
            me->accept();
            return true;
        }

        break;
    }

    default:
        break;
    }

    return QQuickWindow::event(e);
}
Qt::Edges LinuxPlatform::resizeEdges(const QPointF &pos) const
{
    constexpr qreal border = 8.0;

    Qt::Edges edges;

    if (pos.x() <= border)
        edges |= Qt::LeftEdge;

    if (pos.x() >= width() - border)
        edges |= Qt::RightEdge;

    if (pos.y() <= border)
        edges |= Qt::TopEdge;

    if (pos.y() >= height() - border)
        edges |= Qt::BottomEdge;

    return edges;
}
void LinuxPlatform::setup()
{
    setFlags(Qt::Window | Qt::FramelessWindowHint);

    const QRect screenGeometry =
        screen()->availableGeometry();

    setPosition(
        screenGeometry.x()
            + (screenGeometry.width() - width()) / 2,
        screenGeometry.y()
            + (screenGeometry.height() - height()) / 2);
}