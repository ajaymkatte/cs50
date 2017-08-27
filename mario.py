# import sys
import sys

# main
def main():

    # get a number
    while True:
        n = int(input("Enter a number: "))
        if n >= 0 and n <= 23:
            break

    # interate and print
    for i in range(n):
        print(" " *(n - i - 1), end = "")
        print("#" *(i + 2))

if __name__=="__main__":
    main()