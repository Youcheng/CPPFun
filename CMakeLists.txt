cmake_minimum_required(VERSION 3.6)
if (NOT DEFINED ENV{CC} AND NOT DEFINED ENV{CXX})
    set(CMAKE_C_COMPILER "/opt/cresearch/bin/gcc")
    set(CMAKE_CXX_COMPILER "/opt/cresearch/bin/g++")
endif()

project(CPPFun CXX)



set(CMAKE_C_COMPILER "/opt/cresearch/bin/gcc")
set(CMAKE_CXX_COMPILER "/opt/cresearch/bin/g++")

set(CMAKE_EXPORT_COMPILE_COMMANDS "true")

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++14 -g -Wall -Wno-multichar -Wno-deprecated-declarations -Wno-unused-local-typedef -Wno-mismatched-tags -Wno-missing-braces")
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -DLEVEL1_DCACHE_LINESIZE=64")
set(CMAKE_CXX_FLAGS_DEBUG "${CMAKE_CXX_FLAGS_DEBUG} -DKMT_DEBUG -D_GLIBCXX_DEBUG -D_GLIBCXX_DEBUG_PEDANTIC")
set(CMAKE_EXE_LINKER_FLAGS "${CMAKE_EXE_LINKER_FLAGS} -static-libgcc -static-libstdc++ -fuse-ld=gold")


# find out all .cpp .hpp files recursively
file(GLOB_RECURSE TMP_FILES *.cpp *.hpp)
# put all object files into a lib, fun
add_library(fun ${TMP_FILES})


file(GLOB_RECURSE APP_SOURCES LIST_DIRECTORIES false *.cpp)
foreach(sourceFile ${APP_SOURCES})
    message("sourceFile = ${sourceFile}")
    string(REGEX MATCH  "[^/]*.cpp$" tmp ${sourceFile})
    string(REPLACE ".cpp" "" tgt ${tmp})
    add_executable(${tgt} ${sourceFile})
    target_link_libraries(${tgt} fun pthread dl)
endforeach(sourceFile ${APP_SOURCES})
