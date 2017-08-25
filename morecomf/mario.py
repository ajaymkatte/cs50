# import sys
import sys

# main starts from here
def main():

    m = 1

    # get a number
    while True:
        n = int(input("Enter a number no greater than 23: "))
        if n >= 0 and n <= 23:
            break

    # iterate
    for i in range(n):
        for x in range(n - m):
            print(" ", end = "")

        for x in range(m):
            print("#", end = "")

        # spacer
        print(" ", end = "")

        for x in range(m):
            print("#", end = "")

        # print a new line
        print("")

        m += 1

if __name__ == "__main__":
    main()