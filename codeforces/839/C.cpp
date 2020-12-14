#include <iostream>
#include <vector>
using namespace std;
     
typedef long long ll;
typedef long double ld;
#define fi first
#define se second
#define mp make_pair
#define N 100005

vector < vector <int> > adj(N);
vector <bool> visited(N, 0);
vector <ld> cnt;

void dfs (int i, int depth, ld prob) {
    visited[i] = 1;
    ld unv = 0;
    for (auto j : adj[i]) {
        if (!visited[j]) {
            unv += 1;
        }
    }
    if (unv == 0) {
        cnt.push_back(prob * depth);
    }
    else {
        for (auto j : adj[i]) {
            if (!visited[j]) {
                dfs(j, depth + 1, prob / unv);
            }
        }
    }
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int n, u, v; cin >> n;
    for (int i = 1; i < n; i++) {
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    dfs(1, 0, 1);
    ld result = 0;
    for (int i = 0; i < cnt.size(); i++) {
        result += cnt[i];
    }
    printf("%0.9Lf\n", result);
    return 0;
}