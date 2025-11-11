//
// Created by fanboyan on 2025/7/2.
//

#ifndef REVENANTS_BOUNDARY_H
#define REVENANTS_BOUNDARY_H

#include "index.h"

namespace Revenants {
    struct Boundary {
        public: float floorBoundary = 0, ceilingBoundary = 0, leftBoundary = 0, rightBoundary = 0;
        public: Boundary() = default;
        public: Boundary(const float floorBoundary, const float ceilingBoundary, const float leftBoundary, const float rightBoundary)
                : floorBoundary(floorBoundary), ceilingBoundary(ceilingBoundary), leftBoundary(leftBoundary), rightBoundary(rightBoundary) { omitted }
    };
}

#endif //REVENANTS_BOUNDARY_H
