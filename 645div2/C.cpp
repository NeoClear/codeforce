#include <bits/stdc++.h>

typedef long long ll;

using namespace std;

ll T;
ll a1, a2, b1, b2;

int main() {
    cin >> T;
    while (T--) {
        cin >> a1 >> b1 >> a2 >> b2;
        ll dx = a2 - a1;
        ll dy = b2 - b1;
        ll ans = 0;
        ll K = min(dx, dy);
        ll V = max(dx, dy) - K;
        ans += K * (K - 1);
        ans += K * (V + 1);
        cout << ans + 1 << endl;
    }
    return 0;
}
