cmake_minimum_required(VERSION 3.10)

project(BlockchainSimulation)

# Set C++ standard (e.g., C++11, C++14, C++17, etc.)
set(CMAKE_CXX_STANDARD 17)

# Find packages or libraries if needed (e.g., Boost, OpenSSL, etc.)
# find_package(Boost REQUIRED)

# Define your C++ executable target
add_executable(BlockchainSimulation
    backend/blockchain/main.cpp
    backend/blockchain/Block.h
    backend/blockchain/Block.cpp
    backend/blockchain/Transaction.h
    backend/blockchain/Transaction.cpp
    backend/blockchain/Blockchain.h
    backend/blockchain/Blockchain.cpp
    backend/blockchain/MerkleTree.h
    backend/blockchain/MerkleTree.cpp
)

# Include any additional dependencies here (e.g., Boost)
# target_link_libraries(BlockchainSimulation PRIVATE Boost::Boost)

# Find OpenSSL and link it to the target
find_package(OpenSSL REQUIRED)
target_link_libraries(BlockchainSimulation OpenSSL::Crypto)

# Set output directory for the executable (optional)
set(EXECUTABLE_OUTPUT_PATH ${CMAKE_BINARY_DIR}/bin)
