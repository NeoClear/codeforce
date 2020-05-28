#include <iostream>
#include <cstdio>
#include <cctype>
#include <algorithm>
#include <cstring>

#define SIZE 200010
#define inf 0xffffffff

typedef long long ll;

using namespace std;

ll read() {
    ll ans = 0, f = 1; char ch = getchar();
    while (!isdigit(ch)) { if (ch == '-') f = -1; ch = getchar(); }
    while (isdigit(ch)) { ans = ans * 10 + ch - '0'; ch = getchar(); }
    return ans * f;
}

ll item[SIZE];
ll acc[SIZE];

int main() {
    // freopen("in.txt", "r", stdin);
    ll N = read();
    for (ll i = 0; i < N; i++) {
        ll n = read(), p = read(), k = read();
        for (ll t = 0; t < n; t++) { item[t] = read(); }
        sort(item, item + n);
        memset(acc, 0, sizeof(acc));
        ll j;
        ll flag = -1;
        bool go = true;
        for (j = 0; j < n; j++) {
            ll acc1 = (j < 0 ? 0 : acc[j - 1]) + item[j];
            ll acc2 = j < k - 1 ? inf : (j < k ? 0 : acc[j - k]) + item[j];
            acc[j] = min(acc1, acc2);
            // cout << acc[j] << endl;
            if (acc[j] <= p) {
                flag = j;
            }
        }
        printf("%lld\n", flag + 1);
    }
    return 0;
}