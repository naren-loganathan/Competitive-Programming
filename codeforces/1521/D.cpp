#include <iostream>
#include <vector>
#include <set>
#include <algorithm>
using namespace std;

typedef long long ll;
#define fi first
#define se second
#define mp make_pair

vector < set <int> > adj(1e5);
vector <int> vis(1e5), deg(1e5), par(1e5), ord, leaf;

set < pair <int, int> > rem_edges, add_edges;

void dfs1(int v, int parent) {  //assigning parents, finding the order of visits
    ord.push_back(v);
    par[v] = parent;
    set <int> :: iterator i;
    for (i = adj[v].begin(); i != adj[v].end(); i++) {
        int u = *i;
        if (u != parent) dfs1(u, v);
    }
}

void dfs2(int v) {  //selecting vertices of degree 1 in each CC
    vis[v] = 1;
    if (deg[v] == 1) leaf.push_back(v);
    set <int> :: iterator i;
    for (i = adj[v].begin(); i != adj[v].end(); i++) {
        int u = *i;
        if (vis[u] == 0) dfs2(u);
    }
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int t; cin >> t;
    while (t--) {
        int n; cin >> n;
        ord.clear();
        add_edges.clear(); 
        rem_edges.clear();
        for (int i = 0; i < n; i++) {
            adj[i].clear();
            vis[i] = 0; deg[i] = 0; par[i] = -1;
        }
        for (int i = 1; i < n; i++) {
            int a, b; cin >> a >> b;
            a -= 1; b -= 1;
            deg[a]++; deg[b]++;
            adj[a].insert(b); 
            adj[b].insert(a);
        }
        dfs1(0, -1);
        for (int k = n - 1; k >= 0; k--) {
            int i = ord[k];
            if (deg[i] > 2) {
                if (par[i] != -1) {
                    rem_edges.insert(mp(i + 1, par[i] + 1));
                    adj[i].erase(par[i]);
                    adj[par[i]].erase(i);
                    deg[i]--; deg[par[i]]--;
                }
                while (deg[i] > 2) {
                    int j = *adj[i].begin();
                    adj[i].erase(j);
                    adj[j].erase(i);
                    rem_edges.insert(mp(i + 1, j + 1));
                    deg[i]--; deg[j]--;
                }
            }
        }
        vector < pair <int, int> > link;
        vector <int> one;
        for (int i = 0; i < n; i++) {
            if (!vis[i]) {
                if (deg[i] == 0) {
                    vis[i] = 1;
                    one.push_back(i);
                } else {
                    leaf.clear(); dfs2(i);
                    link.push_back(mp(leaf[0], leaf[1]));
                }
            }
        }
        for (int i = 0; i + 1 < one.size(); i++) {
            add_edges.insert(mp(one[i] + 1, one[i + 1] + 1));
        }
        if (!link.empty() && !one.empty()) add_edges.insert(mp(one.back() + 1, link[0].fi + 1));
        for (int i = 1; i < link.size(); i++) {
            add_edges.insert(mp(link[i - 1].se + 1, link[i].fi + 1));
        }
        set < pair <int, int> > :: iterator i1, i2;
        i1 = rem_edges.begin();
        i2 = add_edges.begin();
        cout << rem_edges.size() << '\n';
        for (int i = 0; i < rem_edges.size(); i++) {
            cout << i1 -> fi << ' ' << i1 -> se << ' ' << i2 -> fi << ' ' << i2 -> se << '\n';
            i1++; i2++;
        }
    }
    return 0;
}