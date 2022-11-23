cmake_minimum_required(VERSION 3.11 FATAL_ERROR)

project(testing VERSION 0.1 DESCRIPTION "diferent tests for the library" LANGUAGES CXX)


add_executable(slip10 slip10.cpp)
add_test(NAME slip10 COMMAND slip10)
target_link_libraries(slip10 PRIVATE qslip10)
include(FetchContent)

FetchContent_Declare(
        ed25
        GIT_REPOSITORY git@github.com:EddyTheCo/Qed25519.git
        GIT_TAG main
        )
FetchContent_MakeAvailable(ed25)

target_link_libraries(slip10 PRIVATE  qed25519)
