cmake_minimum_required(VERSION 3.12)
project(chess_study)

# Source files
set(SRC_DIR "${CMAKE_SOURCE_DIR}/src")
set(TEST_DIR "${CMAKE_SOURCE_DIR}/tests")
set(SRC_FILES
    ${SRC_DIR}/main/main.c
    ${SRC_DIR}/core/piece/piece.c
    ${SRC_DIR}/core/piece/piece_type.c
    ${SRC_DIR}/core/board/board.c
    ${SRC_DIR}/core/board/square.c
    ${SRC_DIR}/core/color_attribute.c
    ${SRC_DIR}/core/player.c
    ${SRC_DIR}/core/move_history.c
    ${SRC_DIR}/core/game.c
)

# Include directories
include_directories(
    ${SRC_DIR}
)

# Add executable
add_executable(chess_study ${SRC_FILES} ${SRC_DIR}/main/main.c)

# Set compiler flags debugging
target_compile_options(chess_study PRIVATE -Wall -Wextra -g)
