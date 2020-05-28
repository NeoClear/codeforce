#include <bits/stdc++.h>

using namespace std;

int T, N;
int granny[200010];

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> T;
    while (T--) {
        cin >> N;
        for (int i = 0; i < N; i++)
            cin >> granny[i];
        sort(granny, granny + N);
        int ans = N - 1;
        while (granny[ans] > ans + 1)
            ans--;
        cout << ans + 2 << endl;
    }
    return 0;
}
