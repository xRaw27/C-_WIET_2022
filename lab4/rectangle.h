//
// Created by xraw on 25.04.2022.
//

#ifndef RECTANGLE_H
#define RECTANGLE_H

#include "shape.h"

namespace Shapes {

class Rectangle : public Shape {
public:
    Rectangle(int x1, int y1, int x2, int y2) : from{x1, y1}, to{x2, y2} {}

    int x() const { return from.x_; }
    int y() const { return from.y_; }
    int xTo() const { return to.x_; }
    int yTo() const { return to.y_; }
    bool isIn(int, int) const override;

private:
    const Point from, to;
};

}

#endif //RECTANGLE_H
