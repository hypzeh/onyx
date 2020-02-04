add_executable(Sandbox Main.cpp)

target_link_libraries(Sandbox Onyx)
target_include_directories(Onyx INTERFACE ${ONYX_SRC_DIR}/Onyx)
