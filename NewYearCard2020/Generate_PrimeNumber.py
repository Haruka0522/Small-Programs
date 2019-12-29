from math import sqrt


#xより小さい素数のリストを生成
def Generate_PrimeNumber(x):
    #2以下の素数はない
    if x < 2:
        return []

    primes  = [i for i in range(x)]
    primes[1] = 0  #1を素数から除く

    sqrt_x = sqrt(x)

    #エラトステネスのふるい
    for prime in primes:
        if prime > sqrt_x:
            break
        if prime == 0:
            continue
        for non_prime in range(2*prime,x,prime):
            primes[non_prime] = 0

    return [prime for prime in primes if prime != 0]

if __name__ == '__main__':
    x = int(input("入力した数未満の素数を全列挙します"))
    print(Generate_PrimeNumber(x))
