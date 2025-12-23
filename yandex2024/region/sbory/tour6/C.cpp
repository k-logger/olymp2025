#include <bits/stdc++.h>
using namespace std;
#define int long long
#define ld long double
#define sz(x) (int)(x.size())
#define all(x) x.begin(), x.end()

vector<vector<pair<int, int>>> g;

void solve() {
    int n, k; cin >> n >> k;
    g.resize(n);
    for (int i=0; i < n; i++) {
        int u, v, w; cin >> u >> v >> w;
        u--; v--;
        g[u].push_back({v, w});
        g[v].push_back({u, w});
    }
    cout << n << '\n';
    for (int i=0; i < n; i++) cout << i + 1 << " ";
}

signed main() {
    int t=1;
    while (t--) solve();
}
