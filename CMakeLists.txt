cmake_minimum_required(VERSION 3.16)
project(jogo)

set(CMAKE_CXX_STANDARD 11)

file(GLOB_RECURSE SOURCES "src/*.cpp" "includes/*.h")

add_executable(
        jogo
        main.cpp
        ${SOURCES}
)

target_include_directories(jogo PRIVATE ${CMAKE_CURRENT_SOURCE_DIR}/includes)

# ===============================================================
#                   OS-SPECIFIC SFML CONFIG
# ===============================================================
if (WIN32)
    message(STATUS "Configuring project for Windows...")

    # Folder where SFML is stored on Windows
    set(SFML_STATIC_LIBRARIES FALSE)
    set(SFML_DIR "${CMAKE_CURRENT_SOURCE_DIR}/tools/SFML-2.6.2/lib/cmake/SFML")

    find_package(SFML 2.6 COMPONENTS system window graphics audio REQUIRED)

    # Copy SFML DLLs after build
    add_custom_command(
            TARGET jogo POST_BUILD
            COMMAND ${CMAKE_COMMAND} -E copy_directory
            "${CMAKE_CURRENT_SOURCE_DIR}/tools/SFML-2.6.2/bin"
            "$<TARGET_FILE_DIR:jogo>"
    )

elseif(UNIX)
    message(STATUS "Configuring project for Linux...")

    # Use system-installed SFML (apt install libsfml-dev)
    find_package(SFML 2.5 COMPONENTS system window graphics audio REQUIRED)
endif()

# ===============================================================

target_link_libraries(
        jogo
        sfml-system
        sfml-window
        sfml-graphics
        sfml-audio
)

set_target_properties(
        jogo PROPERTIES
        RUNTIME_OUTPUT_DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR}/bin
)
