#include <bits/stdc++.h>
using namespace std;
#define int long long
#define sz(x) (int)(x.size())
#define all(x) x.begin(), x.end()

unordered_map<int, int> fact(int x) {
    unordered_map<int, int> mp;
    if (x == 1) {
        return mp;
    }
    for (int i=2; i * i <= x; i++) {
        if (x % i == 0) {
            while (x % i == 0) {
                mp[i]++;
                x/=i;
            }
        }
    }
    if (x > 1) mp[x]++;
    return mp;
}
struct number {
    unordered_map<int, int> p;
    number(int x) {
        p = fact(x);
    }
    number(unordered_map<int, int> pp) {
        p = pp;
    }
};

number operator*(number l, number r) {
    unordered_map<int, int> res;
    for (auto& [k, v] : l.p) {
        res[k] += v;
    }
    for (auto& [k, v] : r.p) {
        res[k] += v;
    }
    return number(res);
}

number operator/(number l, number r) {
    unordered_map<int, int> res;
    for (auto& [k, v] : l.p) {
        res[k] += v;
    }
    for (auto& [k, v] : r.p) {
        res[k] -= v;
    }
    return number(res);
}

void print_ans(number t) {
    unordered_map<int, int> res = t.p;
    bool fl = false;
    for (auto& [x, y] : res) {
        if (y != 0) {
            fl = true;
            break;
        }
    }
    if (!fl) {
        cout << "1 1";
        return;
    }
    vector<pair<int, int>> ans;
    for (auto& [x, y] : res) {
        if (y != 0) {
            ans.push_back({x, y});
        }
    }
    sort(all(ans));
    for (auto& [x, y] : ans) {
        cout << x << " " << y << '\n';
    }
}


vector<int> a, b;
number dfs(int x, int y, int type) {
    if (x + 1 == y) {
        return (number(a[x]) * number(a[x+1])) / number(b[y-1]);
    }
    if (x - 2 == y) {
        return (number(b[y]) * number(b[y+1])) / number(a[x-1]);
    }
    if (type == 0) {
        return (number(a[x]) * number(a[y])) / dfs(y, x, 1 - type);
    } else {
        return (number(b[y]) * number(b[x-1])) / dfs(y+1, x-1, 1 - type);
    }
}

void solve() {
    int n; cin >> n;
    a.resize(n); b.resize(n-1);
    for (int i=0; i < n; i++) cin >> a[i];
    for (int i=0; i < n-1; i++) cin >> b[i];
    int p, q; cin >> p >> q;
    p--; q--;
    if (p == q) {
        print_ans(a[p]);
        return;
    }
    if (p - 1 == q) {
        print_ans(b[q]);
        return;
    }
    int type;
    if (p < q) type = 0;
    else type = 1;
    print_ans(dfs(p, q, type));
}

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int tt = 1;
//     cin >> tt;
    while (tt--) solve();
}
