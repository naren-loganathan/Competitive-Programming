#include <iostream>
#include <vector>
using namespace std;
     
typedef long long int ll;
#define fi first
#define se second
#define mp make_pair
#define N 100005

vector < vector <int> > edges(N);
vector <bool> visited(N, 0);
vector <int> init(N, 0), goal(N, 0), ops;

void dfs (int i, int level, int even_ops, int odd_ops) {
    visited[i] = 1;
    if (level % 2) {
        if (init[i] != goal[i] && odd_ops % 2 == 0) {
            ops.push_back(i);
            odd_ops++;
        }
        else if (init[i] == goal[i] && odd_ops % 2) {
            ops.push_back(i);
            odd_ops++;
        }
    }
    else {
        if (init[i] != goal[i] && even_ops % 2 == 0) {
            ops.push_back(i);
            even_ops++;
        }
        else if (init[i] == goal[i] && even_ops % 2) {
            ops.push_back(i);
            even_ops++;
        }
    }
    for (auto j : edges[i]) {
        if (!visited[j]) {
            dfs(j, level + 1, even_ops, odd_ops);
        }
    }
}
     
int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int n, u, v; 
    cin >> n;
    for (int i = 1; i < n; i++) {
        cin >> u >> v;
        edges[u].push_back(v);
        edges[v].push_back(u);
    }
    for (int i = 1; i <= n; i++) {
        cin >> init[i];
    }
    for (int i = 1; i <= n; i++) {
        cin >> goal[i];
    }
    dfs(1, 0, 0, 0);
    cout << ops.size() << "\n";
    for (int i = 0; i < ops.size(); i++) {
        cout << ops[i] << "\n";
    }
    return 0;
}