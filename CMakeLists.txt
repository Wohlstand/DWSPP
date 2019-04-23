cmake_minimum_required (VERSION 3.2)
project (DWSPP VERSION 0.0.1 LANGUAGES C CXX)

set(CMAKE_CXX_STANDARD 11)

set(libDWS_SRC
    lib/dwspp.cpp
    lib/dwspp_private.cpp
    lib/windows_utils.cpp
)

set(libDWS_INCLUDES
    lib/
    include/
)

add_library(DWSPP STATIC
    ${libDWS_SRC}
)
target_include_directories(DWSPP PRIVATE ${libDWS_INCLUDES})
target_compile_definitions(DWSPP PRIVATE UNICODE _UNICODE)


add_executable(dws_test
    test/test.c
)
add_dependencies(dws_test DWSPP)
target_compile_definitions(dws_test PRIVATE UNICODE _UNICODE)
target_include_directories(dws_test PUBLIC include/)
target_link_libraries(dws_test DWSPP shlwapi)
