//
// Created by fanboyan on 2025/6/30.
//

#ifndef REVENANTS_INPUT_H
#define REVENANTS_INPUT_H

#include <SDL3/SDL.h>

namespace Revenants {
    enum class InputDeviceAction {
        /* Player Movement */ OnWalking, OnRunningLeft, OnRunningRight, OnRunningStopped, OnWalkingStopped, OnTurningAround,
        /* Player Skills */ OnShiftTriggered,
        /* Player Attack */ OnPrimaryAttackTriggered, OnSecondaryAttackTriggered,
        /* Debug Trigger Key */ OnDebuggerTriggered,
        /* Default */ None
    };

    class InputDeviceProxy {
        public: static InputDeviceAction getDeviceAction(const SDL_Event& event) {
            if (event.type == SDL_EVENT_KEY_DOWN) {
                switch (event.key.scancode) {
                    // Basic Moving
                    case SDL_SCANCODE_A: return InputDeviceAction::OnRunningLeft;
                    case SDL_SCANCODE_D: return InputDeviceAction::OnRunningRight;
                    case SDL_SCANCODE_W: return InputDeviceAction::OnWalking;
                    case SDL_SCANCODE_S: return InputDeviceAction::OnTurningAround;
                    case SDL_SCANCODE_LSHIFT: case SDL_SCANCODE_RSHIFT: return InputDeviceAction::OnShiftTriggered;

                    // Debug Mode Trigger Key
                    case SDL_SCANCODE_RIGHTBRACKET: return InputDeviceAction::OnDebuggerTriggered;

                    // Default
                    default: return InputDeviceAction::None;
                }
            }

            if (event.type == SDL_EVENT_KEY_UP) {
                switch (event.key.scancode) {
                    // Basic Moving Stops
                    case SDL_SCANCODE_A: case SDL_SCANCODE_D: return InputDeviceAction::OnRunningStopped;
                    case SDL_SCANCODE_W: return InputDeviceAction::OnWalkingStopped;

                    // Default
                    default: return InputDeviceAction::None;
                }
            }

            if (event.type == SDL_EVENT_MOUSE_BUTTON_DOWN) {
                switch (event.button.button) {
                    // Primary and secondary attacks
                    case SDL_BUTTON_LEFT: return InputDeviceAction::OnPrimaryAttackTriggered;
                    case SDL_BUTTON_RIGHT: return InputDeviceAction::OnSecondaryAttackTriggered;
                    default: return InputDeviceAction::None;
                }
            }

            // Unmapped key
            return InputDeviceAction::None;
        }
    };
}

#endif //REVENANTS_INPUT_H
