cmake_minimum_required(VERSION 3.30)
project(myshell)

set(CMAKE_CXX_STANDARD 17)

set(READLINE_ROOT /opt/homebrew/opt/readline)
set(CMAKE_PREFIX_PATH ${CMAKE_PREFIX_PATH} ${READLINE_ROOT})

file(GLOB_RECURSE SOURCES "src/*.cpp" "src/*.h")

include_directories(${READLINE_ROOT}/include ${PROJECT_SOURCE_DIR}/include)
link_directories(${READLINE_ROOT}/lib)

add_executable(myshell ${SOURCES}
        src/builtins/find.cpp)

target_link_libraries(myshell readline)
