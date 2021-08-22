# Python3.9

import sys
import time
import random

class Colors:
    HEADER = '\033[95m'
    OK_BLUE = '\033[94m'
    OK_CYAN = '\033[96m'
    OK_GREEN = '\033[92m'
    WARNING = '\033[93m'
    FAIL = '\033[91m'
    END = '\033[0m'
    BOLD = '\033[1m'
    UNDERLINE = '\033[4m'

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
    print("usage: " + sys.argv[0] + " [-r | --random] " + 
            "[-c <pangram> | --custom <pangram>] [-h | --help]")

def commands():
    print("commands: \n" +
            ":r\t\t - Set a new random pangram.\n" +
            ":c <pangram>\t - Set a new custom pangram.\n" +
            ":q\t\t - Quit the program.")

def print_curr_sentence():
    global match_sentence
    print("======== " + match_sentence + " ========")

def set_custom_pangram(custom):
    global match_sentence, total_score

    match_sentence = custom
    total_score = len(match_sentence)
    print_curr_sentence()

def set_random_pangram():
    global match_sentence, total_score

    match_sentence = PANGRAMS[random.randint(0, len(PANGRAMS) - 1)]
    total_score = len(match_sentence)
    print_curr_sentence()

def parse_arguments():
    #TODO(Garz4): Add more arguments.

    if sys.argv[1] == "-c" or sys.argv[1] == "--custom" and len(sys.argv == 3):
        set_custom_pangram(sys.argv[2])
    elif sys.argv[1] == "-r" or sys.argv[1] == "--random":
        set_random_pangram()
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
def print_score(curr_score, time_needed):
    global total_score

    percentage = (curr_score * 100) / total_score

    # Determine the color based on the current percentage score.
    # TODO(Garz4): Make this class methods, something like
    # colors.print(std::string msg, colors::COLOR)
    if percentage < 25:
        print(Colors.FAIL, end = "")
    elif percentage < 50:
        print(Colors.WARNING, end = "")
    elif percentage < 75:
        print(Colors.OK_BLUE, end = "")
    else:
        print(Colors.OK_GREEN, end = "")

    print("You scored " +
            str(curr_score) +
            " out of " +
            str(total_score) +
            " in " +
            str(time_needed) +
            "s.")

    # Get back to original color (at least in VS Code).
    print(Colors.END, end = "")

def read_command(command):
    if command == ":q":
        exit(0)
    elif command == ":r":
        set_random_pangram()
        return
    elif command.startswith(":c"):
        if " " in command:
            space = command.index(" ")
            set_custom_pangram(command[space+1:len(command)])
            return

    print("Not a recognized command!")
    commands()

def main():
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
        print_score(curr_score, end - start)

if __name__ == '__main__':
    if len(sys.argv) < 2:
        usage()
        exit(0)
    else:
        parse_arguments()
        main()
