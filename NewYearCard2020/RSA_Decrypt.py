from math import gcd
from sympy import factorint
from gmpy import invert

def Decrypt(encrypted_text_ord,N,E):
    print("素因数分解開始")
    factorition = list(factorint(N).keys())
    P,Q = factorition[0],factorition[1]
    print("素因数分解完了")
    print("P="+str(P))
    print("Q="+str(Q))
    D = invert(E,(P-1)*(Q-1))
    plain_text_ord =str(pow(encrypted_text_ord,D,N))
    plain_text_ord = [plain_text_ord[i:i+2] for i in range(0,len(plain_text_ord),2)]
    plain_text = "".join([chr(int(num)) for num in plain_text_ord])
    return plain_text

if __name__ == '__main__':
    encrypted_text = int(input())
    N = int(input())
    plaintext = Decrypt(encrypted_text,N,65537)
    print("plaintext is '"+plaintext+"'")
