cmake_minimum_required(VERSION 3.10)
project(02_xml_parse)

set(CMAKE_CXX_STANDARD 14)

set(INC_DIRS "." "cl_factory/" "cl_factory/vsq_classes" "xml_procs/")
set(SRC_LIST main.cpp cl_factory/vsq_classes/emptyitem.cpp cl_factory/vsq_classes/visualproject.cpp vsqconstructor.h vsqconstructor.cpp)


include_directories(${INC_DIRS})

add_executable(${PROJECT_NAME} ${SRC_LIST})

