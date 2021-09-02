#include "errors.hh"

namespace CompilerVm
{
    std::map<std::string, std::string> Errors::errorMap = {
        {"B001", "Bad definition name"},
        {"B002", "Invalid regular expression"},
    };
} // namespace CompilerVm
