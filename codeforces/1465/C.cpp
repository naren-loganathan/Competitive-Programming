#include <iostream>
#include <vector>
using namespace std;
     
typedef long long ll;
#define fi first
#define se second
#define mp make_pair
#define N 100005

vector <bool> visited(N, 0);
vector < vector <int> > adj(N);
bool cycle = 0;

void dfs (int u, int pred) {
    visited[u] = 1;
    for (auto v : adj[u]) {
        if (!visited[v]) {
            dfs(v, u);
        }
        else if (v != pred) {
            cycle = 1;
        }
    }
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int t; cin >> t;
    while (t--) {
        int n, m, x, y, cnt = 0; 
        cin >> n >> m;
        for (int i = 1; i <= n; i++) {
            adj[i].clear();
            visited[i] = 0;
        }
        for (int i = 0; i < m; i++) {
            cin >> x >> y;
            if (x != y) {
                adj[x].push_back(y);
                adj[y].push_back(x);
                cnt++;
            }
        }
        for (int i = 1; i <= n; i++) {
            cycle = 0;
            if (!visited[i]) {
                dfs(i, -69420);
            }
            if (cycle) {
                cnt++;
            }
        }
        cout << cnt << "\n";
    }
    return 0;
}

//Sometimes I wish I was smart.