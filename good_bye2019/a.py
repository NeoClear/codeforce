t = int(input())

for _ in range(t):
    n, k1, k2 = map(int, input().split())
    l1 = list(map(int, input().split()))
    l2 = list(map(int, input().split()))
    print("YES" if max(l1) > max(l2) else "NO")