
#ifndef OP4_HEXAGON_H
#define OP4_HEXAGON_H

#include "IGeoFig.hh"
#include "BaseCObject.hh"
#include "Vector2D.hh"
#include "IPrintable.hh"
#include "IPhysObject.hh"

namespace figure {
    class hexagon : public IGeoFig, IPhysObject, IPrintable, BaseCObject {
        Vector2D a, b;
        float m;
    public:
        explicit hexagon(float a_x, float a_y, float b_x, float b_y);

        float mass() override;

        Vector2D position() override;

        float square() override;

        float perimeter() override;

        void draw() override;

        bool operator==(IPhysObject &ob) const override;

        bool operator<(IPhysObject &ob) const override;

        const char *classname() override;

        unsigned int size() override;
    };
}

#endif //LAB_4_HEXAGON_HH
