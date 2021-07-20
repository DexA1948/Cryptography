import gcd


def eulartotient(n):
    totientnumber=0
    for i in range(1,n):
        if gcd.gcd(n, i) == 1:
            totientnumber += 1
    return totientnumber