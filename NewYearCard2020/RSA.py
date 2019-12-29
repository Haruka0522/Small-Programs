from math import gcd
from sympy import factorint
from gmpy import invert

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
    return ((N,E),(N,D))

def Decrypt(encrypted_text_ord,N,E):
    print("素因数分解開始")
    factorition = list(factorint(N).keys())
    P,Q = factorition[0],factorition[1]
    print("素因数分解完了")
    D = invert(E,(P-1)*(Q-1))
    plain_text_ord =str(pow(encrypted_text_ord,D,N))
    plain_text_ord = [plain_text_ord[i:i+2] for i in range(0,len(plain_text_ord),2)]
    plain_text = "".join([chr(int(num)) for num in plain_text_ord])
    return plain_text

def Encrypt(encrypt_text,public_keys):
    N,E = public_keys
    text_ord = [ord(text) for text in list(encrypt_text)]
    text_ord = int("".join(map(str,text_ord)))
    encrypted = pow(text_ord,E,N)
    return encrypted

if __name__ == '__main__':
    p = 179769313486231590772930519078902473361797697894230657273430081157732675805500963132708477322407536021120113879871393357658789768814416622492847430639474124377767893424865485276302219601246094119453082952085005768838150682342462881473913110540827237163350510684586298239947245938479716304835356329624224138297
    q = 179769313486231590772930519078902473361797697894230657273430081157732675805500963132708477322407536021120113879871393357658789768814416622492847430639474124377767893424865485276302219601246094119453082952085005768838150682342462881473913110540827237163350510684586298239947245938479716304835356329624224137859
    public_keys,private_keys = GenerateKeys(p,q)
    print(public_keys)
    plaintext = input("plaintext")
    encrypted_text = Encrypt(plaintext,public_keys)
    print("encrypted text is "+str(encrypted_text))

    Decrypt_text = Decrypt(encrypted_text,public_keys[0],65537)
    print("plaintext is"+str(Decrypt_text))

