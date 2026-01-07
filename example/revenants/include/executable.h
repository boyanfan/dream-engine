//
// Created by fanboyan on 2025/6/11.
//

#ifndef REVENANTS_EXECUTABLE_H
#define REVENANTS_EXECUTABLE_H

#include "engine/core.h"

#include "index.h"
#include "ember.h"

namespace Revenants {
    class RevenantsExecutable final : public DreamEngine::Application {
        // Initialize the game and load the resources
        public: RevenantsExecutable();

        // Destruct the game
        public: ~RevenantsExecutable() override;

        // Load the window configuration to create the game window
        private: static DreamEngine::WindowConfiguration getConfiguration(const std::string& configuration);
    };
}

#endif //REVENANTS_EXECUTABLE_H