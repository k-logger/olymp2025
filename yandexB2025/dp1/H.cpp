#include <bits/stdc++.h>
using namespace std;
using ll = long long;

void solve() {
    int n; cin >> n;
    vector<vector<ll>> dp(n+1, vector<ll>(10));
    if (n == 1) {
        cout << 9;
        return;
    }
    for (int j=1; j < 10; j++) {
        dp[1][j] = 1;
    }
    for (int j=0; j < 10; j++) {
        for (int k=1; k < 10; k++) {
            if (abs(j-k) <= 1) {
                dp[2][j] += dp[1][k];
            }
        }
    }

    for (int len = 3; len <= n; len++) {
        for (int i = 0; i < 10; i++) {
            for (int k = 0; k < 10; k++) {
                if (abs(i-k) <= 1) {
                    dp[len][i] += dp[len-1][k];
                }
            }
        }
    }
    ll s = 0;
    for (int j=0; j < 10; j++) {
        s += dp[n][j];
    }
    cout << s;
}

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int tt = 1;
//    cin >> tt;
    while (tt--) solve();
}
