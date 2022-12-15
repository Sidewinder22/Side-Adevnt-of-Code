#!/usr/bin/python3

# We can use list as a stack:
# https://docs.python.org/3/tutorial/datastructures.html#using-lists-as-stacks

def read_and_create_stacks(lines):
    stacks = {i: list() for i in range(1, 10, 1)} # create 9 stacks

    # process in reverse order to build stack from the bottom
    for x in range(7, -1, -1):
        line = lines[x]
        stack_number = 1

        for i in range(0, len(line), 4):
            crate = line[i : i+4]

            if crate.strip():
                stacks[stack_number].append(crate.rstrip())

            stack_number += 1

    return stacks

def read_and_process_commands(stacks):
    # commands are from 10 line to the end of lines
    for x in range(10, len(lines), 1):
        [amount, src, dest] = [int(word) for word in lines[x].split() if word.isdigit()]
        
        for i in range(0, amount):
            element = stacks[src].pop()
            stacks[dest].append(element)

file_name = "input"
lines = []

with open(file_name) as file:
    lines = file.readlines()

lines = [line.rstrip() for line in lines]

stacks = read_and_create_stacks(lines)
read_and_process_commands(stacks)

result = ""
for i in range(1, len(stacks)+1):
    result += stacks[i].pop().replace('[','').replace(']','')

print(f"Result: {result}")
