//
// Created by xraw on 25.04.2022.
//

#include "shapecomposite.h"

#include <utility>

namespace Shapes
{

ShapeComposite::ShapeComposite(std::shared_ptr<Shape> s1, std::shared_ptr<Shape> s2, ShapeOperation operation)
: shape1{std::move(s1)}, shape2{std::move(s2)}, operation{operation} {}

bool ShapeComposite::isIn(int x, int y) const {
    if (operation == ShapeOperation::INTERSECTION) {
        return shape1->isIn(x, y) && shape2->isIn(x, y);
    }
    if (operation == ShapeOperation::SUM) {
        return shape1->isIn(x, y) || shape2->isIn(x, y);
    }
    return shape1->isIn(x, y) && !shape2->isIn(x, y);
}

}


