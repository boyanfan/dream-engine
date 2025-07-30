//
// Created by fanboyan on 2025/7/22.
//

#ifndef DREAM_ENGINE_VIEW_H
#define DREAM_ENGINE_VIEW_H

#include "engine/core.h"

namespace DreamEngine {
    /// The standard interface for a basic UI element that can be updated and rendered by confirming to
    /// Updatable and Renderable interfaces. It represents a rectangular component in a user interface,
    /// supporting both visibility toggling and spatial configuration through a frame.
    ///
    interface View : public Updatable, public Renderable {
        /// The bounding rectangle of the view in floating-point coordinates.
        public: SDL_FRect frame = { NONE, NONE, NONE, NONE };

        /// Determines whether the view should be rendered.
        public: bool isVisible = true;

        /// Virtual destructor for safe inheritance.
        public: ~View() override = default;
    };
}

#endif //DREAM_ENGINE_VIEW_H
