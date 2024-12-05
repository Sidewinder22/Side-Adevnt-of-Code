set(YEAR 2024)
set(TARGET 1)

set(PART_1 ${YEAR}_${TARGET}_part_1)

add_executable(${PART_1} part_1.cpp)
target_link_libraries(${PART_1} PRIVATE tools)
