#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
using namespace std;            

typedef long long ll;
#define fi first
#define se second
#define mp make_pair

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int n, m; cin >> n >> m;
    vector < vector < vector <int> > > adj(2, vector < vector <int> > (n));
    for (int i = 0; i < m; i++) {
        int u, v; cin >> u >> v;
        u--; v--;
        adj[0][u].push_back(v);
        adj[1][v].push_back(u);
    }
    int dist[2][n][n];
    for (int k = 0; k < 2; k++) {
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                dist[k][i][j] = (i != j ? 1e4 : 0);
            }
        }
    }
    for (int i = 0; i < n; i++) {
        for (int k = 0; k < 2; k++) {
            queue <int> q; 
            q.push(i);
            while (!q.empty()) {
                int u = q.front(); q.pop();
                for (int j = 0; j < adj[k][u].size(); j++) {
                    int v = adj[k][u][j];
                    if (dist[k][i][v] == 1e4) {
                        dist[k][i][v] = dist[k][i][u] + 1;
                        q.push(v);
                    }
                }
            }
        }
    }
    vector < vector < pair <int, int> > > f(n), r(n);
    for (int k = 0; k < 2; k++) {
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (i != j && dist[k][i][j] < 1e4) {
                    if (k == 0) {
                        f[i].push_back(mp(-dist[k][i][j], j));
                    } else {
                        r[i].push_back(mp(-dist[k][i][j], j));
                    }
                }
            }
        }
    }
    for (int i = 0; i < n; i++) {
        sort(f[i].begin(), f[i].end());
        sort(r[i].begin(), r[i].end());
    }
    int a, b, c, d, total_dist = 0;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (i != j && dist[0][i][j] < 1e4) {
                int curr = dist[0][i][j];
                vector < pair <int, int> > x, y;
                int idx = 0;
                while (x.size() < 2 && idx < f[j].size()) {
                    if (f[j][idx].se != i) {
                        x.push_back(f[j][idx]);
                    }
                    idx += 1;
                }
                idx = 0;
                while (y.size() < 2 && idx < r[i].size()) {
                    if (r[i][idx].se != j) {
                        y.push_back(r[i][idx]);
                    }
                    idx += 1;
                }
                int a_new = -1, d_new = -1, m = 0;
                for (int p = 0; p < x.size(); p++) {
                    for (int q = 0; q < y.size(); q++) {
                        if (x[p].se != y[q].se) {
                            if ((-1) * (x[p].fi + y[q].fi) > m) {
                                m = (-1) * (x[p].fi + y[q].fi);
                                d_new = x[p].se;
                                a_new = y[q].se;
                            }
                        }
                    }
                }
                if (a_new != -1 && d_new != -1) {
                    curr += m;
                    if (curr > total_dist) {
                        total_dist = curr;
                        a = a_new; d = d_new;
                        b = i; c = j;
                    }
                }
            }
        }
    }
    cout << a + 1 << ' ' << b + 1 << ' ' << c + 1 << ' ' << d + 1 << '\n';
    return 0;
}