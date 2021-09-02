#include <gtest/gtest.h>
#include "regex_def.hh"
#include "regex.hh"
#include <iostream>

using namespace std;
using namespace CompilerVm;
using namespace testing;

class TestRegex : public testing::Test {
public:
    TestRegex() {}

protected:
    // RegexDef _regexDef;
    Regex _regex;
};

TEST_F(TestRegex, testExpr) {
    Result r;

    RegexDef regexDef;
    regexDef.addRegexDef("cai", "caix");
    regexDef.addRegexDef("peng", "{cai} peng");
    regexDef.addRegexDef("xiang", "{peng} xiang");
    EXPECT_EQ("caix", regexDef.getRegexDef("cai", r));

    _regex.setRegexDef(regexDef);
    _regex.addRegex("{cai} hello");
    _regex.addRegex("{xiang} hello");
    _regex.expandRegex(r);
    if (r.isFailed()) {
        auto messages = r.messages();
        for (auto msg: messages) {
            std::cout << msg.code() << " " << msg.message() << std::endl;
        }
    }
    EXPECT_FALSE(r.isFailed());

    auto regexes = _regex.getRegex();
    EXPECT_EQ("caix hello", regexes[0]);
    EXPECT_EQ("caix peng xiang hello", regexes[1]);
}

int main(int argc, char **argv) {
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}