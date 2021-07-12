import sys
import time

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

def usage():
    print("")


def match_against(curr_sentence, match_sentence):
    j = 0
    curr_score = 0
    for c in match_sentence:
        if j < len(curr_sentence) and c == curr_sentence[j]:
            j += 1
            curr_score += 1
    return curr_score


def main(match_sentence, total_score):
    while True:
        start = time.time()
        curr_sentence = raw_input()
        end = time.time()
        curr_score = match_against(curr_sentence, match_sentence)
        print(
            "You scored ",
            curr_score,
            " out of ",
            total_score,
            " in ",
            end-start,
            "s.")

if __name__ == '__main__':
    argc = len(sys.argv)
    if argc is not 2:
        usage()
    else:
        main(sys.argv[1], len(sys.argv[1]))
