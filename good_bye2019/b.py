t = int(input())

for _ in range(t):
    n = int(input())
    arr = list(map(int, input().split()))
    flag = True
    for i in range(1, n):
        if abs(arr[i] - arr[i - 1]) >= 2:
            print("YES")
            print(i, i + 1)
            flag = False
            break
    if flag:
        print("NO")