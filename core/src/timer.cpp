//
// Created by fanboyan on 2025/6/17.
//

#include "timer.h"

namespace DreamEngine {
    void Timer::restart() { elapsedTime = 0; hasTriggered = false; }

    void Timer::setOnTimeout(const std::function<void()>& callback) { onTimeout = callback; }

    void Timer::pause() { hasPaused = true; }

    void Timer::resume() { hasPaused = false; }

    void Timer::onUpdate(const float interval) {
        if (hasPaused) return;
        elapsedTime += interval;

        if (elapsedTime >= duration) {
            if ((!hasTriggered || isRepeating) && onTimeout) onTimeout();
            if (isRepeating) elapsedTime -= duration;
            hasTriggered = true;
        }
    }
}
