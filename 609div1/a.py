from typing import List

def expand(rep: List[int], digits: int) -> List[int]:
    pattern = []
    pattern.extend(rep)
    k = len(rep)
    while len(pattern) < digits:
        pattern.append(pattern[-k])
    return pattern

def inc(pattern: List[int]) -> None:
    pattern[-1] += 1
    d = 1
    while pattern[-d] == 10:
        pattern[-d] = 0
        pattern[-d - 1] += 1
        d += 1

n, k = map(int, input().split())
y = input().strip("\n")
number = []
for d in y:
    number.append(int(d))

pat = number[:min(k, len(number))]

while expand(pat, len(number)) < number:
    inc(pat)

ans = ""
for d in expand(pat, len(number)):
    ans += str(d)
print(len(ans))
print(ans)