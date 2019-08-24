# The GoldScript Project
#
cmake_minimum_required (VERSION 3.3)

project ("GoldScript")

if(DEFINED ENV{GOLDSCRIPT_HOME})
     message("-- Will install GoldScript to location: " $ENV{GOLDSCRIPT_HOME})
	 set(CMAKE_INSTALL_PREFIX, $ENV{GOLDSCRIPT_HOME})
else(DEFINED ENV{GOLDSCRIPT_HOME})
     message("-- Will install GoldScript to location: " ${CMAKE_CURRENT_BINARY_DIR})
	 set(CMAKE_INSTALL_PREFIX, ${CMAKE_CURRENT_BINARY_DIR})
endif(DEFINED ENV{GOLDSCRIPT_HOME})

enable_testing()

add_subdirectory(src)