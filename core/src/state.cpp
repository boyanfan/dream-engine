//
// Created by fanboyan on 2025/7/2.
//

#include "state.h"

namespace DreamEngine {
    void FiniteStateMachine::switchCurrentState(State* state) {
        if (currentState == state) return;
        if (currentState) currentState->onExit();
        currentState = state;
        if (currentState) currentState->onEntry();
    }

    void FiniteStateMachine::onUpdate(const float interval) { if (currentState) currentState->onUpdate(interval); }
}