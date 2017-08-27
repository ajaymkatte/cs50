# import sys
import sys

# main starts here
def main():

    # get change owed
    n = float(input("Enter the change owed: "))

    change = 0

    # iterate through all the available coins
    while True:
        if n >= 0.25:
            n -= 0.25
        else:
            break
        change += 1

    while True:
        if n >= 0.1:
            n -= 0.1
        else:
            break
        change += 1

    while True:
        if n >= 0.05:
            n -= 0.05
        else:
            break
        change += 1

    if n >= 0.01:
        change = change + (n / 0.01)

    # sanity check
    if n > 0:
        change += 1

    print("{}".format(change))

if __name__ == "__main__":
    main()
