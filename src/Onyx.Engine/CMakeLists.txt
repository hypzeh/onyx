file(GLOB_RECURSE ONYX_SOURCES_ENGINE
     ${ONYX_SRC_DIR}/Onyx.Engine/*.c
     ${ONYX_SRC_DIR}/Onyx.Engine/*.cpp
     ${ONYX_SRC_DIR}/Onyx.Engine/*.h
     ${ONYX_SRC_DIR}/Onyx.Engine/*.hpp)
add_library(Onyx.Engine STATIC ${ONYX_SOURCES_ENGINE})

set_target_properties(Onyx.Engine PROPERTIES FOLDER src)

target_link_libraries(Onyx.Engine PRIVATE glfw)
