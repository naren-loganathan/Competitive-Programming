#include <iostream>
#include <vector>
using namespace std;

typedef long long ll;
#define fi first
#define se second
#define mp make_pair

ll op(ll t, ll curr, ll x) {
    if (t == 1) {
        return (curr + (x + 1e5 - 1) / 1e5);
    } else {
        return ((curr * x + 1e5 - 1) / 1e5);
    }
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    ll n, m; cin >> n >> m;
    vector <int> vis(m + 1), ans(m + 1, -1);
    vis[0] = 1, ans[0] = 0;
    for (int i = 1; i <= n; i++) {
        vector <int> new_vis = vis;
        ll t, x, y; cin >> t >> x >> y;
        for (int j = 0; j <= m; j++) {
            if (vis[j]) {
                ll curr = op(t, j, x);
                for (int a = 1; a <= y; a++) {
                    if (curr > m || vis[curr]) {
                        break;
                    } else {
                        new_vis[curr] = 1;
                        ans[curr] = i;
                        curr = op(t, curr, x);
                    }
                }
            }
        }
        vis = new_vis;
    }
    for (int i = 1; i <= m; i++) {
        cout << ans[i] << ' ';
    }
    cout << '\n';
    return 0;
}