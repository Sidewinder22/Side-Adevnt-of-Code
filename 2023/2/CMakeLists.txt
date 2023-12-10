set (TARGET 2)

set (PART_1 ${TARGET}_part_1)
set (PART_2 ${TARGET}_part_2)

add_executable(${PART_1} part_1.cpp)
target_link_libraries(${PART_1} PRIVATE tools)
