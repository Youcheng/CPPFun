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
add_library(fun ${SOURCE_FILES} Preprocessor/log.cpp)
link_libraries(fun)

#CopyControl
add_executable(copyInitialization CopyControl/copyInitialization.cpp)

#TypeTrait
add_executable(type TypeTrait/type.cpp)
add_executable(staticAssert TypeTrait/staticAssert.cpp)

#Constructor
add_executable(catchExceptFromConstructorInitializer Constructor/catchExceptFromConstructorInitializer.cpp SharedVariable/conditionVariable.cpp Future/future.cpp Future/writerReader.cpp VirtualFunction/multipleVirtualFunc.cpp StorageDurationAndLinkage/threadLocal.cpp Pimp/widget.h Pimp/widget.cpp Object/alignment.cpp)

#Destructor
add_executable(throwExceptInDestructor Destructor/throwExceptInDestructor.cpp)

#Library
add_executable(dlopen ${CMAKE_SOURCE_DIR}/Library/dlopen/dlopen.cpp)
target_link_libraries(dlopen ${CMAKE_DL_LIBS})
target_link_libraries(dlopen pthread)

#SharedVariable
add_executable(deadlock ${CMAKE_SOURCE_DIR}/SharedVariable/deadLock.cpp)
target_link_libraries(deadlock pthread)
add_executable(conditionVariable ${CMAKE_SOURCE_DIR}/SharedVariable/conditionVariable.cpp)
target_link_libraries(conditionVariable pthread)

#Future
add_executable(future ${CMAKE_SOURCE_DIR}/Future/future.cpp)
target_link_libraries(future pthread)
add_executable(writerReader ${CMAKE_SOURCE_DIR}/Future/writerReader.cpp)
target_link_libraries(writerReader pthread)

#VirtualFunction
add_executable(multipleVirtualFunc ${CMAKE_SOURCE_DIR}/VirtualFunction/multipleVirtualFunc.cpp)

#StorageDurationAndLinkage
add_executable(threadLocal ${CMAKE_SOURCE_DIR}/StorageDurationAndLinkage/threadLocal.cpp)
target_link_libraries(threadLocal pthread)

#String
add_executable(cstrcpy ${CMAKE_SOURCE_DIR}/String/cstrcpy.cpp)

#Pimp
add_executable(widget ${CMAKE_SOURCE_DIR}/Pimp/widget.cpp)

#Preprocessor
add_executable(log ${CMAKE_SOURCE_DIR}/Preprocessor/log.cpp)

#Object
add_executable(alignment ${CMAKE_SOURCE_DIR}/Object/alignment.cpp)

#UniversalReference
add_executable(universalReference ${CMAKE_SOURCE_DIR}/UniversalReference/universalReference.cpp)
target_link_libraries(universalReference pthread)