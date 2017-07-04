cmake_minimum_required(VERSION 3.6)
if (NOT DEFINED ENV{CC} AND NOT DEFINED ENV{CXX})
    set(CMAKE_C_COMPILER "/opt/cresearch/bin/gcc")
    set(CMAKE_CXX_COMPILER "/opt/cresearch/bin/g++")
endif()

project(CPPFun CXX)



set(CMAKE_C_COMPILER "/opt/cresearch/bin/gcc")
set(CMAKE_CXX_COMPILER "/opt/cresearch/bin/g++")

set(CMAKE_EXPORT_COMPILE_COMMANDS "true")

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++14 -g -Wall -Wno-multichar -Wno-deprecated-declarations -Wno-missing-braces")
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -DLEVEL1_DCACHE_LINESIZE=64")
set(CMAKE_CXX_FLAGS_DEBUG "${CMAKE_CXX_FLAGS_DEBUG} -DKMT_DEBUG -D_GLIBCXX_DEBUG -D_GLIBCXX_DEBUG_PEDANTIC")
set(CMAKE_EXE_LINKER_FLAGS "${CMAKE_EXE_LINKER_FLAGS} -static-libgcc -static-libstdc++ -fuse-ld=gold")


set(Boost_INCLUDE_DIR /opt/cresearch/vendor/boost/1.63.0/include/)
set(Boost_LIBRARY_DIR /opt/cresearch/vendor/boost/1.63.0/lib/gcc/6.3.0/x86_64/generic/release/)
set(Boost_NO_SYSTEM_PATHS ON)
set(Boost_USE_STATIC_LIBS ON)
find_package(Boost REQUIRED COMPONENTS date_time filesystem program_options system thread regex)

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
    include_directories(${Boost_INCLUDE_DIRS})
    target_link_libraries(${tgt} fun pthread dl ${Boost_LIBRARIES})
endforeach(sourceFile ${APP_SOURCES})
