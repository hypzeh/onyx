add_executable(Onyx.Sandbox Main.cpp)

target_link_libraries(Onyx.Sandbox Onyx.Engine)
target_include_directories(Onyx.Engine INTERFACE ${ONYX_SRC_DIR}/Onyx.Engine)
