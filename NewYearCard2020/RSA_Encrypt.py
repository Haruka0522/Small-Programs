from math import gcd

def lcm(x,y):
    return (x*y) // gcd(x,y)

def ExtendedEuclideanAlgorithm(a,b):
    if b == 0:
        u = 1
        v = 0
    else:
        q = a / b
        r = a % b
        (u0,v0) = ExtendedEuclideanAlgorithm(b,r)
        u = u0
        v = u0 - q * v0
    return (u,v)

# gcd(a,b) と ax + by = gcd(a,b) の最小整数解を返す
def egcd(a, b):
    if a == 0:
        return b, 0, 1
    else:
        g, y, x = egcd(b % a, a)
        return g, x - (b // a) * y, y

def GenerateKeys(P,Q):
    N = P * Q
    L = lcm(P-1,Q-1)
    E = 65537
    #D = ExtendedEuclideanAlgorithm(E,L)[0]
    D = egcd(E,L)[0]
    if D < 0:
        D += 1
    return ((N,E),(N,D)) #N,Eが公開鍵、Dは秘密鍵

def Encrypt(encrypt_text,public_keys):
    N,E = public_keys
    text_ord = [ord(text) for text in list(encrypt_text)]
    text_ord = int("".join(map(str,text_ord)))
    print(text_ord)
    encrypted = pow(text_ord,E,N)
    return encrypted,public_keys


if __name__ == '__main__':
    p = 18446744073709863911
    q = 18446744073709862201

    public_key,private_key = GenerateKeys(p,q)
    plain_text = input()
    encrypted_text,public_key = Encrypt(plain_text,public_key)
    print("encrypted text is'"+str(encrypted_text)+"'")
    print("E="+str(public_key[1]))
    print("N="+str(public_key[0]))
