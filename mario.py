# import sys
import sys

# main
def main():

    # get a number
    while True:
        n = int(input("Enter a number: "))
        if n >= 0 and n <= 23:
            break
    m = 1

    # interate and print
    for i in range(n):
        for x in range(n - m):
            print(" ", end = "")

        for x in range(m):
            print("#", end ="")

        print("#")
        m += 1


if __name__=="__main__":
    main()