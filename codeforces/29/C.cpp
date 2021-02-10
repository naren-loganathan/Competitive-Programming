#include <iostream>
#include <vector>
#include <map>
#include <set>
using namespace std;

typedef long long ll;
#define fi first
#define se second
#define mp make_pair

vector < vector <int> > adj(1e5 + 1);
vector <bool> visited(1e5 + 1, 0);
map <int, int> m;
map <int, int> inv_m;
map <int, int> cnt;

void dfs (int u) {
    visited[u] = 1;
    cout << m[u] << " ";
    for (auto v : adj[u]) {
        if (!visited[v]) {
            dfs(v);
        }
    }
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int n; cin >> n;
    int a[n][2];
    set <int> s;
    for (int i = 0; i < n; i++) {
        cin >> a[i][0] >> a[i][1];
        s.insert(a[i][0]);
        s.insert(a[i][1]);
        cnt[a[i][0]]++; cnt[a[i][1]]++;
    }
    int x = 1;
    while (!s.empty()) {
        m[x] = *(s.begin());
        inv_m[*(s.begin())] = x;
        s.erase(*(s.begin()));
        x++;
    }
    for (int i = 0; i < n; i++) {
        adj[inv_m[a[i][0]]].push_back(inv_m[a[i][1]]);
        adj[inv_m[a[i][1]]].push_back(inv_m[a[i][0]]);
    }
    for (auto it : cnt) {
        if (it.se == 1) {
            dfs(inv_m[it.fi]);
            break;
        }
    }
    cout << "\n";
    return 0;
}