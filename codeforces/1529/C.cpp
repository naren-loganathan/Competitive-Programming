#include <iostream>
#include <vector>
#include <cmath>
using namespace std;            

typedef long long ll;
#define fi first
#define se second
#define mp make_pair

vector < vector <int> > adj(1e5);
vector <int> par(1e5), ord;

ll val = 0;

void dfs(int u, int parent) {
    par[u] = parent; ord.push_back(u);
    for (int i = 0; i < adj[u].size(); i++) {
        if (adj[u][i] != parent) {
            dfs(adj[u][i], u);
        }
    }
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int t; cin >> t;
    while (t--) {
        int n; cin >> n;
        vector <ll> r(n), l(n), dl(n), dr(n);
        ord.clear();
        for (int i = 0; i < n; i++) {
            adj[i].clear();
            cin >> l[i] >> r[i];
        }
        for (int i = 1; i < n; i++) {
            int u, v; cin >> u >> v;
            u--; v--;
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        dfs(0, -1);
        for (int i = n - 1; i > 0; i--) {
            int u = par[ord[i]], v = ord[i];
            dl[u] += max(dl[v] + abs(l[u] - l[v]), dr[v] + abs(l[u] - r[v]));
            dr[u] += max(dl[v] + abs(r[u] - l[v]), dr[v] + abs(r[u] - r[v]));
        }
        cout << max(dl[0], dr[0]) << '\n';
    }
    return 0;
}