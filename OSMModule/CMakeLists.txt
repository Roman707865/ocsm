cmake_minimum_required(VERSION 2.8)

project(OSMModule)

include_directories(Include)

add_library(OSMModule Source/OSMModule.cpp Source/PriorKnowledgeProvider.cpp Source/RequestAnalyzer.cpp Source/RequestLauncher.cpp Source/ResultGenerator.cpp Source/JSON.cpp Source/JSONValue.cpp)

