#include "definition.hh"
#include "strutil.hh"
#include "colorizer.hh"
#include <iostream>
#include <fmt/format.h>
#include "errors.hh"

namespace CompilerVm
{
    void Definition::addDefinition(std::string line) {
        std::vector<std::string> defs = StrUtil::split(line, ' ');
        if (defs.size() != 2) {
            std::cout << colorizer::colorize("invalid line: " + line, term_colors_t::red)
                      << std::endl;
            return;
        }
        addDefinition(defs[0], defs[1]);
    }

    void Definition::addDefinition(std::string name, std::string def) {
        _defMap[name] = def;
    }

    void Definition::printDefinitions() {
        for (auto entity: _defMap) {
            std::cout << entity.first << ": " << entity.second << std::endl;
        }
    }

    std::string Definition::getDefinition(std::string name, Result& r) {
        auto it = _defMap.find(name);
        if (it == _defMap.end()) {
            r.error("B001", fmt::format("{} : {}", errorMap["B001"], name));
            return "";
        }
        return it->second;
    }
} // namespace compiler_vm
