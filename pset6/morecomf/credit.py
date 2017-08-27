# import sys
import sys
import cs50

# main starts here
def main():

    cc = int(input("Enter the credit card number: "))

    n , odd, even = 0, 0, 0

    # checksum
    while True:
        last = (cc % 10)
        cc = int(cc / 10)
        if n % 2 != 0:
            add = last * 2
            even += int((add / 10)) + (add % 10)
        else:
            odd += last

        n += 1

        if (cc <= 9):
            break

    # checksum for first number of the cc
    if n % 2 != 0:
        add = cc * 2
        even += int((add / 10)) + (add % 10)
    else:
        odd += cc


    check = (cc * 10) + last

    # check if the card is valid
    if (odd + even) % 10 == 0:
        if cc == 4:
            print("Visa")
        elif check == 34 or check == 37:
            print("AMEX")
        elif check == 51 or check == 52 or check == 53 or check == 54 or check == 55:
            print("MasterCard")
        else:
            print("invalid card")
    else:
        print("invalid card")


if __name__ == "__main__":
    main()