for _ in range(int(input())):
    _ = input()
    line = input().lstrip("P")
    ans = 0
    for sect in line.split("A"):
        ans = max(ans, len(sect))
    print(ans if ans < len(line) else 0)