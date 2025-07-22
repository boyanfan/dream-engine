//
// Created by fanboyan on 2025/7/22.
//

#ifndef DREAM_ENGINE_COLOR_H
#define DREAM_ENGINE_COLOR_H

#include "../core/symbols.h"

#include <cstdint>
#include <string>
#include <functional>

namespace DreamEngine {
    /// Represents a color using red, green, blue, and alpha components (RGBA Representation).
    struct Color {
        /// Red, green, blue, and alpha components for the RGBA color representation.
        public: uint8_t red = NONE, green = NONE, blue = NONE, alpha = SOLID_COLOR;

        /// Constructs a color with specified red, green, blue, and alpha values.
        ///
        /// @param red The red value of a color.
        /// @param green The green value of a color.
        /// @param blue The blue value of a color.
        /// @param alpha The alpha value of a color.
        ///
        public: Color(uint8_t red, uint8_t green, uint8_t blue, uint8_t alpha = SOLID_COLOR);

        /// Constructs a Color from a hexadecimal string representation.
        /// @param hexRepresentation A string starting with '#' followed by 6 or 8 hex digits.
        ///
        explicit Color(const std::string& hexRepresentation);

        /// Predefined Dream Engine Colors
        static const Color White;
        static const Color Black;
        static const Color Red;
        static const Color Green;
        static const Color Blue;
    };
}

#endif //DREAM_ENGINE_COLOR_H
