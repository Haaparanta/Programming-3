#ifndef MOVINGOBJECTGRAPHICS_HH
#define MOVINGOBJECTGRAPHICS_HH

#include "movingobject.hh"

#include <QGraphicsItem>
#include <memory>

class MovingObjectGraphics : public QGraphicsItem
{
public:
    explicit MovingObjectGraphics(std::shared_ptr<MovingObject> relatedObject,
                                  QGraphicsItem *parent = nullptr);

    void paint(QPainter *painter,
                const QStyleOptionGraphicsItem *option,
                QWidget *widget = nullptr);
    void updatePos();

protected:
    QRectF boundingRect() const;

private:
    std::shared_ptr<MovingObject> relatedObject_;

};

#endif // MOVINGOBJECTGRAPHICS_HH
