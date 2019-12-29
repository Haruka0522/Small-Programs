def is_prime(q):
    q = abs(q)
    if q == 2: return True
    if q < 2 or q&1 == 0: return False
    return pow(2, q-1, q) == 1

if __name__ == '__main__':
    i = 2**1024
    while True:
        if is_prime(i):
            print(i)
        i += 1
