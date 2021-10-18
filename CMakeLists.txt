cmake_minimum_required(VERSION 3.14)
project(cppbot)

# GoogleTest requires at least C++11
set(CMAKE_CXX_STANDARD 11)

add_library(bot src/bot.cc)
add_executable(cppbot src/main.cc)
target_link_libraries(cppbot bot)

include(FetchContent)
FetchContent_Declare(
  googletest
  URL https://github.com/google/googletest/archive/609281088cfefc76f9d0ce82e1ff6c30cc3591e5.zip
)
# For Windows: Prevent overriding the parent project's compiler/linker settings
set(gtest_force_shared_crt ON CACHE BOOL "" FORCE)
FetchContent_MakeAvailable(googletest)

enable_testing()

add_executable(
  bot_test
  test/cppbot_test.cc
)
target_link_libraries(
  bot_test
  bot
  gtest_main
)

include(GoogleTest)
gtest_discover_tests(bot_test)
