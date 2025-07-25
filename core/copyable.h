//
// Created by fanboyan on 2025/6/5.
//

#ifndef DREAM_ENGINE_COPYABLE_H
#define DREAM_ENGINE_COPYABLE_H

#include "symbols.h"

namespace DreamEngine {
    /// The standard interface for creating deep or customized copies of engine objects.
    /// Implementing classes must define the `copy()` method with precise control over which should be duplicated.
    ///
    interface Copyable {
        /// Requires the conforming types to implement the appropriate destructor.
        public: virtual ~Copyable() = default;

        /// Creates a copy of the object. The exact behavior is defined by the implementing class.
        /// @return A new dynamically allocated instance with copied data.
        ///
        public: virtual Copyable* copy() const = delegated;
    };
}

#endif //DREAM_ENGINE_COPYABLE_H
