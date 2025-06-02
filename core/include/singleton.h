//
// Created by fanboyan on 2025/6/2.
//

#ifndef DREAM_ENGINE_MANAGER_H
#define DREAM_ENGINE_MANAGER_H

namespace DreamEngine {
    /// A generic base class for implementing the Singleton pattern. To use this class, inherit from it and
    /// declare the derived class as a friend class.
    ///
    template<typename T> class Singleton {
        /// Protected default constructor to prevent external instantiation.
        protected: Singleton();

        /// Virtual destructor to allow safe cleanup in derived classes.
        protected: virtual ~Singleton();

        /// Deleted copy constructor to prevent copying of the singleton instance.
        public: Singleton(const Singleton&) = delete;

        /// Deleted move constructor to prevent moving of the singleton instance.
        public: Singleton(Singleton&&) = delete;

        /// Singleton instance pointer.
        private: static T* instance;

        /// Deleted copy assignment operator to prevent reassignment.
        public: Singleton& operator =(const Singleton&) = delete;

        /// Deleted move assignment operator to prevent move-assignment.
        public: Singleton& operator =(Singleton&&) = delete;

        /// Get the singleton instance of the derived class `T`.
        /// @return A pointer to the singleton instance of type `T`.
        ///
        static T* getInstance();
    };
}

#endif //DREAM_ENGINE_MANAGER_H
