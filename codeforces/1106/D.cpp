#include <iostream>
#include <vector>
#include <queue>
using namespace std;
     
typedef long long ll;
#define fi first
#define se second
#define mp make_pair
#define N 100005

priority_queue <int, vector <int>, greater <int> > q;
vector < vector <int> > adj(N);
vector <int> result;
vector <bool> visited(N, 0);

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int n, m, u, v; 
    cin >> n >> m;
    for (int i = 0; i < m; i++) {
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    visited[1] = 1; q.push(1);
    while (!q.empty()) {
        int i = q.top(); q.pop();
        result.push_back(i);
        for (auto j : adj[i]) {
            if (visited[j] == 0) {
                q.push(j);
                visited[j] = 1;
            }
        }
    }
    for (int i = 0; i < n; i++) {
        cout << result[i] << " ";
    }
    cout << "\n";
    return 0;
}