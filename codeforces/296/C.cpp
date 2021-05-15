#include <iostream>
#include <vector>
using namespace std;

typedef long long ll;
#define fi first
#define se second
#define mp make_pair

//Yeah, that was a bit overkill...

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    ll n, m, k; cin >> n >> m >> k;
    vector <ll> t(n), add(n);
    for (int i = 0; i < n; i++) {
        cin >> t[i];
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
        ll inc = pre[i] * d[i];
        add[l[i]] += inc;
        if (r[i] + 1 < n) {
            add[r[i] + 1] -= inc;
        }
    }
    for (int i = 1; i < n; i++) {
        add[i] += add[i - 1];
    }
    for (int i = 0; i < n; i++) {
        cout << t[i] + add[i] << ' ';
    }
    cout << '\n';
    return 0;
}