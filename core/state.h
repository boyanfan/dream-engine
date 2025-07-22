//
// Created by fanboyan on 2025/7/2.
//

#ifndef DREAM_ENGINE_STATE_H
#define DREAM_ENGINE_STATE_H

#include "symbols.h"
#include "updatable.h"
#include "identifiable.h"

#include <string>
#include <unordered_map>

namespace DreamEngine {
    /// The standard interface that represents a generic state in the game or application, managed by
    /// a finite state machine.
    ///
    interface State : public Updatable, public Identifiable<Identifier> {
        /// Destructor override to ensure proper cleanup of state-derived objects.
        public: ~State() override = default;

        /// Called when the state becomes active or is entered.
        public: virtual void onEntry() = delegated;

        /// Called when the state is no longer active or is exited.
        public: virtual void onExit() = delegated;
    };

    /// A final class representing a finite state machine (FSM) that manages transitions between different `State`
    /// instances.
    ///
    class FiniteStateMachine final : public Updatable {
        /// Pointer to the currently active state.
        private: State* currentState = nullptr;

        /// Constructs an empty finite state machine.
        public: FiniteStateMachine() = default;

        /// Destructor override to ensure proper cleanup.
        public: ~FiniteStateMachine() override = default;

        /// Switches the current active state to the one associated with the given identifier.
        /// @param state The state to switch to.
        ///
        public: bool switchCurrentState(State* state);

        /// Get the identifier of the current active state.
        /// @return The identifier defined by the current active state.
        ///
        public: Identifier getCurrentStateID() const;

        /// Updates the currently active state. This method should be called once per frame.
        /// @param interval The elapsed time since the last update, in seconds.
        ///
        public: void onUpdate(float interval) override;
    };
}

#endif //DREAM_ENGINE_STATE_H
