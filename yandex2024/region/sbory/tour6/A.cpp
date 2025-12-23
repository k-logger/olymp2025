#include <bits/stdc++.h>
using namespace std;
#define int long long
#define ld long double
#define sz(x) (int)(x.size())
#define all(x) x.begin(), x.end()

void solve() {
    int n; cin >> n;
    for (int i=n; i <= (int)1e18; i++) {
        string s = to_string(i);
        int sum = 0;
        for (int j=0; j < sz(s); j++) {
            if (j % 2 == 0) sum += (s[j] - '0');
            else sum -=  (s[j] - '0');
        }
        if (__gcd(i, abs(sum)) > 1) {
            cout << i;
            return;
        }
    }
}

signed main() {
    int t=1;
    while (t--) solve();
}
