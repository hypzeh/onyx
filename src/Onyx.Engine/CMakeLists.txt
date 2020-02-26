file(GLOB_RECURSE ONYX_SOURCES_ENGINE
     ${ONYX_SRC_DIR}/Onyx.Engine/*.cpp
     ${ONYX_SRC_DIR}/Onyx.Engine/*.h)
add_library(Onyx.Engine STATIC ${ONYX_SOURCES_ENGINE})

set_target_properties(Onyx.Engine PROPERTIES FOLDER src)

if (WIN32)
    add_compile_definitions(ONYX_PLATFORM_WINDOWS)
endif()

target_link_libraries(Onyx.Engine PRIVATE glfw)
