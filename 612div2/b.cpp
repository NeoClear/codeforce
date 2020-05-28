#include <iostream>

typedef long long ll;

using namespace std;

ll n, p;
ll value[1500] = {};

bool is_good(ll val) {
    for (ll i = 0; i < 64; i += 2) {
        ll v = (val >> i) & 0b11;
        if (!(v == 0b11 || v == 0b00))
            return false;
    }
    return true;
}

int main() {
    cin >> n >> p;
    
    for (ll i = 0; i < n; i++) {
        string s;
        cin >> s;
        ll it = 0;
        for (const auto& ch : s) {
            ll cur;
            if (ch == 'S')
                cur = 0;
            else if (ch == 'E')
                cur = 1;
            else if (ch == 'T')
                cur = 2;
            value[i] |= (cur << it);
            it += 2;
        }
    }
    ll cnt = 0;
    for (ll i = 0; i < n; i++) {
        for (ll j = i + 1; j < n; j++) {
            for (ll k = j + 1; k < n; k++) {
                if (is_good(value[i] + value[j] + value[k])) {
                    cnt++;
                }
            }
        }
    }
    cout << cnt << endl;
    return 0;
}