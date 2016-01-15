#! /usr/bin/python3

import subprocess
import os
import sys

GREEN = '\033[92m'
RED = '\033[91m'
BOLD = "\033[1m"
ENDC = '\033[0m'
FNULL = open(os.devnull, 'w')

class suite:
    def __init__(self):
        self.failed = 0
        self.passed = 0

    def call_on_dir(self, test_dir):
        for f in os.listdir(test_dir):
            file_name = test_dir + f
            ret = subprocess.call(["./bin/nolimia32", file_name],
                                  stdout=FNULL, stderr=FNULL)
            if ret == 0:
                print(BOLD + GREEN + os.path.basename(file_name) + ENDC)
                self.passed += 1
            else:
                print(BOLD + RED + os.path.basename(file_name) + ENDC)
                self.failed += 1
def normalize(path):
    if path[len(path) - 1] != '/':
        path += '/'

    return path

if __name__ == '__main__':
    tests = suite()
    tests.call_on_dir(normalize(sys.argv[1]))
    print("Tests: " + BOLD + " "
          + str(tests.passed) + " / " + str(tests.passed + tests.failed) + ENDC)
