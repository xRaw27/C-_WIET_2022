//
// Created by xraw on 25.04.2022.
//

#ifndef CIRCLE_H
#define CIRCLE_H

#include "shape.h"

namespace Shapes {

class Circle : public Shape {
public:
    Circle(int x0, int y0, int r) : center{x0, y0}, r{r} {}

    int x() const { return center.x_; }
    int y() const { return center.y_; }
    int getRadius() const { return r; }
    bool isIn(int, int) const override;

private:
    const Point center;
    const int r;
};

}

#endif //CIRCLE_H
