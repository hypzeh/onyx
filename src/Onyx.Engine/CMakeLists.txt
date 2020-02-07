set(ONYX_SOURCES_ENGINE 
    Onyx.h
    System/Application.h
    System/Application.cpp
)

add_library(Onyx.Engine STATIC ${ONYX_SOURCES_ENGINE})
