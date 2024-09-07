FetchContent_Declare(
	EstervEd25519
	GIT_REPOSITORY https://github.com/EddyTheCo/Esterv.Crypto.Ed25519.git
  GIT_TAG align 
  FIND_PACKAGE_ARGS 0.1 CONFIG)
FetchContent_MakeAvailable(EstervEd25519)

foreach(app slip10)
  add_executable(${app} ${app}.cpp)
  target_link_libraries(${app} PRIVATE slip10 Esterv::ed25519)
  add_test(NAME ${app} COMMAND ${app})

  if(WIN32 AND BUILD_SHARED_LIBS)
    add_custom_command(
      TARGET ${app}
      POST_BUILD
      COMMAND ${CMAKE_COMMAND} -E copy_if_different
              $<TARGET_RUNTIME_DLLS:${app}> $<TARGET_FILE_DIR:${app}>
      COMMAND_EXPAND_LISTS)
  endif()

endforeach()
