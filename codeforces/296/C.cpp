#include <iostream>
#include <vector>
using namespace std;

typedef long long ll;
#define fi first
#define se second
#define mp make_pair

//Overkill?
template <typename T>
struct Fenwick {
    const int n; vector <T> tree;
    Fenwick(int n) : n(n), tree(n) {}
    void update(int x, T v) {
        for (int i = x; i < n; i = (i | (i + 1))) {
            tree[i] += v;
        }
    }
    T sum(int x) {
        T ans = 0;
        for (int i = x; i >= 0; i = (i & (i + 1)) - 1) {
            ans += tree[i];
        }
        return ans;
    }
    void range_update(int l, int r, T v) {
        update(l, v);
        if (r + 1 < n) {
            update(r + 1, -v);
        }
    }
    T point_query(int x) {
        return sum(x);
    }
};

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    ll n, m, k; cin >> n >> m >> k;
    Fenwick <ll> t(n);
    for (int i = 0; i < n; i++) {
        ll a; cin >> a;
        t.range_update(i, i, a);
    }
    vector <ll> l(m), r(m), d(m), pre(m);
    for (int i = 0; i < m; i++) {
        cin >> l[i] >> r[i] >> d[i];
        l[i]--; r[i]--;
    }
    while (k--) {
        int x, y; cin >> x >> y;
        x--; y--;
        pre[x] += 1;
        if (y + 1 < m) {
            pre[y + 1] -= 1;
        }
    }
    for (int i = 1; i < m; i++) {
        pre[i] += pre[i - 1];
    }
    for (int i = 0; i < m; i++) {
        t.range_update(l[i], r[i], d[i] * pre[i]);
    }
    for (int i = 0; i < n; i++) {
        cout << t.point_query(i) << ' ';
    }
    cout << '\n';
    return 0;
}