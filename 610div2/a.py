N = int(input())

for i in range(N):
    a, b, c, r = map(int, input().split())
    left = min(a, b)
    right = max(a, b)
    leftr = max(left, c - r)
    rightr = min(right, c + r)
    print(min((leftr - left) + (right - rightr), right - left))