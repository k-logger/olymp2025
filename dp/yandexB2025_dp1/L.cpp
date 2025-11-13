#include <bits/stdc++.h>
using namespace std;

using ll = long long;

void solve() {
    int n, w; cin >> n >> w;
    vector<int> a(n);
    for (int i=0; i < n; i++) cin >> a[i];
    bitset<6300000> dp;
    dp |= 1;
    for (int i=0; i < n; i++) {
        dp |= (dp << a[i]);
    }
    cout << ((dp[w]) ? "YES" : "NO");
}

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int tt = 1;
//    cin >> tt;
    while (tt--) solve();
}
