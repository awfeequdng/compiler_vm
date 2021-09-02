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
    regexDef.addRegexDef("cai", "cai1");
    EXPECT_EQ("cai1", regexDef.getRegexDef("cai", r));

    _regex.setRegexDef(regexDef);
    _regex.addRegex("{cai} hello");
    _regex.expandRegex(r);
    if (r.isFailed()) {
        auto messages = r.messages();
        for (auto msg: messages) {
            std::cout << msg.code() << " " << msg.message() << std::endl;
        }
    }
    EXPECT_FALSE(r.isFailed());

    auto regexes = _regex.getRegex();
    EXPECT_EQ("cai1 hello", regexes[0]);
}

int main(int argc, char **argv) {
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}