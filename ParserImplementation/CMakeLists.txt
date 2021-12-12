cmake_minimum_required(VERSION 3.16.0)

project(parser-lib VERSION 1.0.0 LANGUAGES CXX)

# include_directories("${CMAKE_SOURCE_DIR}/ParserImplementation/Interfaces" "${PROJECT_NAME}/ParserImplementation/Source")

add_library(${PROJECT_NAME} Interfaces/Parser.h Interfaces/MyParser.h Source/MyParser.cpp Interfaces/Visitor.h
Interfaces/VisitorImp.h Source/VisitorImp.cpp Interfaces/YAMLobj.h Source/YAMLobj.cpp 
Interfaces/Source.h Interfaces/Sink.h
Interfaces/StringSource.h Interfaces/StreamSource.h Interfaces/StringSink.h Interfaces/StreamSink.h
Interfaces/DecoratorVisitor.h Interfaces/DecoratorSink.h Interfaces/DecoratorParser.h Interfaces/DecoratorSource.h) 

target_include_directories(${PROJECT_NAME} PUBLIC Interfaces)

target_link_libraries(${PROJECT_NAME} CONAN_PKG::spdlog)
