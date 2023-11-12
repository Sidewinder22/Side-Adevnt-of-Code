set (TARGET 7)

add_executable(${TARGET} main.cpp)
target_link_libraries(${TARGET} PRIVATE tools)
