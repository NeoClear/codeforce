#include <iostream>
#include <cstdio>
#include <cctype>
#include <algorithm>
#include <cstring>

typedef long long ll;

using namespace std;

ll read() {
    ll ans = 0, f = 1; char ch = getchar();
    while (!isdigit(ch)) { if (ch == '-') f = -1; ch = getchar(); }
    while (isdigit(ch)) { ans = ans * 10 + ch - '0'; ch = getchar(); }
    return ans * f;
}

ll store[200010];

int main() {
    // freopen("in.txt", "r", stdin);
    ll N = read();
    for (ll i = 0; i < N; i++) {
        ll n = read(), p = read(), k = read();
        for (ll j = 0; j < n; j++) { store[j] = read(); }
        sort(store, store + n);
        ll j = 0;
        ll acc[2];
        memset(acc, 0, sizeof(acc));
        for (j = 0; j < n; j++) {
            acc[j % 2] += store[j];
            if (acc[j % 2] > p)
                break;
        }
        printf("%lld\n", j);
    }
    return 0;
}