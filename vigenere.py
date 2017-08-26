# import sys
import sys

def main():

    # check correctness of keyword
    for c in sys.argv[1]:
        if ord(c) < 65 or (ord(c) > 91 and ord(c) < 97) or ord(c) > 122:
            exit(1)

    crack, text, n, i = sys.argv[1], input("plaintext: "), 0, 0
    final = list(text)

    # iterate through
    for c in text:

        # if the character is an alphabet
        if(ord(c) >= 65 and ord(c) <= 90) or (ord(c) >= 97 and ord(c) <= 122):

            # place of the alphabet
            if ord(c) >= 65 and ord(c) <= 90:
                numt = ord(c) - 65
            else:
                numt = ord(c) - 97

            # place of the alphabet
            if ord(crack[n]) >= 65 and ord(crack[n]) <= 90:
                numc = ord(crack[n]) - 65
            else:
                numc = ord(crack[n]) - 97

            # assign the new char accordingly
            if numc + numt <= 26:
                final[i] = chr(ord(c) + numc)
            else:
                final[i] = chr(ord(c) - (26 - numc))
            n += 1
            if n > len(crack) - 1:
                n = 0

        else:
            final[i] = c
        i += 1

    # print
    print("ciphertext: {}".format("".join(final)))

if __name__ == "__main__":
    main()