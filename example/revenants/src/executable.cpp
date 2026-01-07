//
// Created by fanboyan on 2025/6/11.
//

#include "executable.h"

namespace Revenants {
    RevenantsExecutable::RevenantsExecutable() : Application(getConfiguration(WINDOW_CONFIGURATION_FILE)) {
        // Developer tool only: generate the manifest file
        DreamEngine::ResourceManager::generateResourceManifest(RESOURCES_PATH, MANIFEST_PATH);

        // Verify and preload game resources
        DreamEngine::ResourceManager::verifyResourceManifest(RESOURCES_PATH, MANIFEST_PATH);

        DreamEngine::ResourceManager* resourceManager = DreamEngine::ResourceManager::getInstance();
        resourceManager->loadFromDirectory(renderer, RESOURCES_PATH);

        // Submit the scene
        DreamEngine::SceneManager* sceneManager = DreamEngine::SceneManager::getInstance();
        sceneManager->switchCurrentScene(new EmberScene(*camera));
    }

    RevenantsExecutable::~RevenantsExecutable() {
        DreamEngine::SceneManager* sceneManager = DreamEngine::SceneManager::getInstance();
        sceneManager->destroyCurrentScene();
    }

    DreamEngine::WindowConfiguration RevenantsExecutable::getConfiguration(const std::string& configuration) {
        // Load window configuration
        DreamEngine::WindowConfiguration windowConfiguration = DreamEngine::WindowConfiguration();
        windowConfiguration.configurateFromFile(configuration);
        return windowConfiguration;
    }
}