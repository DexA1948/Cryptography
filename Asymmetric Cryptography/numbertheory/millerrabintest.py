import math
import random
import sympy as sp


def traditional(n):
    if n == 1 or n == 2:
        return 'Prime'

    npt1 = math.floor(math.sqrt(n))+1

    for i in range(2, npt1):
        if n % i == 0:
            return False
    return True


def findkq(n):
    fkq1 = int(math.log(n, 2))
    n = int(n-1)
    for i in range(fkq1):
        if n % 2 == 0:
            n = n / 2
        else:
            return i, int(n)
    return i+1, int(n)


def Miller_Rabin(n):
    k, q = findkq(n)
    a = random.randint(2, n-1)
    msg = f'{n}-1 = 2 ^ {k} * {q}, let a = {a}'
    print(msg)
    if pow(a, q) % n == 1:
        return str(n)+" is Prime (1)"
    for i in range(k):
        if pow(a, pow(2, i) * q) % n == n-1:
            return str(n)+" is Prime"
    return str(n)+" is Composite"


def bool_Miller_Rabin(n):
    k, q = findkq(n)
    a = random.randint(2, n-1)
    if pow(a, q) % n == 1:
        return True
    for i in range(k):
        if pow(a, pow(2, i) * q) % n == n-1:
            return True
    return False


def testmiller():
    # only odd numbers as inputs
    list_prime = []
    for en in range(3, 100, 2):
        if bool_Miller_Rabin(en):
            list_prime.append(en)
    print("\nList of all prime number generated using Python's inbuilt function sympy.primerange: ")
    print(list(sp.primerange(3, 100)))
    print("\nList of all prime number generated using our algorithm: ")
    print(list_prime)
    print("\nTesting for all odd numbers between 3-100")
    print("\nn-1 = 2 ^ q * k, 2 < a < n\n")
    for en in range(3, 100, 2):
        print(Miller_Rabin(en), end="\n\n")
