#include <bits/stdc++.h>

using namespace std;

int T;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> T;
    int N, M;
    while (T--) {
        cin >> N >> M;
        cout << (N * M + 1) / 2 << endl;
    }
    return 0;
}
