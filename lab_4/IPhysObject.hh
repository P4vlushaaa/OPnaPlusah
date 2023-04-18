
#ifndef LAB_4_IPHYSOBJECT_HH
#define LAB_4_IPHYSOBJECT_HH

#include "Vector2D.hh"

class IPhysObject {
public:
    virtual float mass() = 0;

    virtual Vector2D position() = 0;

    virtual bool operator==(IPhysObject &ob) const = 0;

    virtual bool operator<(IPhysObject &ob) const = 0;
};

#endif //LAB_4_IPHYSOBJECT_HH
