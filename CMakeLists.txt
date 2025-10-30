cmake_minimum_required(VERSION 3.16)
project(jogo)

set(CMAKE_CXX_STANDARD 11)

# Caminho onde a SFML foi extraída no Windows
# (ajuste se necessário)
set(SFML_STATIC_LIBRARIES FALSE)
set(SFML_DIR "${CMAKE_CURRENT_SOURCE_DIR}/tools/SFML-2.6.2/lib/cmake/SFML")

# --- Encontra a SFML ---
find_package(SFML 2.6 COMPONENTS system window graphics audio REQUIRED)

# --- Busca recursiva por arquivos .cpp e .h ---
file(
        GLOB_RECURSE SOURCES
        "src/*.cpp"
        "includes/*.h"
)

add_executable(
        jogo
        main.cpp
        ${SOURCES}
)

# --- Diretórios de include ---
target_include_directories(
        jogo PRIVATE
        ${CMAKE_CURRENT_SOURCE_DIR}/includes
)

# --- Linka as bibliotecas da SFML ---
target_link_libraries(
        jogo
        sfml-system
        sfml-window
        sfml-graphics
        sfml-audio
)

# --- Onde o executável será salvo ---
set_target_properties(
        jogo PROPERTIES
        RUNTIME_OUTPUT_DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR}/bin
)

add_custom_command(
        TARGET jogo POST_BUILD
        COMMAND ${CMAKE_COMMAND} -E copy_directory
        "${CMAKE_CURRENT_SOURCE_DIR}/tools/SFML-2.6.2/bin"
        "$<TARGET_FILE_DIR:jogo>"
)
