#pragma once

#include <string>
#include <vector>
#include <utility>

#include "result_message.hh"

namespace CompilerVm {

    class Result {
    public:
        Result() = default;

        inline void fail() {
            _success = false;
        }

        inline void succeed() {
            _success = true;
        }

        inline void info(
                const std::string& code,
                const std::string& message,
                const std::string& details = {}) {
            _messages.emplace_back(
                code,
                message,
                details,
                ResultMessage::types::info);
        }

        inline void error(
                const std::string& code,
                const std::string& message,
                const std::string& details = {}) {
            _messages.emplace_back(
                    code,
                    message,
                    details,
                    ResultMessage::types::error);
            fail();
        }

        inline void warning(
                const std::string& code,
                const std::string& message,
                const std::string& details = {}) {
            _messages.emplace_back(
                code,
                message,
                details,
                ResultMessage::types::warning);
        }

        inline bool isFailed() const {
            return !_success;
        }

        void removeCode(const std::string& code) {
            for (auto it = _messages.begin(); it != _messages.end(); ++it) {
                if ((*it).code() == code)
                    it = _messages.erase(it);
            }
        }

        inline const ResultMessageList& messages() const {
            return _messages;
        }

        inline bool hasCode(const std::string& code) const {
            for (const auto& msg : _messages)
                if (msg.code() == code)
                    return true;
            return false;
        }

        inline const ResultMessage* findCode(const std::string& code) const {
            for (auto it = _messages.begin(); it != _messages.end(); ++it) {
                if ((*it).code() == code)
                    return &(*it);
            }
            return nullptr;
        }

    private:
        bool _success = true;
        ResultMessageList _messages {};
    };

};
