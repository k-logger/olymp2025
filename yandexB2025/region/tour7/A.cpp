#include <bits/stdc++.h>
using namespace std;

#define int long long
#define all(x) x.begin(), x.end()
#define sz(x) (int)(x.size())
#define ld long double

void solve() {
    int n; cin >> n;
    string s; cin >> s;
    queue<int> q1, q2;
    int res = 0;
    for (int i=0; i < n; i++) {
        while (!q1.empty() && !q2.empty() && q2.front() < q1.front()) q2.pop();
        if (s[i] == '1') q1.push(i);
        if (s[i] == '2') q2.push(i);
        if (s[i] == '3') {
            if (!q1.empty() && !q2.empty()) {
                q1.pop();
                q2.pop();
                res += 3;
            }
        }
    }
    cout << res;
}

signed main() {
    int t = 1;
    while (t--) solve();
}
