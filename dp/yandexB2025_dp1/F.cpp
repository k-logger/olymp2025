#include <bits/stdc++.h>
using namespace std;

using ll = long long;

void solve() {
    int s; cin >> s;

    vector<vector<vector<int>>> dp(10, vector<vector<int>>(10, vector<int>(82)));
    for (int k = 1; k <= 9; k++) {
        dp[1][k][k] = 1;
    }
    for (int i=0; i < 10; i++) {
        for (int j=1; j < 10; j++) {
            for (int sum = 0; sum < 19; sum++) {
                if (sum >= i) {
                    dp[2][i][sum] += dp[1][j][sum-i];
                }
            }
        }
    }
    for (int len=3; len < 10; len++) {
        for (int sum=0; sum < 82; sum++) {
            for (int j=0; j < 10; j++) {
                for (int k=0; k < 10; k++) {
                    if (sum >= j) {
                        dp[len][j][sum] += dp[len-1][k][sum-j];
                    }
                }
            }
        }
    }
    int ans = 0;
    for (int len = 1; len < 10; len++) {
        for (int k=0; k < 10; k++) {
            ans += dp[len][k][s];
        }
    }
    if (s == 1) ans++;
    cout << ans;
}

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int tt = 1;
//    cin >> tt;
    while (tt--) solve();
}
