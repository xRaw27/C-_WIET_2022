//
// Created by xraw on 25.04.2022.
//

#include "circle.h"
#include "cmath"

namespace Shapes {

    bool Circle::isIn(int x, int y) const {
        return sqrt(pow(x - center.x_, 2) + pow(y - center.y_, 2)) <= r;
    }

}