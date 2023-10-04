cmake_minimum_required(VERSION 3.12)

project(BlockchainProject)

set(CMAKE_CXX_STANDARD 17)

add_executable(backend
    backend/main.cpp
    backend/blockchain.cpp
    backend/server.cpp
)

file(COPY frontend DESTINATION ${CMAKE_BINARY_DIR})

target_include_directories(backend PRIVATE backend)
