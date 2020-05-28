n = int(input())
domino = list(map(int, input().strip().split()))

# dye[0] means black, dye[1] means white
dye = [0] * 2

for i in range(len(domino)):
    dye[i % 2] += domino[i] // 2
    dye[(i + 1) % 2] += (domino[i] + 1) // 2

print(min(dye))