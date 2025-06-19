//
// Created by fanboyan on 2025/6/14.
//

#include "logger.h"

namespace DreamEngine {
    void Logger::log(const LogScope logScope, const std::string &message) const {
        if (logScope < this->logScope) return;
        std::cout << getMessageHeader(logScope) << message << std::endl;
    }

    std::string Logger::onInitialize(const std::string& module, const std::string& target, const bool state) {
        std::ostringstream buffer;
        std::string action;

        if (state) action = " successfully initialized ";
        else action = " failed to initialize ";

        buffer << getMessageModule(module) << action << LOG_STYLE_CYAN << target << LOG_STYLE_PLAIN << ".";
        return buffer.str();
    }

    std::string Logger::onDeinitialize(const std::string& module, const std::string& target) {
        std::ostringstream buffer;
        buffer << LOG_STYLE_CYAN << target << LOG_STYLE_PLAIN << " has been deinitialized by " << getMessageModule(module) << ".";
        return buffer.str();
    }

    std::string Logger::onFileLoad(const std::string& module, const std::string& filepath, const bool state) {
        std::ostringstream buffer;
        std::string action;

        if (state) action = " successfully loaded ";
        else action = " failed to load ";

        buffer << getMessageModule(module) << action << "the file " << getFilepath(filepath) << ".";
        return buffer.str();
    }

    std::string Logger::onFileUnload(const std::string& module, const std::string& filepath) {
        std::ostringstream buffer;
        buffer << "File " << getFilepath(filepath) << " has been closed by " << getMessageModule(module) << ".";
        return buffer.str();
    }

    std::string Logger::getMessageModule(const std::string& module) {
        std::ostringstream buffer;
        buffer << LOG_STYLE_BLUE << module << LOG_STYLE_PLAIN;
        return buffer.str();
    }

    std::string Logger::getFilepath(const std::string& filepath) {
        std::ostringstream buffer;
        buffer << LOG_STYLE_MAGENTA << filepath << LOG_STYLE_PLAIN;
        return buffer.str();
    }

    std::string Logger::getMessageHeader(const LogScope logScope) {
        std::ostringstream buffer;
        if (logScope == LogScope::Info) buffer << LOG_STYLE_BOLD_GREEN << "[INFO]: " << LOG_STYLE_PLAIN;
        else if (logScope == LogScope::Warning) buffer << LOG_STYLE_BOLD_YELLOW << "[WARNING]: " << LOG_STYLE_PLAIN;
        else if (logScope == LogScope::Error) buffer << LOG_STYLE_BOLD_RED << "[ERROR]: " << LOG_STYLE_PLAIN;
        else buffer << LOG_STYLE_BOLD_GREY << "[Unknown]: ";

        return buffer.str();
    }
}
