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

    # lose
    if my_input == "X":
        if opponent_input == "A":
            result += 3             # scissors
        elif opponent_input == "B":
            result += 1             # rock
        else:
            result += 2             # paper
    # draw
    elif my_input == "Y":
        result += 3 + opponent_value
    # win
    else:
        result += 6
        if opponent_input == "A":
            result += 2             # paper
        elif opponent_input == "B":
            result += 3             # scissors
        else:
            result += 1            # rock

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
