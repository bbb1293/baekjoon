import sys;

# sys.stdin = open("input.txt", "r")

non_prime = [False for i in range(8001)]

ret = 1
for i in range(2, 8001):
    if non_prime[i] == False:
        ret *= i

        for j in range(i + i, 8001, i):
            non_prime[j] = True

while True:
    n, t = map(int, sys.stdin.readline().split())

    if n == 0:
        break
    
    print(ret - 1, end='')
    
    for i in range(max(0, n - 3421)):
        print(9, end='')

    print()
