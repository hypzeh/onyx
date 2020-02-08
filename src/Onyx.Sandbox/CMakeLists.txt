add_executable(Onyx.Sandbox Main.cpp)

set_target_properties(Onyx.Sandbox PROPERTIES FOLDER src)

target_link_libraries(Onyx.Sandbox PRIVATE Onyx.Engine)

target_include_directories(Onyx.Engine PRIVATE ${ONYX_SRC_DIR}/Onyx.Engine)
