#include <functional>
#include <type_traits>

#include <gtest/gtest.h>

#include <GSys/DSV/Config.h>

using namespace GSys::DSV;

TEST(ConfigContructor, Default)
{
    EXPECT_TRUE(std::is_default_constructible<Config>::value);
}

TEST(ConfigContructor, CopyNoThrow)
{
    EXPECT_TRUE(std::is_nothrow_copy_constructible<Config>::value);
}

TEST(ConfigContructor, MoveNoThrow)
{
    EXPECT_TRUE(std::is_nothrow_move_constructible<Config>::value);
}

TEST(ConfigDestructor, NoThrow)
{
    EXPECT_TRUE(std::is_nothrow_destructible<Config>::value);
}

TEST(ConfigAssignable, CopyNoThrow)
{
    EXPECT_TRUE(std::is_nothrow_copy_assignable<Config>::value);
}

TEST(ConfigAssignable, MoveNoThrow)
{
    EXPECT_TRUE(std::is_nothrow_move_constructible<Config>::value);
}

TEST(ConfigDefaultContructorMemberValue, LineEnding)
{
    EXPECT_EQ(Config().lineEnding(), Config::LineEnding::Lf);
}

TEST(ConfigDefaultContructorMemberValue, Delimiter)
{
    EXPECT_EQ(Config().delimiter(), Config::Delimiter::Comma);
}

TEST(ConfigDefaultContructorMemberValue, AllowedTextData)
{
    EXPECT_EQ(Config().allowedTextData(), Config::AllowedTextData::All);
}

TEST(ConfigDefaultContructorMemberValue, Header)
{
    EXPECT_EQ(Config().header(), Config::Header::FirstLineHeader);
}

TEST(ConfigSetters, LineEndingFromDefault)
{
    auto values = { Config::LineEnding::CrLf, Config::LineEnding::Lf, Config::LineEnding::Cr };
    for (auto value : values) {
        Config config;
        config.setLineEnding(value);
        EXPECT_EQ(config.lineEnding(), value);
    }
}

TEST(ConfigSetters, LineEndingFromToAnyValues)
{
    auto values = { Config::LineEnding::CrLf, Config::LineEnding::Lf, Config::LineEnding::Cr };
    for (auto value_from : values) {
        for (auto value_to : values) {
            Config config;
            config.setLineEnding(value_from);
            config.setLineEnding(value_to);
            EXPECT_EQ(config.lineEnding(), value_to);
        }
    }
}

int main(int argc, char** argv)
{
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
