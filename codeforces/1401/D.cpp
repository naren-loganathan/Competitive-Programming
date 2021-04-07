#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
using namespace std;

typedef long long ll;
#define fi first
#define se second
#define mp make_pair

ll mod = 1e9 + 7;

vector <ll> cnt(1e5);
vector < vector <int> > adj(1e5);

void dfs(int i, int parent) {
    cnt[i] = 1;
    for (int j = 0; j < adj[i].size(); j++) {
        if (adj[i][j] != parent) {
            dfs(adj[i][j], i);
            cnt[i] += cnt[adj[i][j]];
        }
    }
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int t; cin >> t;
    while (t--) {
        ll n, ans = 0; cin >> n;
        for (int i = 0; i < n; i++) {
            adj[i].clear();
            cnt[i] = 0;
        }
        for (int i = 1; i < n; i++) {
            int u, v; cin >> u >> v;
            u -= 1; v -= 1;
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        int m; cin >> m;
        vector <ll> p(m);
        for (int i = 0; i < m; i++) {
            cin >> p[i];
        }
        sort(p.begin(), p.end(), greater <ll> ());
        dfs(0, -1);
        vector <ll> pdt;
        for (int i = 0; i < n; i++) {
            pdt.push_back(cnt[i] * (n - cnt[i]));
        }
        sort(pdt.begin(), pdt.end(), greater <ll> ());
        pdt.pop_back(); n -= 1;
        for (int i = 0; i < n; i++) {
            pdt[i] %= mod;
        }
        if (m < n) {
            for (int i = 0; i < m; i++) {
                pdt[i] = (pdt[i] * p[i]) % mod;
            }
        } else {
            int it = 0;
            while (it <= m - n) {
                pdt[0] = (pdt[0] * p[it]) % mod;
                it += 1;
            }
            for (; it < m; it++) {
                pdt[it - (m - n)] = (pdt[it - (m - n)] * p[it]) % mod;
            }
        }
        for (int i = 0; i < n; i++) {
            ans = (ans + pdt[i]) % mod;
        }
        cout << ans << '\n';
    }
    return 0;
}