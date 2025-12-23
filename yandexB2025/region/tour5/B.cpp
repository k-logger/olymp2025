#include <bits/stdc++.h>
using namespace std;
#define int long long
#define ld long double
#define sz(x) (int)(x.size())
#define all(x) x.begin(), x.end()
const int INF = (int)(1e10);

void solve() {
    int n, k; cin >> n >> k;
    vector<pair<int, int>> ev;
    for (int i=0; i < n; i++) {
        int l, r; cin >> l >> r;
        ev.push_back({l, -1});
        ev.push_back({r, 1});
    }
    sort(all(ev));
    int cnt = 0, start = 0, ans = 0;
    for (auto& [x, y] : ev) {
        cnt -= y;
        if (cnt == n && y == -1) {
            start = x;
        }
        if (cnt == n-1 && y == 1) {
            ans += x - start + 1;
        }
    }
    cout << ans;
}

signed main() {
    int t = 1;
    // cin >> t;
    while (t--) solve();
}
