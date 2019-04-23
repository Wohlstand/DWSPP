cmake_minimum_required (VERSION 3.2)
project (DWSPP VERSION 0.0.1 LANGUAGES C CXX)

set(CMAKE_CXX_STANDARD 11)

set(libDWS_SRC
    lib/dwspp_private.cpp
)

set(libDWS_INCLUDES
    lib/
    include/
)

add_library(DWSPP STATIC
    ${libDWS_SRC}
)
target_include_directories(DWSPP PRIVATE ${libDWS_INCLUDES})
