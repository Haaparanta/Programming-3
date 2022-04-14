#ifndef OBJECTCONTROLLER_HH
#define OBJECTCONTROLLER_HH

#include "movingobject.hh"
#include "constants.hh"

#include <vector>
#include <memory>
#include <QString>

enum ObjectType {FASTBALL, ODDBALL, END};
const std::vector<QString> OBJECT_TYPE_LABELS = {
    "Fast Ball", "Odd Ball"
};

class ObjectController
{
public:
    ObjectController();
    ~ObjectController();

    void registerObject(std::shared_ptr<MovingObject> mOBj);
    void moveObjects();


private:

    std::vector<std::shared_ptr<MovingObject> > moving_objects_;

};

#endif // OBJECTCONTROLLER_HH
