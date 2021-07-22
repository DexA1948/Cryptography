# this files are present in repo inside number theory 
import eulartotient as et
import extendedeuclid as ee


# let two prime numbers p and q
p, q = 7, 13

# calculate n
# 91
n = p * q

# calculate Euler's totient of n
t = et.eulartotient(n)

# let e be a relatively prime number to t
# calculate d such that e * d = 1 (mod t)
e = 5
d = ee.extendedEuclid(e, t)

# Encryption
m = input("\nEnter a message to be encrypted: ")
c = pow(ord(m), e) % n

# Decryption
m2 = pow(c, d) % n
print("\nEncrypted text is: ", chr(m2))
