cmake_minimum_required (VERSION 2.8.11)
project (HTTPG)

file(GLOB_RECURSE SOURCES src/*.c)
add_executable (httpg ${SOURCES})

set(EXECUTABLE_OUTPUT_PATH "bin")

find_package (CURL)
if (CURL_FOUND)
	include_directories(${CURL_INCLUDE_DIRS})
	target_link_libraries(httpg ${CURL_LIBRARIES})
else()
	MESSAGE(FATAL_ERROR "LibCurl is not found in your system.")
endif (CURL_FOUND)

target_link_libraries(httpg ${LIBS})