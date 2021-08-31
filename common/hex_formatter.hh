#pragma once
#include <string>

namespace CompilerVm {
    class HexFormatter {
    public:
        static std::string dump_to_string(
                const void* data,
                size_t size);
    };
}