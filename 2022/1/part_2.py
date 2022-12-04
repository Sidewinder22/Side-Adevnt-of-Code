#!/usr/bin/python3

file_name = "input"
lines = []

with open(file_name) as file:
    lines = file.readlines()

one_elf_calories = []       # list
all_elves_calories = ()     # tuple

for line in lines:
    if line == "\n":
        # We can't add int to tuple; only tuple to tuple
        all_elves_calories = all_elves_calories + (sum(one_elf_calories),)
        one_elf_calories.clear()
        
    else:
        one_elf_calories.append(int(line))

# Sorte and reverse the tuple: max number will be on the first position
all_elves_calories = sorted(all_elves_calories, reverse=True)

calories = 0
for n in range(3):
    calories += all_elves_calories[n]

print(f"Calories of the three top Elves: {calories}")
