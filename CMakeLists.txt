set(NAME MLImageDenoiser)

cmake_minimum_required(VERSION 3.10)

project(${NAME})

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

if(CMAKE_VERSION VERSION_LESS "3.7.0")
    set(CMAKE_INCLUDE_CURRENT_DIR ON)
endif()

set(CMAKE_AUTOMOC ON)

find_package(Qt5 COMPONENTS Widgets REQUIRED)

# FILE Macros for all sources, main source and main headers
file (GLOB_RECURSE ALL_SOURCES "code/*.cpp" "code/*.h" "code/*.qrc" "code/*.ui")
set(MAIN_SOURCE code/MLImageDenoiser.cpp)
set(MAIN_HEADER code/MLImageDenoiser.h)

SET(ALL_SOURCES ${ALL_SOURCES} ${ADD_SOURCE})

qt5_wrap_ui(ALL_SOURCES code/MLImageDenoiser.ui)

if(WIN32)
	add_executable(MLImageDenoiser WIN32 ${MAIN_CPP} ${ALL_SOURCES} ${MAIN_HEADER})
	
	target_link_libraries(MLImageDenoiser debug ${CMAKE_SOURCE_DIR}/vendor/oidn/build/Debug/common.lib)
	target_link_libraries(MLImageDenoiser debug ${CMAKE_SOURCE_DIR}/vendor/oidn/build/Debug/utils.lib)
	target_link_libraries(MLImageDenoiser debug ${CMAKE_SOURCE_DIR}/vendor/oidn/build/Debug/OpenImageDenoise.lib)
	target_link_libraries(MLImageDenoiser debug ${CMAKE_SOURCE_DIR}/vendor/oidn/vendor/tbb/lib/intel64/vc14/tbb_debug.lib)

	add_custom_command(TARGET MLImageDenoiser
						POST_BUILD
						COMMAND "${CMAKE_COMMAND}" -E copy 
								"$(SolutionDir)/../vendor/oidn/build/$<$<CONFIG:Release>:Release>$<$<CONFIG:Debug>:Debug>/OpenImageDenoise.dll"
								"$(SolutionDir)/$<$<CONFIG:Release>:Release>$<$<CONFIG:Debug>:Debug>/OpenImageDenoise.dll"
						COMMENT "Copying OpenImageDenoise.dll to required directory.")
						
	add_custom_command(TARGET MLImageDenoiser
						POST_BUILD
						COMMAND "${CMAKE_COMMAND}" -E copy 
								"$(SolutionDir)/../vendor/oidn/vendor/tbb/redist/intel64/vc14/tbb12$<$<CONFIG:Release>:>$<$<CONFIG:Debug>:_debug>.dll"
								"$(SolutionDir)/$<$<CONFIG:Release>:Release>$<$<CONFIG:Debug>:Debug>/tbb12$<$<CONFIG:Release>:>$<$<CONFIG:Debug>:_debug>.dll"
						COMMENT "Copying tbb12_debug.dll to required directory.")
						
	add_custom_command(
    TARGET MLImageDenoiser PRE_BUILD
    COMMAND echo Configuration is $<$<CONFIG:Release>:Release>$<$<CONFIG:Debug>:Debug>
	)
						
	#copy /Y "$(SolutionDir)\..\vendor\oidn\build\Debug\OpenImageDenoise.dll" "$(SolutionDir)\Debug\OpenImageDenoise.dll"
	#copy /Y "$(SolutionDir)\..\vendor\oidn\vendor\tbb\redist\intel64\vc14\tbb12_debug.dll" "$(SolutionDir)\Debug\tbb12_debug.dll"
	
	target_link_libraries(MLImageDenoiser optimized ${CMAKE_SOURCE_DIR}/vendor/oidn/build/Release/common.lib)
	target_link_libraries(MLImageDenoiser optimized ${CMAKE_SOURCE_DIR}/vendor/oidn/build/Release/utils.lib)
	target_link_libraries(MLImageDenoiser optimized ${CMAKE_SOURCE_DIR}/vendor/oidn/build/Release/OpenImageDenoise.lib)
	target_link_libraries(MLImageDenoiser optimized ${CMAKE_SOURCE_DIR}/vendor/oidn/vendor/tbb/lib/intel64/vc14/tbb.lib)
else(WIN32)
	add_executable(MLImageDenoiser ${MAIN_CPP} ${ALL_SOURCES} ${MAIN_HEADER})
endif(WIN32)

include_directories("vendor/oidn")
include_directories("vendor/oidn/build")
include_directories("vendor/oidn/include")
include_directories("vendor/oidn/vendor/tbb/include")

target_link_libraries(${NAME} Qt5::Widgets)