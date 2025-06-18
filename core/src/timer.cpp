//
// Created by fanboyan on 2025/6/17.
//

#include "timer.h"

namespace DreamEngine {
    void Timer::restart() { elapsedTime = 0; isRepeating = false; }

    void Timer::setDuration(const float duration) { this->duration = duration; }

    void Timer::setRepeating(const bool flag) { isRepeating = flag; }

    void Timer::setOnTimeout(const std::function<void()>& callback) { onTimeout = callback; }

    void Timer::pause() { hasPaused = true; }

    void Timer::resume() { hasPaused = false; }

    void Timer::onUpdate(const float interval) {
        // Do nothing if the timer is currently paused
        if (hasPaused) return;

        // Accumulate the elapsed time since the last update
        elapsedTime += interval;

        // Check whether the accumulated time has reached or surpassed the set duration,
        // use a loop to handle cases where `interval` is large enough to trigger multiple times
        while (elapsedTime >= duration) {
            // Determine if the timer is allowed to trigger: it must not have triggered, or it is a repeating timer
            const bool canTrigger = (!hasTriggered || isRepeating);

            // If triggering is allowed and a timeout callback is set, invoke it
            if (canTrigger && onTimeout) onTimeout();

            // If the timer is not repeating, set hasTriggered and break out of the loop, since
            // we only want to trigger once for non-repeating timers
            if (!isRepeating) {
                hasTriggered = true;
                break;
            }

            // For repeating timers, subtract one full duration and allow the loop to continue, which
            // handles cases where multiple durations have passed within one update
            elapsedTime -= duration;
            hasTriggered = true;
        }
    }
}
