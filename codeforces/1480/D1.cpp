#include <iostream>
#include <vector>
using namespace std;

typedef long long ll;
#define fi first
#define se second
#define mp make_pair

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int n; cin >> n;
    vector <int> a(n + 1, 1e9), nxt(n + 1, 1e9), m[n + 1], x, y;
    for (int i = 0; i < n; i++) {
        cin >> a[i];
        m[a[i]].push_back(i);
    }
    for (int i = 1; i <= n; i++) {
        for (int j = 0; j + 1 < m[i].size(); j++) {
            nxt[m[i][j]] = m[i][j + 1];
        }
    }
    x.push_back(n); y.push_back(n);
    for (int i = 0; i < n; i++) {
        bool eqx = (a[i] == a[x.back()]);
        bool eqy = (a[i] == a[y.back()]);
        if (eqx && !eqy) {
            y.push_back(i);
        } else if (!eqx && !eqy) {
            if (nxt[x.back()] <= nxt[y.back()]) {
                x.push_back(i);
            } else {
                y.push_back(i);
            }
        } else {
            x.push_back(i);
        }
    }
    int ans = 0;
    for (int i = 1; i < x.size(); i++) {
        if (a[x[i]] != a[x[i - 1]]) ans++;
    }
    for (int i = 1; i < y.size(); i++) {
        if (a[y[i]] != a[y[i - 1]]) ans++;
    }
    cout << ans << '\n';
    return 0;
}