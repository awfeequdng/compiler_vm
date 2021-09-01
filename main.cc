
#include "hex_formatter.hh"
#include "colorizer.hh"
#include "regex_def.hh"
#include <iostream>
void func_test();

using namespace CompilerVm;

int main() {
    auto heap = malloc(1024 * 1024 * 32);
    std::cout << HexFormatter::dump_to_string(heap, 256);
    free(heap);

    std::string color = "Hello World";

    std::cout << colorizer::colorize(color, term_colors_t::yellow, term_colors_t::dark_gray) << std::endl;

    std::string line = "   cai pengxiang   ";
    RegexDef regexDef;
    regexDef.addRegexDef(line);
    regexDef.addRegexDef("nihao", "world");
    regexDef.printRegexDefs();
    Result r;
    auto def = regexDef.getRegexDef("nihao", r);
    if (r.isFailed()) {
        std::cout << colorizer::colorize(r.messages()[0].message(), term_colors_t::red) << std::endl;
    } else {
        std::cout << colorizer::colorize("nihao: " + def, term_colors_t::green) << std::endl;
    }

    def = regexDef.getRegexDef("test", r);
    if (r.isFailed()) {
        std::cout << colorizer::colorize(r.messages()[0].message(), term_colors_t::red) << std::endl;
    } else {
        std::cout << colorizer::colorize("test: " + def, term_colors_t::green) << std::endl;
    }
    // func_test();
    return 0;
}