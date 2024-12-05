#!/usr/bin/python

file = open("input");
first_list = []
second_list = []
for line in file:
    fields = line.strip().split()
    first_list.append(int(fields[0]))
    second_list.append(int(fields[1]))

first_list = sorted(first_list)
second_list = sorted(second_list)

result = 0
for i in range (1000):
    result += abs(first_list[i] - second_list[i])

print(f"Result: {result}")
