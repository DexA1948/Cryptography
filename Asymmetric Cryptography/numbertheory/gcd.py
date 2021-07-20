def gcd(a, b):
    if b == 0:
        return a
    else:
        while b != 0:
            a, b = b, a % b
    return a
