#include <iostream>
#include <vector>
#include <set>
#include <map>
#include <queue>
using namespace std;

typedef long long ll;
#define fi first
#define se second
#define mp make_pair

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int n, m, k; cin >> n >> m >> k;
    vector < pair <int, int> > adj[n];
    map < pair <int, int>, int> idx;
    for (int i = 1; i <= m; i++) {
        int x, y, w; cin >> x >> y >> w;
        x--; y--;
        adj[x].push_back(mp(y, w));
        adj[y].push_back(mp(x, w));
        idx[mp(x, y)] = i;
        idx[mp(y, x)] = i;
    }
    vector <ll> d(n, 1e18), pre(n, -1);
    d[0] = 0; pre[0] = -1;
    set < pair <ll, ll> > q;    //Dijkstra
    q.insert(mp(0, 0));
    while (!q.empty()) {
        pair <ll, ll> v = *(q.begin());
        q.erase(v);
        int u = v.se;
        for (int i = 0; i < adj[u].size(); i++) {
            ll v = adj[u][i].fi;
            ll w = adj[u][i].se;
            if (d[u] + w < d[v]) {
                pair <int, int> p = mp(d[v], v);
                if (q.find(p) != q.end()) {
                    q.erase(p);
                }
                pre[v] = u;
                d[v] = d[u] + w;
                q.insert(mp(d[v], v));
            }
        }
    }
    vector <int> tree_adj[n], vis(n);
    for (int i = 1; i < n; i++) {
        tree_adj[pre[i]].push_back(i);
        tree_adj[i].push_back(pre[i]);
    }
    vector < pair <int, int> > rem_edges;
    queue <int> qq; 
    qq.push(0); vis[0] = 1;
    while (rem_edges.size() < k && !qq.empty()) {    //BFS
        int u = qq.front(); qq.pop();
        for (int i = 0; i < tree_adj[u].size() && rem_edges.size() < k; i++) {
            int v = tree_adj[u][i];
            if (!vis[v]) {
                vis[v] = 1;
                rem_edges.push_back(mp(u, v));
                qq.push(v);
            }
        }
    }
    cout << rem_edges.size() << '\n';
    for (int i = 0; i < rem_edges.size(); i++) {
        cout << idx[rem_edges[i]] << ' ';
    }
    cout << '\n';
    return 0;
}