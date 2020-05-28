#include <iostream>
#include <cctype>

typedef unsigned long long ll;

using namespace std;

ll arr[100010];

ll read() {
    ll ans = 0; char ch = getchar();
    while (!isdigit(ch)) { ch = getchar(); }
    while (isdigit(ch)) { ans = ans * 10 + ch - '0'; ch = getchar(); }
    return ans;
}

// 1 + 1 = 10
// 1 ^ 1 = 0
// 1 + 0 = 1
// 1 ^ 0 = 1
// 0 + 0 = 0
// 0 ^ 0 = 0

// 1 0 0 1 1 0
// 0 0 0 1 1 1

ll get_bit(ll n, ll b) {
    return (n >> b) && 0x1;
}

int main() {
    ll t = read();
    for (ll i = 0; i < t; i++) {
        ll n = read();
        for (ll k = 0; k < n; k++) { arr[k] = read(); }
        int carry[64] = {}, stay[64] = {};
        for (ll b = 0; b < 64; b++) {
            ll acc0 = 0, acc1 = 0;
            for (ll k = 0; k < n; k++) {
                ll ele = arr[k];
                if (get_bit(acc1, b) ^ get_bit(ele, b))
                    stay[b]++;
                if (get_bit(acc0, b) && get_bit(ele, b))
                    carry[b]++;
                acc0 += ele;
                acc1 ^= ele;
            }    
        }
        int diff[64];
        for (ll b = 0; b < 64; b++) { diff[b] = carry[b] * 2 - stay[b]; }
        // 1 & 1: diff += 2 diff
        // 1 & 0: diff
    }
    return 0;
}