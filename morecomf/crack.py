# cracks a password of five characters, hope to cut down on the copy paste someday
# https://github.com/ajaymkatte/pset2/blob/master/morecomf/crack.c five characters implementation in c

# does not handle non-character

# import sys and crypt
import sys
import crypt

def main():

    # check if the argv
    if(len(sys.argv) != 2):
        print("error")
        exit(2)

    # get salt
    salt = sys.argv[1][0] + sys.argv[1][1]
    n = 0

    # one character long password
    for i in range(52):
        alpha = getalpha(i)
        check(alpha, salt)

    # two characters long
    for i in range(52):
        alpha0 = getalpha(i)
        for i in range(53):
            alpha1 = getalpha(i)
            password = alpha0 + alpha1
            check(password, salt)

    # three characters long
    for i in range(52):
        alpha0 = getalpha(i)
        for i in range(53):
            alpha1 = getalpha(i)
            for i in range(53):
                alpha2 = getalpha(i)
                password = alpha0 + alpha1 + alpha2
                check(password, salt)

    # four characters long
    for i in range(52):
        alpha0 = getalpha(i)
        for i in range(53):
            alpha1 = getalpha(i)
            for i in range(53):
                alpha2 = getalpha(i)
                for i in range(53):
                    alpha3 = getalpha(i)
                    password = alpha0 + alpha1 + alpha2 + alpha3
                    check(password, salt)

    # five characters long
    for i in range(52):
        alpha0 = getalpha(i)
        for i in range(53):
            alpha1 = getalpha(i)
            for i in range(53):
                alpha2 = getalpha(i)
                for i in range(53):
                    alpha3 = getalpha(i)
                    for i in range(53):
                        alpha4 = getalpha(i)
                        password = alpha0 + alpha1 + alpha2 + alpha3 + alpha4
                        check(password, salt)

    # if all else fails
    print("no luck")

# give alpha
def getalpha(n):
    if n < 26:
        alpha = chr(65 + n)
    else:
        alpha = chr(65 + n + 6)
    return alpha

# check correctness of the password
def check(password, salt):
    if sys.argv[1] == crypt.crypt(password, salt):
        print("{}".format(password))
        exit(0)

if __name__ == "__main__":
    main()