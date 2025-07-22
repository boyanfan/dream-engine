//
// Created by fanboyan on 2025/7/4.
//

#ifndef DREAM_ENGINE_OBSERVABLE_H
#define DREAM_ENGINE_OBSERVABLE_H

#include "symbols.h"
#include <vector>

namespace DreamEngine {
    /// The standard interface for objects that can observe changes in an observable object.
    template<typename T> interface Observer {
        /// Virtual destructor for proper cleanup for the confirming types.
        public: virtual ~Observer() = default;

        /// Called when the observable has changed.
        /// @param newValue The new value of the observable.
        ///
        virtual void onNotified(const T& newValue) = delegated;
    };

    /// The standard interface for objects that can be observed and notify registered observers.
    template<typename T> interface Observable {
        /// All registered observers to be notified when the observed value has changed.
        private: std::vector<Observer<T>*> observers;

        /// Virtual destructor for proper cleanup for the confirming types.
        public: virtual ~Observable() = default;

        /// Adds an observer to be notified when the observable changes.
        /// @param observer Pointer to the observer to be added.
        ///
        public: void registerObserver(Observer<T>* observer) { observers.push_back(observer); }

        /// Removes an observer.
        /// @param observer Pointer to the observer to be removed.
        ///
        void removeObserver(Observer<T>* observer) {
            observers.erase(std::remove(observers.begin(), observers.end(), observer), observers.end());
        }

        /// Notifies all registered observers with the updated value.
        /// @param newValue The new value to notify observers about.
        ///
        public: void notify(const T& newValue) const {
            for (Observer<T>* observer : observers) { if (observer) observer->onNotified(newValue); }
        }
    };
}

#endif //DREAM_ENGINE_OBSERVABLE_H
