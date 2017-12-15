cmake_minimum_required(VERSION 3.6 FATAL_ERROR)
project(taskThree)

set(SUBPROJECTS
	${PROJECT_NAME}-windows
	${PROJECT_NAME}-test
	${PROJECT_NAME}-fractal
	)
	
macro(find_package)
	if(NOT "${ARGV0}" IN_LIST SUBPROJECTS)
		_find_package(${ARGV0})
	endif()
endmacro()

foreach(subproj IN LISTS SUBPROJECTS)
	add_subdirectory(${subproj})
endforeach()
