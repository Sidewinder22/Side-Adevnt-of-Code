#!/usr/bin/python3

file_name = "input"
lines = []

with open(file_name) as file:
    lines = file.readlines()

result = 0
for line in lines:
    ranges = [r.split('-') for r in line.rstrip().split(',')]

    first_begin = int(ranges[0][0])
    first_end = int(ranges[0][1])
    second_begin = int(ranges[1][0])
    second_end = int(ranges[1][1])

    if first_begin <= second_begin and first_end >= second_end:
        result += 1
    elif second_begin <= first_begin and second_end >= first_end:
        result += 1

print(f"result: {result}")
