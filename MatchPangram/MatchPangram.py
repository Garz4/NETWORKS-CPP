# MIT License
#
# Copyright (c) 2021 Uriel Rivas
#
# Permission is hereby granted, free of charge, to any person obtaining a copy
# of this software and associated documentation files (the "Software"), to deal
# in the Software without restriction, including without limitation the rights
# to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
# copies of the Software, and to permit persons to whom the Software is
# furnished to do so, subject to the following conditions:
#
# https://github.com/Garz4/zoning/blob/master/LICENSE

# Python3.9

import random
import sys
import time

class Colors:
    HEADER = '\033[95m'
    OK_BLUE = '\033[94m'
    OK_CYAN = '\033[96m'
    OK_GREEN = '\033[92m'
    WARNING = '\033[93m'
    FAIL = '\033[91m'
    BOLD = '\033[1m'
    UNDERLINE = '\033[4m'
    DEFAULT = '\033[0m'

PANGRAMS = ["Waltz, bad nymph, for quick jigs vex.",
        "Glib jocks quiz nymph to vex dwarf.",
        "Sphinx of black quartz, judge my vow.",
        "How vexingly quick daft zebras jump!",
        "The five boxing wizards jump quickly.",
        "Jackdaws love my big sphinx of quartz.",
        "Pack my box with five dozen liquor jugs.",
        "The quick brown fox jumps over a lazy dog."]

match_sentence = ""
total_score = 0

def usage():
    print(
        "Usage: " + sys.argv[0] +
        "[-c <pangram> | --custom <pangram>] [-h | --help]"
    )

def commands():
    print(
        "Commands: \n" +
        ":r\t\t - Set a new random pangram.\n" +
        ":c <pangram>\t - Set a new custom pangram.\n" +
        ":q\t\t - Quit the program."
    )

def print_curr_sentence():
    global match_sentence

    print("======== " + match_sentence + " ========")

def set_pangram(pangram):
    global match_sentence, total_score

    match_sentence = pangram
    total_score = len(match_sentence)
    print_curr_sentence()

def random_pangram():
    return PANGRAMS[random.randint(0, len(PANGRAMS) - 1)]

def parse_arguments():
    #TODO(Garz4): Add more arguments.

    if len(sys.argv) >= 2:
        if ((sys.argv[1] == "-c" or sys.argv[1] == "--custom") and
                len(sys.argv) > 2):
            set_pangram(" ".join(sys.argv[2 : len(sys.argv)]))
        else:
            usage()
            exit(0)

# Matches the current sentence against the global pangram `match_sentence`.
def match_against(curr_sentence):
    # TODO(Garz4): Match like Source Control matches new code.

    global match_sentence

    j = 0
    curr_score = 0
    for c in match_sentence:
        if j < len(curr_sentence) and c == curr_sentence[j]:
            j += 1
            curr_score += 1

    return curr_score

# Prints the current score using colors. Kawaii!
def print_score(curr_score, time_needed, time_diff):
    global total_score

    percentage = (curr_score * 100) / total_score

    # Determine the color based on the current percentage score.
    # TODO(Garz4): Make these class methods, something like
    # colors.print(std::string msg, colors::COLOR)
    if percentage < 50:
        print(Colors.FAIL, end = "")
    else:
        print(Colors.OK_GREEN, end = "")

    print("You scored " +
            str(curr_score) +
            " out of " +
            str(total_score) +
            " in " +
            str(round(time_needed, 2)) +
            "s.")

    if time_diff < 0:
        print(Colors.OK_BLUE + str(round(-1 * time_diff, 2)) + "s. faster!")
    elif time_diff > 0:
        print(Colors.WARNING + str(round(time_diff, 2)) + "s. slower!")
    else:
        print(Colors.BOLD + "Perfectly balanced... As all things should be...")

    # Get back to original color.
    print(Colors.DEFAULT, end = "")

def read_command(command):
    if command == ":q":
        exit(0)
    elif command == ":r":
        set_pangram(random_pangram())
        return
    elif command.startswith(":c"):
        if " " in command:
            space = command.index(" ")
            set_pangram(command[space + 1 : len(command)])
            return

    print("Not a recognized command!")
    commands()

def main():
    parse_arguments()

    prev_time = 0

    while True:
        # Time that bad boy.
        start = time.time()
        curr_sentence = input()
        end = time.time()

        # Continue with the loop whether its a command or empty line.
        if not curr_sentence:
            continue
        elif curr_sentence.startswith(":"):
            read_command(curr_sentence)
            continue

        # Compute current score and print it.
        curr_score = match_against(curr_sentence)
        curr_time = end - start
        print_score(curr_score, curr_time, curr_time - prev_time)
        prev_time = curr_time

if __name__ == '__main__':
    main()
