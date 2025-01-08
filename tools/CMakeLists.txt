set(LIB tools)

add_library(${LIB})
target_sources(${LIB}
    PUBLIC
    FILE_SET CXX_MODULES FILES
    filesystem.cpp)

target_sources(${LIB}
    PUBLIC
    FILE_SET CXX_MODULES FILES
    helpers.cpp)

target_sources(${LIB}
    PUBLIC
    FILE_SET CXX_MODULES FILES
    numbers.cpp)
