

cmake_minimum_required(VERSION 3.10)
project(UbuntuImageFetcher VERSION 1.0)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++17 -stdlib=libc++")

find_package(Poco REQUIRED COMPONENTS Net JSON NetSSL)

include_directories(${Poco_INCLUDE_DIRS})
include_directories(${CMAKE_SOURCE_DIR}/include)

enable_testing()

add_executable(UbuntuImageFetcher
    test/main.cpp
    src/UbuntuImageFetcher.cpp
    test/test_UbuntuImageFetcher.cpp
)

target_link_libraries(UbuntuImageFetcher Poco::Net Poco::JSON Poco::NetSSL)

# -------------------------
# Testing

# UbuntuImageFetcherTests
add_executable(UbuntuImageFetcherTests
    test/main.cpp
    test/test_UbuntuImageFetcher.cpp
    src/UbuntuImageFetcher.cpp
)

target_link_libraries(UbuntuImageFetcherTests Poco::Net Poco::JSON Poco::NetSSL)
add_test(NAME UbuntuImageFetcherTest COMMAND UbuntuImageFetcherTests)
