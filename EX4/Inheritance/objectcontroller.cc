#include "objectcontroller.hh"
#include <QDebug>

ObjectController::ObjectController()
{
}

ObjectController::~ObjectController()
{

}

void ObjectController::registerObject(std::shared_ptr<MovingObject> mOBj)
{
    moving_objects_.push_back(mOBj);
}

void ObjectController::moveObjects()
{

    for( auto it = moving_objects_.begin();
         it != moving_objects_.end();
         ++it)
    {
        qDebug() << "Moving:" << it->get();
        it->get()->move();
    }
}
