#include <bits/stdc++.h>
using namespace std;

#define int long long
#define all(x) x.begin(), x.end()
#define sz(x) (int)(x.size())
#define ld long double


int cnt = 0;
void dfs(int v, vector<vector<int>>& g, int p=-1) {
    cnt++;
    for (int u : g[v]) {
        if (u != p) {
            dfs(u, g, v);
        }
    }
}

void solve() {
    int n; cin >> n;
    vector<int> l(n);
    for (int i=0; i < n; i++) cin >> l[i];
    vector<pair<int, int>> e;
    for (int i=0; i < n-1; i++) {
        int u, v; cin >> u >> v;
        u--; v--;
        e.push_back({u, v});
        e.push_back({v, u});
    }

    for (int mask = 0; mask < (1 << sz(e)); mask++) {
        vector<vector<int>> g(n);
        for (int i=0; i < sz(e); i++) {
            if ((mask >> i) & 1) {
                g[e[i].first].push_back(e[i].second);
            }
        }
        bool fl = true;
        for (int i=0; i < n; i++) {
            cnt = 0;
            dfs(i, g);
            if (l[i] != cnt) fl = false;
        }
        if (fl) {
            cout << "YES";
            return;
        }
    }
    cout << "NO";
}

signed main() {
    int t = 1;
    while (t--) solve();
}
