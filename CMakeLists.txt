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
	
	target_link_libraries(MLImageDenoiser debug ${CMAKE_SOURCE_DIR}/vendor/oidn-windows/lib/OpenImageDenoise.lib)
	target_link_libraries(MLImageDenoiser debug ${CMAKE_SOURCE_DIR}/vendor/oidn-windows/lib/tbb.lib)
	
	target_link_libraries(MLImageDenoiser optimized ${CMAKE_SOURCE_DIR}/vendor/oidn-windows/lib/OpenImageDenoise.lib)
	target_link_libraries(MLImageDenoiser optimized ${CMAKE_SOURCE_DIR}/vendor/oidn-windows/lib/tbb.lib)

	add_custom_command(TARGET MLImageDenoiser
						POST_BUILD
						COMMAND "${CMAKE_COMMAND}" -E copy 
								"$(SolutionDir)/../vendor/oidn-windows/bin/OpenImageDenoise.dll"
								"$(SolutionDir)/$<$<CONFIG:Release>:Release>$<$<CONFIG:Debug>:Debug>/OpenImageDenoise.dll"
						COMMENT "Copying OpenImageDenoise.dll to required directory.")
						
	add_custom_command(TARGET MLImageDenoiser
						POST_BUILD
						COMMAND "${CMAKE_COMMAND}" -E copy 
								"$(SolutionDir)/../vendor/oidn-windows/bin/tbb12.dll"
								"$(SolutionDir)/$<$<CONFIG:Release>:Release>$<$<CONFIG:Debug>:Debug>/tbb12.dll"
						COMMENT "Copying tbb12.dll to required directory.")
						
	
	include_directories("vendor/oidn-windows/include")
	
else(WIN32)
	add_executable(MLImageDenoiser ${MAIN_CPP} ${ALL_SOURCES} ${MAIN_HEADER})
	
	target_link_libraries(MLImageDenoiser debug ${CMAKE_SOURCE_DIR}/vendor/oidn-linux/lib/libOpenImageDenoise.so.1.4.1)
	target_link_libraries(MLImageDenoiser debug ${CMAKE_SOURCE_DIR}/vendor/oidn-linux/lib/libtbb.so.12.2)
	
	target_link_libraries(MLImageDenoiser optimized ${CMAKE_SOURCE_DIR}/vendor/oidn-linux/lib/libOpenImageDenoise.so.1.4.1)
	target_link_libraries(MLImageDenoiser optimized ${CMAKE_SOURCE_DIR}/vendor/oidn-linux/lib/libtbb.so.12.2)
						
	
	include_directories("vendor/oidn-linux/include")
	
endif(WIN32)

target_link_libraries(${NAME} Qt5::Widgets)