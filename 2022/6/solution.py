#!/usr/bin/python3

def find_marker_distance_from_begin(datastream, marker_length):
    distance = 0

    for i in range (marker_length, len(datastream)):
        marker = datastream[i-marker_length:i] 

        found_double_chars = False
        for x in range (0, marker_length):
            for y in range(0, marker_length):
                if x == y:
                    continue
                elif marker[x] == marker[y]:
                    found_double_chars = True
        
        if not found_double_chars:
            print("*** Valid marker found ***")
            distance = i
            break
    return distance


file_name = "input"
lines = []

with open(file_name) as file:
    lines = file.readlines()

print(f"Part 1 result: {find_marker_distance_from_begin(lines[0], 4)}")
print(f"Part 2 result: {find_marker_distance_from_begin(lines[0], 14)}")
