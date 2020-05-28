t = int(input())

for p in range(t):
    n, s = map(int, input().split())
    verse = list(map(int, input().split()))
    if sum(verse) <= s:
        print(0)
        continue
    ans = -1
    max_index = 0
    sums = 0
    for i in range(len(verse)):
        sums += verse[i]
        if verse[i] > verse[max_index]:
            max_index = i
        if sums - verse[max_index] <= s:
            ans = max_index
        else:
            break
    print(ans + 1)