// buggy

#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cctype>
#include <algorithm>
#include <vector>
#include <unordered_map>

#define MOD 998244353

typedef long long ll;

using namespace std;

ll read() {
    ll ans = 0, f = 1; char ch = getchar();
    while (!isdigit(ch)) { if (ch == '-') f = -1; ch = getchar(); }
    while (isdigit(ch)) { ans = ans * 10 + ch - '0'; ch = getchar(); }
    return ans * f;
}

ll extend_gcd(ll a, ll b, ll& x, ll& y) {
    if (b == 0) { x = 1; y = 0; return a; }
    ll ret = extend_gcd(b, a % b, x, y);
    ll temp = y;
    y = x - (a / b) * y;
    x = temp;
    return ret;
}

ll gcd(ll a, ll b) {
    if (b == 0) { return a; }
    return gcd(b, a % b);
}

pair<ll, ll> add_fraction(pair<ll, ll> a, pair<ll, ll> b) {
    pair<ll, ll> ret;
    ll common = gcd(a.second, b.second);
    a.first *= b.second / common;
    b.first *= a.second / common;
    ret.first = a.first + b.first;
    ret.second = (a.second / common) * b.second;
    ll div = gcd(ret.first, ret.second);
    ret.first /= div;
    ret.second /= div;
    return ret;
}

ll N;

int main() {
    // freopen("in.txt", "r", stdin);
    N = read();
    vector<vector<ll>> want(N);
    unordered_map<ll, ll> gift_needed;
    vector<pair<ll, ll>> prob(N);
    for (ll p = 0; p < N; p++) {
        ll k = read();
        for (ll q = 0; q < k; q++) {
            ll gift = read();
            want[p].push_back(gift);
            gift_needed[gift]++;
        }
    }

    for (ll i = 0; i < N; i++) {
        ll sum = 0;
        for (const auto& gift : want[i]) { sum += gift_needed[gift]; }
        prob[i].first = sum;
        prob[i].second = want[i].size();
        ll div = gcd(prob[i].first, prob[i].second);
        prob[i].first /= div;
        prob[i].second /= div;
    }
    // for i-th kid, the probability that his ai gift is 1 / N * 1 / ki * gift_needed[ai] / N
    // for the same kid

    pair<ll, ll> ans = {0, 1};
    for (const auto& it : prob)
        ans = add_fraction(ans, it);
    ans.second *= N * N;
    ll inverse_y, space;
    extend_gcd(ans.second, MOD, inverse_y, space);
    while (inverse_y < 0) { inverse_y += MOD; }
    while (inverse_y > MOD) { inverse_y -= MOD; }
    ll content = ((ans.first % MOD) * (inverse_y % MOD)) % MOD;
    printf("%lld\n", content);
    return 0;
}