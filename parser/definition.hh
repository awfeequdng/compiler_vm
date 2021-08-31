#pragma once
#include <map>
#include <string>
#include "result.hh"

namespace CompilerVm
{
    class Definition {
    public:
        // 定义格式如下:
        // 名称 <空格> 定义内容 [<空格>]
        void addDefinition(std::string line);

        void addDefinition(std::string name, std::string definition);

        void printDefinitions();

        std::string getDefinition(std::string def, Result &r);

    private:
        std::map<std::string, std::string> _defMap;
    };
} // namespace CompilerVm
