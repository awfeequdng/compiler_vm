#pragma once

#include <vector>
#include <string>

namespace CompilerVm
{
    class StrUtil {
    public:
        static std::vector<std::string> split(std::string str, char delimiter);
    };
} // namespace CompilerVm
