cmake_minimum_required(VERSION 3.2)
project(CPPFun CXX)



set(CMAKE_C_COMPILER "/opt/cresearch/bin/gcc")
set(CMAKE_CXX_COMPILER "/opt/cresearch/bin/g++")

set(CMAKE_EXPORT_COMPILE_COMMANDS "true")

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++14 -g -Wall -Wno-multichar -Wno-deprecated-declarations -Wno-unused-local-typedef -Wno-mismatched-tags -Wno-missing-braces")
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -DLEVEL1_DCACHE_LINESIZE=64")
set(CMAKE_CXX_FLAGS_DEBUG "${CMAKE_CXX_FLAGS_DEBUG} -DKMT_DEBUG -D_GLIBCXX_DEBUG -D_GLIBCXX_DEBUG_PEDANTIC")
set(CMAKE_EXE_LINKER_FLAGS "${CMAKE_EXE_LINKER_FLAGS} -static-libgcc -static-libstdc++ -fuse-ld=gold")

#include_directories(
#        src/apps
#        src/libs)


# find out all .cpp .hpp files recursively
file(GLOB_RECURSE TMP_FILES */*.cpp */*.hpp)
foreach(f ${TMP_FILES})
    #message(${f})
    list(APPEND SOURCE_FILES ${f})
endforeach()


# put all object files into a lib, fun
add_library(fun ${SOURCE_FILES})
link_libraries(fun)

#CopyControl
add_executable(copyInitialization CopyControl/copyInitialization.cpp)

#TypeTrait
add_executable(type TypeTrait/type.cpp)

#Constructor
add_executable(catchExceptFromConstructorInitializer Constructor/catchExceptFromConstructorInitializer.cpp)

#Destructor
add_executable(throwExceptInDestructor Destructor/throwExceptInDestructor.cpp)

#Library
add_executable(dlopen ${CMAKE_SOURCE_DIR}/Library/dlopen/dlopen.cpp)
target_link_libraries(dlopen ${CMAKE_DL_LIBS})
target_link_libraries(dlopen pthread)