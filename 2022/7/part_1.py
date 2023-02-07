#!/usr/bin/python3

# dirs and their content
dirs_content_dict = {}
dirs_level_stack = []
cd_command = "cd"
ls_command = "ls"
upper_command = ".."


def parse_lines():

    dir_content = []
    dir_name = ""    


    for line in lines:

        print(f"### stack: {dirs_level_stack}")
        # parse command (starting with $)
        if line[0] == "$":
            print(f">>> command: {line}")

            if line.find(ls_command) > 0:
                continue

            if dir_content and dir_name:
                print(f"+++, dir_content: {dir_content}")
                dirs_content_dict[dir_name] = dir_content
                dir_content = []
                dir_name = ""

            if line.find(cd_command) > 0:
                elements = line.split(" ")
                dir_name = elements[2]

                if dir_name == upper_command:
                    dirs_level_stack.pop()
                else:
                    dirs_level_stack.append(line)

        # parse output
        else:
            print(f"--> line: {line}")

            dir_content.append(line)


    # For the last entry
    if dir_content and dir_name:
        print(f"+++, after for dir_content: {dir_content}")
        dirs_content_dict[dir_name] = dir_content
        dir_content = []
        dir_name = ""


def parse_dirs_dict(dirs_content):
    for dir_name in dirs_content:
        for file_name in dirs_content[dir_name]:

            name_elements = file_name.split(' ')

            if name_elements[0] == "dir":

                dirs_content[dir_name].extend(dirs_content[name_elements[1]])
                dirs_content[dir_name].remove(file_name)

                parse_dirs_dict(dirs_content)
        
    return dirs_content




# file_name = "example" #"input"
file_name = "input"
lines = []

with open(file_name) as file:
    lines = file.readlines()

lines = [line.rstrip() for line in lines]
    
parse_lines()

print(dirs_content_dict)

print("----------- parsing dict -------------\n")

parse_dirs_dict(dirs_content_dict)

print("----------- parsing output -------------\n")
# print(dirs_content_dict)

d = parse_dirs_dict(dirs_content_dict)
print(d)


total_dirs_sum = 0
for dir_name in d:
    sum = 0

    for file_name in d[dir_name]:
        sum += int(file_name.split(' ')[0])

    if sum <= 100000:
        total_dirs_sum += sum
    
    print(f"{dir_name}: sum = {sum}")
    print(f"")

print(f"=== Total dirs <= 100000 sum is: {total_dirs_sum}")
