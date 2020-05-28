#include <bits/stdc++.h>

typedef long long ll;

using namespace std;

ll N, X;
ll days[400000];

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> N >> X;
    for (ll i = N - 1; i >= 0; i--)
        cin >> days[i];
    for (ll i = 0; i < N; i++)
        days[i + N] = days[i];
    ll ans = 0, acc = 0, remain = X;
    ll tail = -1;
    for (ll i = 0; i < N; i++) {
        while (remain > 0) {
            tail++;
            remain -= days[tail];
            acc += (days[tail] + 1) * days[tail] / 2;
        }
        ans = max(ans, acc - (remain - 1) * remain / 2);
        remain += days[i];
        acc -= (days[i] + 1) * days[i] / 2;
    }
    cout << ans << endl;
    return 0;
}
