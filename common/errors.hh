#pragma once

#include <map>

namespace CompilerVm
{
    class Errors {
    public:
        static std::map<std::string, std::string> errorMap;
    };
} // namespace CompilerVm
