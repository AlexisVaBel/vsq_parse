cmake_minimum_required(VERSION 3.10)
project(02_xml_parse)

set(CMAKE_CXX_STANDARD 14)

add_executable(02_xml_parse
        main.cpp xml_procs/xmlreader.h cl_factory/visualproject.h cl_factory/vsqitem.h cl_factory/vsqitemsregistrator.h cl_factory/vsqitemfactory.h cl_factory/visualproject.cpp)
