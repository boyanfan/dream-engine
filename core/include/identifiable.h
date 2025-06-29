//
// Created by fanboyan on 2025/6/29.
//

#ifndef DREAM_ENGINE_IDENTIFIABLE_H
#define DREAM_ENGINE_IDENTIFIABLE_H

#include "symbols.h"

namespace DreamEngine {
    /// The standard interface for objects that can be uniquely identified by providing an arbitrary identifier.
    /// The type of the Identifier is also arbitrary.
    ///
    template<typename ID> interface Identifiable {
        /// Virtual destructor to ensure proper cleanup of derived classes.
        public: virtual ~Identifiable() = default;

        /// Returns the unique identifier of the object.
        public: virtual ID getIdentifier() const = delegated;
    };
}

#endif //DREAM_ENGINE_IDENTIFIABLE_H
