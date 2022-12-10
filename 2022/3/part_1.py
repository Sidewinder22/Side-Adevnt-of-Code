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
for line in lines:
    line = line.rstrip()
    half_length = int(len(line)/2)

    first_half = line[:half_length]
    second_half = line[half_length:]

    for char in first_half:
        if second_half.find(char) != -1:
            sum += calculate_value(char)
            break

print(f"Sum: {sum}")
