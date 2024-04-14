
FetchContent_Declare(
        qed25519
        GIT_REPOSITORY https://github.com/EddyTheCo/Qed25519.git
        GIT_TAG v0.1.0
	FIND_PACKAGE_ARGS 0 CONFIG
        )
FetchContent_MakeAvailable(qed25519)


foreach(app  slip10)
add_executable(${app} ${app}.cpp)
target_link_libraries(${app} PRIVATE qslip10 qed25519)
add_test(NAME ${app} COMMAND ${app})

endforeach()

