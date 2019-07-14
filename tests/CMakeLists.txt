include_directories(SYSTEM GTest::GTest)

add_executable(config_test ConfigTest.cpp)
target_link_libraries(config_test GSysDSV GTest::GTest)
gtest_add_tests(TARGET config_test)

add_executable(parser_test ParserTest.cpp)
target_link_libraries(parser_test GSysDSV GTest::GTest)
gtest_add_tests(TARGET parser_test)
