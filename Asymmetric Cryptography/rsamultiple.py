def extendedEuclid(m, b):
    a1, a2, a3 = 1, 0, m
    b1, b2, b3 = 0, 1, b

    while True:
        q = int(a3/b3)

        t1 = a1-q*b1
        t2 = a2-q*b2
        t3 = a3-q*b3

        a1 = b1
        a2 = b2
        a3 = b3
        b1 = t1
        b2 = t2
        b3 = t3

        if b3 == 0 or b3 == 1:
            break

    if b3 == 0:
        print("\nInverse Doesn't Exist")
        exit(1)
    else:
        return b1


def gcd(a, b):
    if b == 0:
        return a
    else:
        while b != 0:
            a, b = b, a % b
    return a


def eulartotient(n):
    totientnumber=0
    for i in range(1,n):
        if gcd(n, i) == 1:
            totientnumber += 1
    return totientnumber


# let two prime numbers p and q
p, q = 5, 19

# calculate n
# 91
n = p * q

# calculate Euler's totient of n
t = eulartotient(n)

# let e be a relatively prime number to t
# calculate d such that e * d = 1 (mod t)
e = 5
d = extendedEuclid(e, t)
print("\nD is: ", d)

m = input("\nEnter a message to be encrypted: ")
m = m.lower()
print(m)

for i in m:
    print("\nAscii Value: ", ord(i))

    m = (ord(i) - 97)
    print("\n0-26 Value: ", m)

    # Encryption
    c = pow(m, e) % n
    print("\nEncrypted Text is: ", c)

    # Decryption
    m2 = pow(c, d) % n
    print("\nDecrypted text is: ", m2)
    print("\nDecrypted text is: ", chr(m2+97))
