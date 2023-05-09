cmake_minimum_required(VERSION 3.11 FATAL_ERROR)

project(testing VERSION 0.1 DESCRIPTION "diferent tests for the library" LANGUAGES CXX)


add_executable(slip10 slip10.cpp)
target_link_libraries(slip10 PRIVATE qslip10)
add_test(NAME slip10 COMMAND slip10)

if (WIN32 AND BUILD_SHARED_LIBS)
    add_custom_command(
        TARGET  POST_BUILD
        COMMAND ${CMAKE_COMMAND} -E copy_if_different $<TARGET_RUNTIME_DLLS:slip10> $<TARGET_FILE_DIR:slip10>
        COMMAND_EXPAND_LISTS
    )
endif ()


