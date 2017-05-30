cmake_minimum_required(VERSION 3.2)
project(CPPFun CXX)

set(CMAKE_C_COMPILER "/opt/cresearch/bin/gcc")
set(CMAKE_CXX_COMPILER "/opt/cresearch/bin/g++")

set(CMAKE_EXPORT_COMPILE_COMMANDS "true")
set(CMAKE_CXX_STANDARD 14)
set(CMAKE_CXX_STANDARD_REQUIRED ON)


set(CMAKE_EXE_LINKER_FLAGS "${CMAKE_EXE_LINKER_FLAGS} -static-libgcc -static-libstdc++ -fuse-ld=gold")

#CopyControl
add_executable(copyInitialization CopyControl/copyInitialization.cpp)

#TypeTrait
add_executable(type TypeTrait/type.cpp)

#Constructor
add_executable(catchExceptFromConstructorInitializer Constructor/catchExceptFromConstructorInitializer.cpp)
