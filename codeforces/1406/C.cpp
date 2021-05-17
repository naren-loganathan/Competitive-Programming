#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;            

typedef long long ll;
#define fi first
#define se second
#define mp make_pair

vector < vector <int> > adj(1e5);
vector <int> cnt(1e5), par(1e5), centroids;

void centroid_dfs(int u, int parent, int n) {
    par[u] = parent; cnt[u] = 1;
    bool is_centroid = true;
    for (int i = 0; i < adj[u].size(); i++) {
        if (adj[u][i] != par[u]) {
            centroid_dfs(adj[u][i], u, n);
            cnt[u] += cnt[adj[u][i]];
            if (cnt[adj[u][i]] > n / 2) {
                is_centroid = false;
            }
        }
    }
    if (n - cnt[u] > n / 2) {
        is_centroid = false;
    }
    if (is_centroid ) {
        centroids.push_back(u);
    }
}

int leaf_dfs(int u) {
    if (adj[u].size() == 1) {
        return u;
    } else {
        for (int i = 0; i < adj[u].size(); i++) {
            if (adj[u][i] != par[u]) {
                return leaf_dfs(adj[u][i]);
            }
        }
    }
    return -1;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int t; cin >> t;
    while (t--) {
        int n; cin >> n;
        centroids.clear();
        for (int i = 0; i < n; i++) {
            adj[i].clear();
        }
        for (int i = 1; i < n; i++) {
            int x, y; cin >> x >> y;
            x--; y--;
            adj[x].push_back(y);
            adj[y].push_back(x);
        }
        centroid_dfs(0, -1, n);
        if (centroids.size() == 1) {
            cout << 1 << ' ' << adj[0][0] + 1 << '\n';
            cout << 1 << ' ' << adj[0][0] + 1 << '\n';
        } else {
            if (par[centroids[0]] != centroids[1]) {
                swap(centroids[0], centroids[1]);
            }
            int v = leaf_dfs(centroids[0]);
            cout << v + 1 << ' ' << par[v] + 1 << '\n';
            cout << v + 1 << ' ' << centroids[1] + 1 << '\n';
        }
    }
    return 0;
}