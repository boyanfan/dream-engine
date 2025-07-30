//
// Created by fanboyan on 2025/7/12.
//

#ifndef DREAM_ENGINE_EDGE_H
#define DREAM_ENGINE_EDGE_H

#include "engine/core.h"

namespace DreamEngine {
    /// Represents the inset distances for the sides of a rectangle, defined by its four edges.
    struct EdgeInsets {
        /// The distance from the leading, top, trailing and bottom edges of a rectangle.
        public: float leading = NONE, top = NONE, trailing = NONE, bottom = NONE;

        /// Constructs an `EdgeInsets` with individually specified values for each edge.
        ///
        /// @param leading The distance from the leading edge.
        /// @param top The distance from the top edge.
        /// @param trailing The distance from the trailing edge.
        /// @param bottom The distance from the bottom edge.
        ///
        public: constexpr EdgeInsets(const float leading, const float top, const float trailing, const float bottom)
        : leading(leading), top(top), trailing(trailing), bottom(bottom) { omitted }

        /// Constructs an `EdgeInsets` where all edges share the same value.
        /// @param all The uniform distance applied to all edges.
        ///
        public: constexpr explicit EdgeInsets(const float all = 0) : leading(all), top(all), trailing(all), bottom(all) { omitted }

        /// Creates an `EdgeInsets` instance with the same value applied to all edges.
        ///
        /// @param all The uniform distance to apply.
        /// @return An `EdgeInsets` with the same value on all sides.
        ///
        public: static EdgeInsets all(const float all) { return EdgeInsets(all); }
    };
}

#endif // DREAM_ENGINE_EDGE_H
