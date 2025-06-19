//
// Created by fanboyan on 2025/6/14.
//

#ifndef DREAM_ENGINE_LOGGER_H
#define DREAM_ENGINE_LOGGER_H

#include "singleton.h"
#include "symbols.h"

#include <string>
#include <sstream>
#include <iostream>
#include <ostream>

namespace DreamEngine {
    /// Defines the severity levels for logging messages, where
    ///     - Informational messages, typically for regular status updates.
    ///     - Warnings that indicate potential issues but not critical failures.
    ///     - Errors that signify serious problems or failed operations.
    ///
    enum class LogScope { Info, Warning, Error };

    /// A singleton logger class that handles formatted log message output with scoping and styling.
    /// Use this logger to print stylized log messages to the console. Messages below the configured log scope will be
    /// filtered out. Logging includes utility helpers for common operations such as initialization, deinitialization,
    /// and file loading status reporting.
    ///
    class Logger final : public Singleton<Logger> { friend class Singleton<Logger>;
        /// The minimum severity of messages that will be printed. Messages with a lower LogScope will be ignored.
        public: LogScope logScope = LogScope::Info;

        /// Constructs the logger. Private to enforce singleton access.
        private: Logger() = default;

        /// Destructs the logger instance.
        private: ~Logger() override = default;

        /// Logs a formatted message to the standard output stream if its scope meets the threshold.
        ///
        /// @param logScope The severity level of the message.
        /// @param message The message string to output.
        ///
        public: void log(LogScope logScope, const std::string& message) const;

        /// Constructs a stylized log message for a module initialization event.
        ///
        /// @param module The name of the module performing the initialization.
        /// @param target The target being initialized.
        /// @param state True if initialization succeeded; false otherwise.
        /// @return A formatted string describing the initialization result.
        ///
        public: static std::string onInitialize(const std::string& module, const std::string& target, bool state);

        /// Constructs a stylized log message for a module deinitialization event.
        ///
        /// @param module The name of the module performing the deinitialization.
        /// @param target The target being deinitialized.
        /// @return A formatted string describing the deinitialization result.
        ///
        public: static std::string onDeinitialize(const std::string& module, const std::string& target);

        /// Constructs a stylized log message for a file loading event.
        ///
        /// @param module The name of the module loading the file.
        /// @param filepath The path of the file.
        /// @param state True if loading succeeded; false otherwise.
        /// @return A formatted string describing the file loading result.
        ///
        public: static std::string onFileLoad(const std::string& module, const std::string& filepath, bool state);

        /// Constructs a stylized log message for a file unloading event.
        ///
        /// @param module The name of the module closing the file.
        /// @param filepath The path of the file.
        /// @return A formatted string describing the file unload action.
        ///
        public: static std::string onFileUnload(const std::string& module, const std::string& filepath);

        /// Returns a stylized string representation of the given module name.
        ///
        /// @param module The name of the module.
        /// @return A color-styled string with the module name.
        ///
        public: static std::string getMessageModule(const std::string& module);

        /// Formats and stylizes the given file path for logging purposes.
        ///
        /// @param filepath The file path to be stylized and included in log messages.
        /// @return A formatted string containing the stylized file path.
        ///
        public: static std::string getFilepath(const std::string& filepath);

        /// Returns the formatted log header prefix based on the severity scope.
        ///
        /// @param logScope The severity level of the log message.
        /// @return A styled header string for the severity level.
        ///
        private: static std::string getMessageHeader(LogScope logScope);
    };
}

#endif //DREAM_ENGINE_LOGGER_H
