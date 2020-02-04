add_executable(Sandbox Main.cpp)

target_link_libraries(Sandbox OnyxEngine)
target_include_directories(OnyxEngine INTERFACE ${ONYX_SRC_DIR}/OnyxEngine)
