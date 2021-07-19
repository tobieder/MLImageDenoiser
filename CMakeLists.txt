set(NAME MLImageDenoiser)

cmake_minimum_required(VERSION 3.10)

project(${NAME})

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

if(CMAKE_VERSION VERSION_LESS "3.7.0")
    set(CMAKE_INCLUDE_CURRENT_DIR ON)
endif()

find_package(Qt5 COMPONENTS Widgets REQUIRED)

# FILE Macros for all sources, main source and main headers
file (GLOB_RECURSE ALL_SOURCES "code/*.cpp" "code/*.h" "code/*.qrc" "code/*.ui")
set(MAIN_SOURCE code/MLImageDenoiser.cpp)
set(MAIN_HEADER code/MLImageDenoiser.h)

SET(ALL_SOURCES ${ALL_SOURCES} ${ADD_SOURCE})

qt5_wrap_ui(ALL_SOURCES code/MLImageDenoiser.ui)

if(WIN32)
	add_executable(MLImageDenoiser WIN32 ${MAIN_CPP} ${ALL_SOURCES} ${MAIN_HEADER})
	#target_link_libraries(realtimertfilters-app base ${Vulkan_LIBRARY} ${WINLIBS})
        #add_custom_command(TARGET realtimertfilters-app POST_BUILD WORKING_DIRECTORY "${CMAKE_SOURCE_DIR}/realtimertfilters-app/data/shaders/glsl" COMMAND "${CMAKE_SOURCE_DIR}/realtimertfilters-app/data/shaders/glsl/compile_all_shaders.bat")
else(WIN32)
	add_executable(MLImageDenoiser ${MAIN_CPP} ${ALL_SOURCES} ${MAIN_HEADER})
	#target_link_libraries(realtimertfilters-app base )
    #    #add_custom_command(TARGET realtimertfilters-app POST_BUILD WORKING_DIRECTORY "${CMAKE_SOURCE_DIR}/realtimertfilters-app/data/shaders/glsl" COMMAND "${CMAKE_SOURCE_DIR}/realtimertfilters-app/data/shaders/glsl/compile_all_shaders.sh")
endif(WIN32)

include_directories("vendor/oidn")
include_directories("vendor/oidn/build")
include_directories("vendor/oidn/include")
include_directories("vendor/oidn/vendor/tbb/include")

target_link_libraries(MLImageDenoiser ${CMAKE_SOURCE_DIR}/vendor/oidn/build/Debug/common.lib)
target_link_libraries(MLImageDenoiser ${CMAKE_SOURCE_DIR}/vendor/oidn/build/Debug/utils.lib)
target_link_libraries(MLImageDenoiser ${CMAKE_SOURCE_DIR}/vendor/oidn/build/Debug/OpenImageDenoise.lib)
target_link_libraries(MLImageDenoiser ${CMAKE_SOURCE_DIR}/vendor/oidn/vendor/tbb/lib/intel64/vc14/tbb_debug.lib)

message(${CMAKE_SOURCE_DIR})

#link_directories("vendor/oidn/build/Debug/common.lib")
#link_directories("vendor/oidn/build/Debug/utils.lib")
#link_directories("vendor/oidn/build/Debug/OpenImageDenoise.lib")
#link_directories("vendor/oidn/vendor/tbb/lib/intel64/vc14/tbb_debug.lib")

target_link_libraries(${NAME} Qt5::Widgets)