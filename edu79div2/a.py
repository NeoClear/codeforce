t = int(input())

for i in range(t):
    colors = list(map(int, input().split()))
    print("No" if max(colors) * 2 > sum(colors) + 1 else "Yes")