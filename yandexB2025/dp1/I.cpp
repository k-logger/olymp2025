#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const int mod = (ll)(1e9) + 9;
vector<int> primes = {};

void solve() {
    int n; cin >> n;
    for (int i = 100; i < 1000; i++) {
        bool fl = false;
        for (int j = 2; j * j <= i; j++) {
            if (i % j == 0) {
                fl = true;
                break;
            }
        }
        if (!fl) primes.push_back(i);
    }
    vector<vector<ll>> dp(n+1, vector<ll>(100));
    for (auto& x : primes) {
        dp[3][x%100] = (dp[3][x%100] + 1) % mod;
    }
    for (int len = 4; len <= n; len++) {
        for (auto& x : primes) {
            dp[len][x%100] = (dp[len][x%100] + dp[len-1][x/10]) % mod;
        }
    }
    ll ans = 0;
    for (int i = 0; i < 100; i++) {
        ans = (ans + dp[n][i]) % mod;
    }
    cout << ans;
}

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int tt = 1;
//    cin >> tt;
    while (tt--) solve();
}
