cmake_minimum_required(VERSION 3.30)
project(myshell)

set(CMAKE_CXX_STANDARD 17)

set(READLINE_ROOT /opt/homebrew/opt/readline)
set(CMAKE_PREFIX_PATH ${CMAKE_PREFIX_PATH} ${READLINE_ROOT})

file(GLOB_RECURSE SOURCES "src/*.cpp" "src/*.h")

include_directories(${READLINE_ROOT}/include)
link_directories(${READLINE_ROOT}/lib)

add_executable(myshell ${SOURCES}
        src/builtins/echo.cpp
        src/myshell.h
        src/builtins/cd.cpp
        src/builtins/pwd.cpp
        src/builtins/ls.cpp
        src/builtins/cat.cpp
)

target_link_libraries(myshell readline)
