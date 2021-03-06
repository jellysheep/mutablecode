PROJECT(MutableCode)
cmake_minimum_required(VERSION 2.8)

set(PROJECT_INCLUDE_DIR ${PROJECT_SOURCE_DIR}/include)
set(PROJECT_SOURCE_DIR ${PROJECT_SOURCE_DIR}/src)

include_directories("${PROJECT_INCLUDE_DIR}")
include_directories("${PROJECT_SOURCE_DIR}")

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -g -std=c++11 -fopenmp -Wall -O2")

set(SOURCES
	${PROJECT_SOURCE_DIR}/main.cpp
	${PROJECT_SOURCE_DIR}/Program.cpp
	${PROJECT_SOURCE_DIR}/Interpreter.cpp
	${PROJECT_SOURCE_DIR}/Char.cpp
	${PROJECT_SOURCE_DIR}/Mutator.cpp
)
set(HEADERS
	${PROJECT_INCLUDE_DIR}/Tape.hpp
	${PROJECT_INCLUDE_DIR}/Program.hpp
	${PROJECT_INCLUDE_DIR}/Interpreter.hpp
	${PROJECT_INCLUDE_DIR}/Char.hpp
	${PROJECT_INCLUDE_DIR}/ProgramLoader.hpp
	${PROJECT_INCLUDE_DIR}/Mutator.hpp
	${PROJECT_INCLUDE_DIR}/Random.hpp
	${PROJECT_INCLUDE_DIR}/Evaluator.hpp
	${PROJECT_INCLUDE_DIR}/Compression.hpp
	${PROJECT_INCLUDE_DIR}/EntropyEvaluator.hpp
	${PROJECT_INCLUDE_DIR}/LevenshteinDistance.hpp
	${PROJECT_INCLUDE_DIR}/StringEvaluator.hpp
)

add_executable(MutableCode ${SOURCES} ${HEADERS})

target_link_libraries(MutableCode z)
