# cracks a password of length one for sanity check
# https://github.com/ajaymkatte/pset2/blob/master/morecomf/crack.c five characters implementation in c

# import sys and crypt
import sys
import crypt

def main():

    # check if the argv
    if(len(sys.argv) != 2):
        print("error")
        exit(2)

    # get salt
    salt = sys.argv[1][0], sys.argv[1][1]
    salt = "".join(salt)

    # iterate
    for i in range(26):
        password = chr(65 + i)
        check(password, salt)
    for i in range(26):
        password = chr(97 + i)
        check(password, salt)

    # if all else fails
    print("no luck")

# check correctness of the password
def check(password, salt):
    if sys.argv[1] == crypt.crypt(password, salt):
        print("{}".format(password))
        exit(0)

if __name__ == "__main__":
    main()