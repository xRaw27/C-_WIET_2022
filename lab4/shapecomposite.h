//
// Created by xraw on 25.04.2022.
//

#ifndef SHAPECOMPOSITE_H
#define SHAPECOMPOSITE_H

#include "shape.h"
#include "memory"

namespace Shapes {

class ShapeComposite : public Shape{
public:
    ShapeComposite(std::shared_ptr<Shape>, std::shared_ptr<Shape>, ShapeOperation);
    bool isIn(int, int) const override;

private:
    const std::shared_ptr<Shape> shape1;
    const std::shared_ptr<Shape> shape2;
    const ShapeOperation operation;
};

}

#endif //SHAPECOMPOSITE_H
