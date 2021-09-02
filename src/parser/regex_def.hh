#pragma once
#include <map>
#include <string>
#include "result.hh"

namespace CompilerVm
{
    class RegexDef {
    public:
        // 定义格式如下:
        // 名称 <空格> 定义内容 [<空格>]
        void addRegexDef(std::string line);

        void addRegexDef(std::string name, std::string def);

        void printRegexDefs();

        std::string getRegexDef(std::string def, Result &r);

        size_t size() const {
            return _defMap.size();
        }
    private:
        std::map<std::string, std::string> _defMap;
    };
} // namespace CompilerVm
