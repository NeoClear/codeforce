#include <iostream>
#include <cstdio>
#include <cctype>
#include <algorithm>

typedef long long ll;

using namespace std;

ll read() {
    ll ans = 0, f = 1; char ch = getchar();
    while (!isdigit(ch)) { if (ch == '-') f = -1; ch = getchar(); }
    while (isdigit(ch)) { ans = ans * 10 + ch - '0'; ch = getchar(); }
    return ans * f;
}

int main() {
    // freopen("in.txt", "r", stdin);
    ll N = read();
    ll a, b, c, r;
    for (ll i  = 0; i < N; i++) {
        a = read(); b = read(); c = read(); r = read();
        ll left = min(a, b), right = max(a, b);
        ll leftr = max(left, min(right, c - r));
        ll rightr = min(right, max(left, c + r));
        printf("%lld\n", (leftr - left) + (right - rightr));
    }
}