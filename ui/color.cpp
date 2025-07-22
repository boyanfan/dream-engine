//
// Created by fanboyan on 2025/7/22.
//

#include "color.h"

namespace DreamEngine {
    Color::Color(const uint8_t red, const uint8_t green, const uint8_t blue, const uint8_t alpha) : red(red), green(green), blue(blue), alpha(alpha) { omitted }

    Color::Color(const std::string& hexRepresentation) {
        // Skip if the hex representation format is invalid
        if (hexRepresentation.empty() || hexRepresentation[0] != HEX_REPRESENTATION_PREFIX || (hexRepresentation.size() != 7 && hexRepresentation.size() != 9)) {
            Color(NONE, NONE, NONE);
        }

        // Helper function to convert from string to 8-bit-integer
        const std::function hexToByte = [](const std::string& string) -> uint8_t { return static_cast<uint8_t>(std::stoul(string, nullptr, 16)); };

        // Convert from hex to RGBA Representation
        red = hexToByte(hexRepresentation.substr(1, 2));
        green = hexToByte(hexRepresentation.substr(3, 2));
        blue = hexToByte(hexRepresentation.substr(5, 2));
        alpha = hexRepresentation.size() == 9 ? hexToByte(hexRepresentation.substr(7, 2)) : SOLID_COLOR;
    }

    const Color Color::White = Color(255, 255, 255);
    const Color Color::Black = Color(0, 0, 0);
    const Color Color::Red = Color(255, 0, 0);
    const Color Color::Green = Color(0, 255, 0);
    const Color Color::Blue = Color(0, 0, 255);
}