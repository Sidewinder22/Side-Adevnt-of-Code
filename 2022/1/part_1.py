#!/usr/bin/python3

file_name = "input"
lines = []

with open(file_name) as file:
    lines = file.readlines()

sum = 0
biggest_sum = 0

for line in lines:
    if line == "\n":
        if sum > biggest_sum:
            biggest_sum = sum
        sum = 0

    else:
        sum += int(line)


print(f"Biggest number of calories: {biggest_sum}")
