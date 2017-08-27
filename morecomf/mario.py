# import sys
import sys

# main starts from here
def main():

    # get a number
    while True:
        n = int(input("Enter a number no greater than 23: "))
        if n >= 0 and n <= 23:
            break

    # iterate
    for i in range(n):
        print(" " *(n - i - 1), end = "")

        print("#" *(i + 1), end = "")

        # spacer
        print(" ", end = "")

        print("#" *(i + 1))

if __name__ == "__main__":
    main()