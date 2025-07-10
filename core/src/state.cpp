//
// Created by fanboyan on 2025/7/2.
//

#include "state.h"

namespace DreamEngine {
    bool FiniteStateMachine::switchCurrentState(State* state) {
        if (currentState == state) return false;
        if (currentState) currentState->onExit();
        currentState = state;
        if (currentState) currentState->onEntry();
        return true;
    }

    void FiniteStateMachine::onUpdate(const float interval) { if (currentState) currentState->onUpdate(interval); }

    Identifier FiniteStateMachine::getCurrentStateID() const {
        if (currentState) return currentState->getIdentifier(); return Identifier();
    }
}