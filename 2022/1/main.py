#!/usr/bin/python3

file_name = "input"
lines = []

with open(file_name) as file:
    lines = file.readlines()

sum = 0
biggest_number = 0

for line in lines:
    if line == "\n":
        if sum > biggest_number:
            biggest_number = sum
        sum = 0

    else:
        sum += int(line)


print(f"Biggest number of calories: {biggest_number}")
