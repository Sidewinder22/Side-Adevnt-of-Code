#!/usr/bin/python3

lowers = "abcdefghijklmnopqrstuvwxyz"
uppers = "ABCDEFGHIJKLMNOPQRSTUVWXYZ"

def calculate_value(char):
    index = 0
    if char.islower():
        index = lowers.index(char) + 1
    else:
        index = 27 + uppers.index(char)
    return index


file_name = "input"
lines = []

with open(file_name) as file:
    lines = file.readlines()

sum = 0
for i in range(0, len(lines), 3):
    first = lines[i]
    second = lines[i + 1]
    third = lines[i + 2]

    for char in first:
        if second.find(char) != -1:
            if third.find(char) != -1:
                sum += calculate_value(char)
                break
    
print(f"Sum: {sum}")
