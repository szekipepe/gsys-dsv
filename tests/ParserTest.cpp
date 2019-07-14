#include <functional>
#include <type_traits>

#include <gtest/gtest.h>

#include <GSys/DSV/Parser.h>

using namespace GSys::DSV;

TEST(ParserContructor, Default)
{
    EXPECT_TRUE(std::is_default_constructible<Parser>::value);
}

TEST(ParserContructor, CopyNoThrow)
{
    EXPECT_TRUE(std::is_nothrow_copy_constructible<Parser>::value);
}

TEST(ParserContructor, MoveNoThrow)
{
    EXPECT_TRUE(std::is_nothrow_move_constructible<Parser>::value);
}

TEST(ParserDestructor, NoThrow)
{
    EXPECT_TRUE(std::is_nothrow_destructible<Parser>::value);
}

TEST(ParserAssignable, CopyNoThrow)
{
    EXPECT_TRUE(std::is_nothrow_copy_assignable<Parser>::value);
}

TEST(ParserAssignable, MoveNoThrow)
{
    EXPECT_TRUE(std::is_nothrow_move_constructible<Parser>::value);
}

int main(int argc, char** argv)
{
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
