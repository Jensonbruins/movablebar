cmake_minimum_required(VERSION 3.21)

include(cmake/pico_sdk_import.cmake)

set(PICO_BOARD "pico")

project(mobielebar_project C CXX ASM)
set(CMAKE_C_STANDARD 17)

pico_sdk_init()

add_executable(mobielebar
    src/main.cpp
    src/screen.cpp
    src/relais.cpp
)

pico_enable_stdio_usb(mobielebar 1)
pico_enable_stdio_uart(mobielebar 0)

add_subdirectory(modules/pico-onewire)

target_link_libraries(mobielebar
    pico_runtime # bare minimum requirement
    pico_stdlib
    pico_one_wire
)

# Include directory contains sound effects
target_include_directories(mobielebar
    PRIVATE
    ${PROJECT_SOURCE_DIR}/include
)

# emit .uf2 file
pico_add_extra_outputs(mobielebar)
