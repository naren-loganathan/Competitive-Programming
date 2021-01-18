#include <iostream>
#include <vector>
#include <set>
#include <algorithm>
using namespace std;
             
typedef long long ll;
#define fi first
#define se second
#define mp make_pair

vector < vector < pair <ll, ll> > > adj(1e5 + 1);
vector <ll> d(1e5 + 1, 1e15), p(1e5 + 1, -1);

void dijkstra () {
    d[1] = 0;
    set < pair <int, int> > q;
    q.insert(mp(0, 1));
    while (!q.empty()) {
        int v = q.begin() -> se;
        q.erase(q.begin());
        for (auto edge : adj[v]) {
            int len = edge.fi, to = edge.se;
            if (d[v] + len < d[to]) {
                q.erase(mp(d[to], to));
                d[to] = d[v] + len;
                p[to] = v;
                q.insert(mp(d[to], to));
            }
        }
    }
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int n, m, a, b, w; 
    cin >> n >> m;
    while (m--) {
        cin >> a >> b >> w;
        adj[a].push_back(mp(w, b));
        adj[b].push_back(mp(w, a));
    }
    dijkstra();
    if (d[n] == 1e15) {
        cout << "-1" << "\n";
    }
    else {
        vector <ll> path;
        path.push_back(n);
        ll v = n;
        while (v != 1) {
            path.push_back(p[v]);
            v = p[v];
        }
        reverse(path.begin(), path.end());
        for (auto u : path) {
            cout << u << " ";
        }
        cout << "\n";
    }
    return 0;
}
