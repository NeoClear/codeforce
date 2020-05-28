t = int(input())

for p in range(t):
    n, m = map(int, input().split())
    stack = list(map(int, input().split()))
    send = list(map(int, input().split()))
    depth = [0] * (n + 1)
    for i in range(n):
        depth[stack[i]] = i
    ans = 0
    max_dep = -1
    for i in range(m):
        gift = send[i]
        if depth[gift] > max_dep:
            max_dep = depth[gift]
            ans += (max_dep - i) * 2 + 1
        else:
            ans += 1
    print(ans)