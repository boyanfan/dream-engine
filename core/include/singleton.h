//
// Created by fanboyan on 2025/6/2.
//

#ifndef DREAM_ENGINE_SINGLETON_H
#define DREAM_ENGINE_SINGLETON_H

namespace DreamEngine {
    /// A generic base class for implementing the Singleton pattern. To use this class, inherit from it and
    /// declare the derived class as a friend class.
    ///
    template<typename T> class Singleton {
        /// The pointer to the only global instance of a singleton class.
        private: static T* instance;

        /// Protected default constructor to prevent external instantiation.
        protected: Singleton() = default;

        /// Virtual destructor to allow safe cleanup in derived classes.
        protected: virtual ~Singleton() = default;

        /// Deleted copy constructor to prevent copying of the singleton instance.
        public: Singleton(const Singleton&) = delete;

        /// Deleted move constructor to prevent moving of the singleton instance.
        public: Singleton(Singleton&&) = delete;

        /// Get the singleton instance of the derived class `T`.
        /// @return A pointer to the singleton instance of type `T`.
        ///
        public: static T* getInstance();

        public: static void destroyInstance();

        /// Deleted copy assignment operator to prevent reassignment.
        public: Singleton& operator =(const Singleton&) = delete;

        /// Deleted move assignment operator to prevent move-assignment.
        public: Singleton& operator =(Singleton&&) = delete;
    };

    template<typename T> inline T* Singleton<T>::instance = nullptr;

    template<typename T> T* Singleton<T>::getInstance() {
        if (!instance) instance = new T();
        return instance;
    }

    template<typename T> void Singleton<T>::destroyInstance() {
        delete instance;
        instance = nullptr;
    }
}

#endif //DREAM_ENGINE_SINGLETON_H
