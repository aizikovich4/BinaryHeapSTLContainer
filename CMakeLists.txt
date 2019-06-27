cmake_minimum_required (VERSION 3.13)
project (BinaryHeapSTLContainer)

set(CMAKE_CXX_STANDARD 17)

include_directories(${CMAKE_CURRENT_SOURCE_DIR})
message(${CMAKE_CURRENT_SOURCE_DIR})
set(BHEAP_SOURCE
			${CMAKE_CURRENT_SOURCE_DIR}/main.cpp
			${CMAKE_CURRENT_SOURCE_DIR}/bheap.cpp
			${CMAKE_CURRENT_SOURCE_DIR}/bheap.hpp
	)
	
add_executable(${PROJECT_NAME} ${BHEAP_SOURCE})


