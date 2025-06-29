//
// Created by fanboyan on 2025/6/25.
//

#ifndef DREAM_ENGINE_SCENE_H
#define DREAM_ENGINE_SCENE_H

#include "object.h"
#include "identifiable.h"
#include "singleton.h"
#include "logger.h"

namespace DreamEngine {
    /// The standard interface that represents an entire game scene. It provides lifecycle hooks for entering and
    /// exiting the scene.
    ///
    interface Scene : public GameObject, public Identifiable<identifier> {
        /// Destructor override to ensure proper cleanup of Scene-derived objects.
        public: ~Scene() override = default;

        /// Indicates whether the scene is ready to transition away. Controlled internally and modified through
        /// public methods.
        private: bool sceneWillTransition = true;

        /// Called when the scene is entered.
        public: virtual void onEntry() = delegated;

        /// Called when the scene is exited.
        public: virtual void onExit() = delegated;

        /// Prevents the scene from transitioning. Useful when a scene is not yet ready to exit.
        public: void lockSceneTransition();

        /// Allows the scene to transition away when requested. This should be called once the scene is ready to
        /// exit cleanly.
        ///
        public: void unlockSceneTransition();

        /// Checks whether the scene is currently allowing transitions.
        /// @return `true` if transitions are allowed, `false` otherwise.
        ///
        public: bool isAllowingSceneTransition() const;
    };

    /// A singleton class responsible for managing scene transitions in the game. SceneManager holds the currently
    /// active scene and provides an interface to switch to a different one.
    ///
    class SceneManager final : public Singleton<SceneManager> { friend class Singleton<SceneManager>;
        /// Class Name for reflection implementation.
        public: static inline std::string self = SCENE_MANAGER_TYPE;

        /// The currently active scene being managed.
        private: Scene* currentScene = nullptr;

        /// Queue of upcoming scenes scheduled for transition.
        private: std::queue<Scene*> nextScenes;

        /// Returns the currently active scene.
        /// @return Pointer to the current Scene.
        ///
        public: Scene* getCurrentScene() const;

        /// Schedules a scene to become the next active scene.
        /// @param nextScene Pointer to the new scene to activate.
        ///
        public: void switchCurrentScene(Scene* nextScene);

        /// Performs the actual scene transition if a scene is queued. It exits the current scene if it is ready to
        /// transition, enters the next scene if there is no active scene or the previous one finished.
        ///
        private: void onSceneTransition();
    };
}

#endif //DREAM_ENGINE_SCENE_H
