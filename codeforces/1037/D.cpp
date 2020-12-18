#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

typedef long long ll;
#define fi first
#define se second
#define mp make_pair
#define N 200005

vector < vector <int> > adj(N);
vector <bool> visited(N, 0);
vector <int> a(N), ord(N), result;

void bfs (int src) {
    queue <int> q; q.push(src);
    visited[src] = 1; int idx = 1;
    while (!q.empty()) {
        int i = q.front(); q.pop();
        result.push_back(i);
        for (int j : adj[i]) {
            if (!visited[j]) {
                visited[j] = 1;
                q.push(j);
            }
        }
    }
}

bool cmp (int a, int b) {
    return ord[a] < ord[b];
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    bool possible = 1;
    int n, x, y, v; cin >> n;
    for (int i = 1; i < n; i++) {
        cin >> x >> y;
        adj[x].push_back(y);
        adj[y].push_back(x);
    }
    for (int i = 0; i < n; i++) {
        cin >> a[i];
        ord[a[i]] = i;
    }
    for (int i = 1; i <= n; i++) {
        sort(adj[i].begin(), adj[i].end(), cmp);
    }
    bfs(1);
    for (int i = 0; i < n; i++) {
        if (result[i] != a[i]) {
            possible = 0;
            break;
        }
    }
    cout << (possible ? "Yes" : "No") << "\n";
    return 0;
}