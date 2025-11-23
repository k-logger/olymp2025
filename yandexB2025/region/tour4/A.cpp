#include <bits/stdc++.h>
using namespace std;
#define int long long
#define sz(x) (int)(x.size())
#define all(x) x.begin(), x.end()

void solve() {
    int n, q; cin >> n >> q;
    vector<int> a(n);
    int s = 0;
    for (int i=0; i < n; i++) {
        cin >> a[i];
    }
    if (n == 1) {
        cout << (a[0]/100)*(100-q);
        return;
    }
    sort(all(a), greater());
    vector<int> dp(n + 1);
    dp[0] = 0;
    dp[1] = (a[0]/100) * (100-q);
    dp[2] = dp[1] + (a[1]/100)*(100-q);
    for (int i=3; i <= n; i++) {
        dp[i] = min({
            dp[i-1] + (a[i-1]/100) * (100-q),
            dp[i-2] + ((a[i-1] + a[i-2])/100) * (100-q),
            dp[i-3] + a[i-2] + a[i-3]
        });
    }
    cout << dp[n];
}

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int tt = 1;
//     cin >> tt;
    while (tt--) solve();
}
