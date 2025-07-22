//
// Created by fanboyan on 2025/7/7.
//

#ifndef DREAM_ENGINE_MATHEMATICS_H
#define DREAM_ENGINE_MATHEMATICS_H

#include <functional>

namespace DreamEngine {
    /// A utility struct that provides mathematical operations and interpolation methods  for a generic type `T`, where
    /// the type of values this mathematics struct operates on. Typically, it supports arithmetic operations
    /// like addition, subtraction, and scalar multiplication.
    ///
    template<typename T> struct Mathematics {
        /// A type alias representing an easing or transformation curve function.
        public: using Curve = std::function<float(float)>;

        /// Performs linear interpolation between `start` and `end` based on the given `interval` and modified by a
        /// custom `curve`.
        ///
        /// @param start The starting value of type `T`.
        /// @param end The ending value of type `T`.
        /// @param interval A float indicating interpolation progress.
        /// @param curve A custom function to transform the interpolation interval.
        /// @returns The interpolated value of type `T`.
        ///
        public: static T lerp(const T& start, const T& end, const float interval, const Curve& curve) {
            float time = std::clamp(curve(interval), 0.0f, 1.0f);
            return start + (end - start) * time;
        }

        /// Returns the linear interpolation value.
        ///
        /// @param time The time progress.
        /// @return The same value.
        ///
        public: static float linear(const float time) { return time; }

        /// Returns the eased-in curve value using a quadratic curve. It starts slowly and speeds up toward the end.
        ///
        /// @param time The time progress.
        /// @return The eased-in value.
        ///
        public: static float easeIn(const float time) { return time * time; }

        /// Returns the eased-out value using a quadratic curve. It starts quickly and decelerates toward the end.
        ///
        /// @param time The time progress.
        /// @return The eased-in value.
        ///
        public: static float easeOut(const float time) { return 1.0f - easeIn(1.0f - time); }

        /// Returns the eased-in-out value using a smooth curve. It starts slowly, speeds up in the middle,
        /// then slows down toward the end.
        ///
        /// @param time The time progress.
        /// @return The eased-in-out value.
        ///
        public: static float easeInOut(const float time) {
            const float easedInValue = easeIn(time);
            const float easedOutValue = easeOut(time);
            return Mathematics<float>::lerp(easedInValue, easedOutValue, time, linear);
        }
    };
}

#endif //DREAM_ENGINE_MATHEMATICS_H
