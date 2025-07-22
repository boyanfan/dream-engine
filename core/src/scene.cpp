//
// Created by fanboyan on 2025/6/25.
//

#include "../core/include/scene.h"

namespace DreamEngine {
    Scene* SceneManager::getCurrentScene() const {
        getInstance()->onSceneTransition();
        return currentScene;
    }

    void SceneManager::switchCurrentScene(Scene* nextScene) {
        if (!nextScene) return;
        nextScenes.push(nextScene);

        std::ostringstream buffer;
        buffer << Logger::getMessageModule(self) << " has scheduled " << nextScene->getIdentifier() << " to be the next scene.";
        LOG_INFO(buffer.str());
    }

    void SceneManager::onSceneTransition() {
        // Return if there is no scene to transition
        if (nextScenes.empty()) return;

        // If there is a current scene on the stage, exit it if it is finished
        if (currentScene) {
            if (currentScene->isAllowingSceneTransition()) { currentScene->onExit(); currentScene = nullptr; }
        }

        // Entry the next scene to the stage if there is no scene on the stage or the previous scene has finished
        else {
            currentScene = nextScenes.front();
            nextScenes.pop();
            currentScene->onEntry();
        }
    }

    bool Scene::isAllowingSceneTransition() const { return sceneWillTransition; }

    void Scene::unlockSceneTransition() { sceneWillTransition = true; }

    void Scene::lockSceneTransition() { sceneWillTransition = false; }
}
