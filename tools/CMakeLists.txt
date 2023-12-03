set (LIB tools)

set (HEADERS
    include/ReadFile.hpp
    include/DigitMap.hpp
)

set (SOURCES
    src/ReadFile.cpp
)

add_library(${LIB} SHARED
    ${HEADERS}
    ${SOURCES}
)

target_include_directories(${LIB} PUBLIC
    include()
)
