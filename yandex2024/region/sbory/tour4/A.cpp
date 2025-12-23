#include <bits/stdc++.h>
using namespace std;

#define int long long
#define ld long double
#define all(x) x.begin(), x.end()
#define sz(x) (int)(x.size())

void solve() {
    int n, k; cin >> n >> k;
    vector<int> a(n);
    for (int i=0; i < n; i++) cin >> a[i];
    vector<int> b = a;
    sort(all(b));
    b.erase(unique(all(b)), b.end());
    for (auto& x : a) {
        x = lower_bound(all(b), x) - b.begin();
    }
    int l = 0, r = 0;
    vector<int> cnt(n + 1);
    multiset<int> st;
    st.insert(1);
    for (int i=0; i < n-1; i++) st.insert(0);
    cnt[a[0]]++;
    int ans = 1;
    while (l < n) {
        while (r < n) {
            r++;
            if (r >= n) break;
            st.erase(st.find(cnt[a[r]]));
            cnt[a[r]]++;
            st.insert(cnt[a[r]]);
            int mx = *prev(st.end());
            if ((r-l+1)-mx <= k) {
                ans = max(ans, r-l+1);
            } else {
                break;
            }
        }
        st.erase(st.find(cnt[a[l]]));
        cnt[a[l]]--;
        st.insert(cnt[a[l]]);
        l++;
    }
    cout << ans;
}

signed main() {
    int t = 1;
    while (t--) solve();
}
