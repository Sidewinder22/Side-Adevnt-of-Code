#!/usr/bin/python3

# A,X -> Rock
# B,Y -> Paper
# C,Z -> Scissors

dict_scores = {"A": 1, "B": 2, "C": 3, "X": 1, "Y": 2, "Z": 3}

def process_line(line):
    [opponent_input, my_input] = line.rstrip().split(' ')

    opponent_value = int(dict_scores[opponent_input])
    my_value = int(dict_scores[my_input])

    print(f"[{opponent_input}] : {opponent_value} <-> {my_input}: {my_value}")

    result = 0
    if my_value == opponent_value:
        result += 3
    else:
        if opponent_input == "A" and my_input == "Y":
            result += 6
        elif opponent_input == "B" and my_input == "Z":
            result += 6
        elif opponent_input == "C" and my_input == "X":
            result += 6

    result += my_value

    print(f"result: {result}")
    return result


file_name = "input"
lines = []
sum = 0

with open(file_name) as file:
    lines = file.readlines()

for line in lines:
    sum += process_line(line)
    print(f"sum: {sum}")

print(f"Sum: {sum}")
