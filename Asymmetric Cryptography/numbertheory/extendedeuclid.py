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
