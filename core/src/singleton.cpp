//
// Created by fanboyan on 2025/6/2.
//

#include "singleton.h"

namespace DreamEngine {
    template<typename T> T* Singleton<T>::instance = nullptr;

    template<typename T> Singleton<T>::Singleton() = default;

    template<typename T> Singleton<T>::~Singleton() = default;

    template<typename T> T* Singleton<T>::getInstance() {
        if (!instance) instance = new T();
        return instance;
    }
}