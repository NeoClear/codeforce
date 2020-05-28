n = int(input())

friend = list(map(int, input().split()))

available = {}
connect = {}

for i in range(1, n + 1):
    if friend[i - 1] == 0:
        connect[i] = 1
    if i not in friend:
        available[i] = 1

same = []
diff = []

for i in connect:
    if i in available:
        same.append(i)
        del available[i]
    else:
        diff.append(i)

print(same)
print(diff)

if (len(same) != 1):
    for i in range(len(same)):
        friend[same[i]] = same[i - 1]
    for i in available:
        friend[diff[-1]] = i
        del diff[-1]
else:
    available[same[i]] = 1
    cnt = 0
    for i in available:
        frient[diff[cnt]] = i
        cnt += 1
        

ans = ""

for i in friend:
    ans += str(i) + " "

print(ans)