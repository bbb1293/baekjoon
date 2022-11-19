import sys;

# sys.stdin = open("input.txt", "r")
paper = [[False for i in range(100)] for j in range(100)]

n = int(input())
while n > 0:
    n -= 1
    x, y = map(int, input().split())

    for i in range(10):
        for j in range(10):
            paper[y + i][x + j] = True

cnt = 0
for y in range(100):
    for x in range(100):
        if (paper[y][x]):
            cnt += 1

print(cnt)