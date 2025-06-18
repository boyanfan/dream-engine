//
// Created by fanboyan on 2025/6/17.
//

#ifndef DREAM_ENGINE_TIMER_H
#define DREAM_ENGINE_TIMER_H

#include "updatable.h"
#include <functional>

namespace DreamEngine {
    /// A utility class to handle timed events in the game. It supports executing a callback function when the timer
    /// time out, and provides functionality to pause, resume, and restart the timer.
    ///
    class Timer final : public Updatable {
        /// The elapsed time, in seconds, since the timer started or was last reset.
        private: float elapsedTime = 0;

        /// The duration of the timer waits, in seconds, before firing the timeout event.
        private: float duration = 0;

        /// Whether the timer is currently paused.
        private: bool hasPaused = false;

        /// Whether the timer has already fired its timeout event in one-shot mode.
        private: bool hasTriggered = false;

        /// Whether the timer is in repeating mode (`true`) or one-shot mode (`false`).
        private: bool isRepeating = false;

        /// The callback function to execute when the timer times out.
        private: std::function<void()> onTimeout;

        /// The default constructor for the Timer class.
        public: Timer() = default;

        /// The default destructor for the Timer class.
        public: ~Timer() override = default;

        /// Restarts the timer by resetting the elapsed time and the has triggered flag.
        public: void restart();

        /// Sets the duration the timer should wait before firing the timeout event.
        /// @param duration The time, in seconds, to wait for triggering the on timeout event.
        ///
        public: void setDuration(float duration);

        /// Sets the callback function to be executed when the timer times out.
        /// @param callback A function with no parameters and no return value to be called upon timeout.
        ///
        public: void setOnTimeout(const std::function<void()>& callback);

        /// Sets whether the timer should repeat after triggering.
        /// @param flag `true` to make the timer repeat; `false` for one-shot behavior.
        ///
        public: void setRepeating(bool flag);

        /// Pauses the timer, halting countdown without resetting the elapsed time.
        public: void pause();

        /// Resumes the timer from where it was paused.
        public: void resume();

        /// Updates the timer based on the time passed since the last update.
        /// This function should be called every frame with the elapsed time. If the timer reaches its duration and is
        /// not paused, it will trigger the callback.
        ///
        /// @param interval Time in seconds since the last update.
        ///
        public: void onUpdate(float interval) override;
    };
}

#endif //DREAM_ENGINE_TIMER_H
