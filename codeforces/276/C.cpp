#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
     
typedef long long ll;
#define fi first
#define se second
#define mp make_pair
#define N 200005

int n;
ll fenwick_tree[N] = {};

void update (int idx, ll val) {
    while (idx <= n) {
        fenwick_tree[idx] += val;
        idx += (idx & (-idx));
    }
}

ll point_query (int idx) {
    ll sum = 0;
    while (idx > 0) {
        sum += fenwick_tree[idx];
        idx -= (idx & (-idx));
    }
    return sum;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int q, l, r; 
    cin >> n >> q;
    vector <ll> a(n + 1, 0), f(n + 1, 0);
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
    }
    sort(a.begin(), a.end());
    while (q--) {
        cin >> l >> r;
        update(l, 1); update(r + 1, -1);
    }
    for (int i = 1; i <= n; i++) {
        f[i] = point_query(i);
    }
    sort (f.begin(), f.end());
    ll sum = 0, j = n;
    for (int i = n; i > 0; i--) {
        sum += f[i] * a[i];
    }
    cout << sum << "\n";
    return 0;
}