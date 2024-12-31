cmake_minimum_required(VERSION 3.15)
project(sol2-luajit)

# Set C++ standard
set(CMAKE_CXX_STANDARD 17)

# Add LuaJIT
add_subdirectory(LuaJIT)
include_directories(LuaJIT/src)

# Add Sol2 include path
include_directories(sol2/include)

# Add the executable
add_executable(sol2-luajit main.cpp)

# Link LuaJIT library
target_link_libraries(sol2-luajit PRIVATE libluajit)
