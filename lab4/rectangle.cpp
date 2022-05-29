//
// Created by xraw on 25.04.2022.
//

#include "rectangle.h"

namespace Shapes {

bool Rectangle::isIn(int x, int y) const {
    return x >= from.x_ && x <= to.x_ && y >= from.y_ && y <= to.y_;
}

}