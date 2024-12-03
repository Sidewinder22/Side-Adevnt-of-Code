set(LIB tools)

add_library(${LIB})
target_sources(${LIB}
    PUBLIC
    FILE_SET CXX_MODULES FILES
    tools.cpp)
