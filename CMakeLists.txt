# CMakeList.txt : CMake project for CMakeProject4, include source and define
# project specific logic here.
#
cmake_minimum_required (VERSION 3.8)

# Enable Hot Reload for MSVC compilers if supported.
if (POLICY CMP0141)
  cmake_policy(SET CMP0141 NEW)
  set(CMAKE_MSVC_DEBUG_INFORMATION_FORMAT "$<IF:$<AND:$<C_COMPILER_ID:MSVC>,$<CXX_COMPILER_ID:MSVC>>,$<$<CONFIG:Debug,RelWithDebInfo>:EditAndContinue>,$<$<CONFIG:Debug,RelWithDebInfo>:ProgramDatabase>>")
endif()

project ("CMakeProject4")

file(GLOB SOURCES "src/*.cpp")

set(BUILD_SHARED_LIBS OFF)
set(CMAKE_EXE_LINKER_FLAGS "-static")
set(CMAKE_FIND_LIBRARY_SUFFIXES ".a")

add_executable (CMakeProject4 "CMakeProject4.cpp" "CMakeProject4.h" ${SOURCES})

if (CMAKE_VERSION VERSION_GREATER 3.12)
  set_property(TARGET CMakeProject4 PROPERTY CXX_STANDARD 20)
endif()

# TODO: Add tests and install targets if needed.
# include_directories(third_party/depends)

# SET(CMAKE_INCLUDE_PATH ${CMAKE_INCLUDE_PATH} "/home/fiyuu/boost")
# SET(CMAKE_LIBRARY_PATH ${CMAKE_LIBRARY_PATH} "/home/fiyuu/boost/stage/lib")

add_subdirectory(third_party/hwinfo)
include_directories(third_party/hwinfo/include)
 
target_link_libraries(CMakeProject4 PRIVATE hwinfo::HWinfo iphlpapi)