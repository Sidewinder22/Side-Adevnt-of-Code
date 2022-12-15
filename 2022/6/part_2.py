#!/usr/bin/python3

file_name = "input"
lines = []

with open(file_name) as file:
    lines = file.readlines()

datastream = lines[0]

for i in range (14, len(datastream)):
    marker = datastream[i-14:i] 

    found_double_chars = False
    for x in range (0, 14):
        for y in range(0, 14):
            if x == y:
                continue
            elif marker[x] == marker[y]:
                found_double_chars = True
    
    if not found_double_chars:
        print("*** Valid marker found ***")
        break

print(f"Result: {i}")
