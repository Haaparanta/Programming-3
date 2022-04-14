#include "movingobjectgraphics.hh"
#include <QPainter>
#include <QDebug>

MovingObjectGraphics::MovingObjectGraphics(std::shared_ptr<MovingObject> relatedObject,
                                           QGraphicsItem *parent) :
    QGraphicsItem(parent),
    relatedObject_(relatedObject)
{

}


QRectF MovingObjectGraphics::boundingRect() const
{
    return QRect(0,0,10,10);

}
void MovingObjectGraphics::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
    Q_UNUSED(option);
    Q_UNUSED(widget);
    painter->setPen(Qt::black);
    painter->setBrush(QBrush(Qt::black));
    painter->drawEllipse( 0, 0, 10, 10 );
}

void MovingObjectGraphics::updatePos()
{
    int x = relatedObject_->getX();
    int y = relatedObject_->getY();
    setPos(x, y);
}

