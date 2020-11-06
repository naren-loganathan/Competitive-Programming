#include <iostream>
#include <vector>
using namespace std;

typedef long long int ll;
#define fi first
#define se second
#define mp make_pair
#define N 100005

vector < vector <int> > adj(N);
vector <int> cats(N, 0);

int paths = 0, m;

void dfs (int i, int parent, int k) {
    if (k > m) {
        return;
    }
    if (adj[i].size() == 1 && i != 1) {
        paths++;
        return;
    }
    for (auto j : adj[i]) {
        if (j != parent) {
            (cats[j] ? dfs(j, i, k + 1) : dfs(j, i, 0));
        }
    }
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int n, x, y; 
    cin >> n >> m;
    for (int i = 1; i <= n; i++) {
        cin >> cats[i];
    }
    for (int i = 1; i < n; i++) {
        cin >> x >> y;
        adj[x].push_back(y);
        adj[y].push_back(x);
    }
    dfs(1, -1, cats[1]);
    cout << paths << "\n";
    return 0;
}