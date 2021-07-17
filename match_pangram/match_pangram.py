# Python3.9

# Pangrams:
# 
# Waltz, bad nymph, for quick jigs vex.
# Glib jocks quiz nymph to vex dwarf.
# Sphinx of black quartz, judge my vow.
# How vexingly quick daft zebras jump!
# The five boxing wizards jump quickly.
# Jackdaws love my big sphinx of quartz.
# Pack my box with five dozen liquor jugs.
# The quick brown fox jumps over a lazy dog.

import sys
import time

# To store and the colors when printing in terminal.
class bcolors:
    HEADER = '\033[95m'
    OKBLUE = '\033[94m'
    OKCYAN = '\033[96m'
    OKGREEN = '\033[92m'
    WARNING = '\033[93m'
    FAIL = '\033[91m'
    ENDC = '\033[0m'
    BOLD = '\033[1m'
    UNDERLINE = '\033[4m'

# Print how to use the program and exits.
def usage():
    # TODO(Garz4): Actually print a usage lol.

    print("")


# Matches the current sentence against the original pangram.
def match_against(curr_sentence, match_sentence):
    # TODO(Garz4): Match like Source Control matches new code.

    j = 0
    curr_score = 0
    for c in match_sentence:
        if j < len(curr_sentence) and c == curr_sentence[j]:
            j += 1
            curr_score += 1
    return curr_score

# Prints the current score using colors. Kawaii!
def print_score(curr_score, total_score, time_needed):
    percentage = (curr_score * 100) / total_score

    if percentage < 25:
        print(bcolors.FAIL)
    elif percentage < 50:
        print(bcolors.WARNING)
    elif percentage < 75:
        print(bcolors.OKBLUE)
    else:
        print(bcolors.OKGREEN)

    print("You scored " +
            str(curr_score) +
            " out of " +
            str(total_score) +
            " in " +
            str(time_needed) +
            "s.")

    # Get back to original color (at least in PowerShell).
    print(bcolors.ENDC)

# Main function.
def main(match_sentence, total_score):
    print("========" + match_sentence + "========")
    while True:
        start = time.time()
        curr_sentence = input()

        # Quit.
        if curr_sentence == ":q":
            break

        end = time.time()
        
        # Compute current score and print it.
        curr_score = match_against(curr_sentence, match_sentence)
        print_score(curr_score, total_score, end-start)

# Call main with current arguments or print usage and exist.
if __name__ == '__main__':
    argc = len(sys.argv)
    if argc != 2:
        usage()
    else:
        main(sys.argv[1], len(sys.argv[1]))
