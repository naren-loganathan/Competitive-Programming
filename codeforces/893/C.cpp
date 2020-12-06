#include <iostream>
#include <vector>
#include <cmath>
using namespace std;
     
typedef long long ll;
#define fi first
#define se second
#define mp make_pair
#define N 100005

vector < vector <int> > adj(N);
vector <bool> visited(N, 0);
vector <ll> c(N, 0);

ll gold;

void dfs (int i) {
    visited[i] = 1;
    gold = min(gold, c[i]);
    for (auto j : adj[i]) {
        if (!visited[j]) {
            dfs(j);
        }
    }
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    ll n, m, x, y; 
    cin >> n >> m;
    for (int i = 1; i <= n; i++) {
        cin >> c[i];
    }
    while (m--) {
        cin >> x >> y;
        adj[x].push_back(y);
        adj[y].push_back(x);
    }
    ll cost = 0;
    for (int i = 1; i <= n; i++) {
        if (visited[i] == 0) {
            gold = 1e9;
            dfs(i);
            cost += gold;
        }
    }
    cout << cost << "\n";
    return 0;
}