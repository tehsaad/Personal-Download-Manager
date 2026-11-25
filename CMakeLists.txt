
cmake_minimum_required(VERSION 3.16)

project(PersonalDownloadManager
    VERSION 1.0
    DESCRIPTION "Personal Download Manager"
    LANGUAGES CXX
)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTOUIC ON)
set(CMAKE_AUTORCC ON)

# Support Qt 6 and Qt 5
find_package(QT NAMES Qt6 Qt5 REQUIRED COMPONENTS Widgets Network)
find_package(Qt${QT_VERSION_MAJOR} REQUIRED COMPONENTS Widgets Network)

# Collect source and header files
file(GLOB_RECURSE PROJECT_SOURCES CONFIGURE_DEPENDS
    "${CMAKE_CURRENT_SOURCE_DIR}/src/*.cpp"
)

file(GLOB_RECURSE PROJECT_HEADERS CONFIGURE_DEPENDS
    "${CMAKE_CURRENT_SOURCE_DIR}/src/*.h"
    "${CMAKE_CURRENT_SOURCE_DIR}/src/*.hpp"
)

# Application executable
add_executable(PersonalDownloadManager
    ${PROJECT_SOURCES}
    ${PROJECT_HEADERS}
)

# Include directories
target_include_directories(PersonalDownloadManager PRIVATE
    ${CMAKE_CURRENT_SOURCE_DIR}/src
    ${CMAKE_CURRENT_SOURCE_DIR}/src/core
    ${CMAKE_CURRENT_SOURCE_DIR}/src/net
    ${CMAKE_CURRENT_SOURCE_DIR}/src/ui
)

# Link Qt libraries
target_link_libraries(PersonalDownloadManager PRIVATE
    Qt${QT_VERSION_MAJOR}::Widgets
    Qt${QT_VERSION_MAJOR}::Network
)

# Compiler warnings
if(MSVC)
    target_compile_options(PersonalDownloadManager PRIVATE /W4)
else()
    target_compile_options(PersonalDownloadManager PRIVATE
        -Wall -Wextra -Wpedantic
    )
endif()

install(TARGETS PersonalDownloadManager
    RUNTIME DESTINATION bin
)
