t = int(input())

for _ in range(t):
    n, k = map(int, input().split())
    a = n // k
    print(min(a * k + k // 2, n))