#include <iostream>
#include <cstring>
#include <cstdio>
#include <cctype>
#include <algorithm>
#include <cstdlib>

#define N 300

typedef long long ll;

using namespace std;

ll interact(string w) {
    cout << w << endl;
    int diff;
    cin >> diff;
    if (diff)
        return diff;
    exit(0);
}

// diff_a == 300 - a
// diff_b == 300 - b

int main() {
    ll a_num, b_num, n;
    a_num = N - interact(string(300, 'a'));
    b_num = N - interact(string(300, 'b'));
    n = a_num + b_num;

    string s(n, 'a');
    ll diff = b_num;

    for (ll i = 0; i < n - 1; i++) {
        s[i] = 'b';
        if (interact(s) > diff)
            s[i] = 'a';
        else
            diff--;
    }
    if (diff)
        s.back() = 'b';
    interact(s);
    return 0;
}