#include <gtest/gtest.h>

class TestRegex : public testing::Test {
public:
    TestRegex() {}

protected:
};

TEST_F(TestRegex, testExpr) {
    std::cout << "hello world" << std::endl;
}

int main(int argc, char **argv) {
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}