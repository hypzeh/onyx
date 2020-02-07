set(ONYX_SOURCES_ENGINE 
    Onyx.h
    pch.cpp
    pch.h
    Diagnostics/Logger.cpp
    Diagnostics/Logger.h
    System/Application.cpp
    System/Application.h
    System/Event.h
    System/Window.h
    System/WindowCloseEvent.h
    System/WindowsWindow.cpp
    System/WindowsWindow.h
)

add_library(Onyx.Engine STATIC ${ONYX_SOURCES_ENGINE})
