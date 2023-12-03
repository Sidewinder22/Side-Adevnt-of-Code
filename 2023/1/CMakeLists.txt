set (TARGET 1)

set (PART_1 ${TARGET}_part_1)
set (PART_2 ${TARGET}_part_2)

add_executable(${PART_1} part_1.cpp)
target_link_libraries(${PART_1} PRIVATE tools)

add_executable(${PART_2} part_2.cpp)
target_link_libraries(${PART_2} PRIVATE tools)
