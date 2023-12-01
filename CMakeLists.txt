cmake_minimum_required(VERSION 3.10)

project(BlockchainSimulation)

# Set C++ standard (e.g., C++11, C++14, C++17, etc.)
set(CMAKE_CXX_STANDARD 17)

# Find packages or libraries if needed (e.g., Boost, OpenSSL, etc.)
# find_package(Boost REQUIRED)

# Include WebSocket++ library (adjust the path)
add_subdirectory(../websocketpp)

# Define your C++ executable target
add_executable(BlockchainSimulation
    main.cpp
    backend/blockchain/Block.h
    backend/blockchain/Block.cpp
    backend/blockchain/Transaction.h
    backend/blockchain/Transaction.cpp
    backend/blockchain/Blockchain.h
    backend/blockchain/Blockchain.cpp
    backend/blockchain/MerkleTree.h
    backend/blockchain/MerkleTree.cpp
    backend/websocket/WebSocketServer.h
    backend/websocket/WebSocketServer.cpp
)

# Link WebSocket++ library to your executable
target_link_libraries(BlockchainSimulation PRIVATE websocketpp::websocketpp)

# Include any additional dependencies here (e.g., Boost)
# target_link_libraries(BlockchainSimulation PRIVATE Boost::Boost)

# Set output directory for the executable (optional)
# set(EXECUTABLE_OUTPUT_PATH ${CMAKE_BINARY_DIR}/bin)

# Add compiler-specific flags if needed
# For example, to enable all warnings:
# if (CMAKE_COMPILER_IS_GNUCC OR CMAKE_COMPILER_IS_GNUCXX)
#     target_compile_options(BlockchainSimulation PRIVATE -Wall -Wextra -pedantic)
# endif()
