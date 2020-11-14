#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
using namespace std;
     
typedef long long ll;
#define fi first
#define se second
#define mp make_pair
#define N 1005

vector < vector <int> > adj(N);
vector < vector <bool> > edge_visits(N, vector <bool> (N, 0));
vector <bool> visited (N, 0);
ll cnt, edge_cnt;

bool lambda (pair <ll, ll> l1, pair <ll, ll> l2) {
    if (l1.fi < l2.fi || (l1.fi == l2.fi && l1.se > l2.se)) {
        return 1;
    }
    return 0;
}

void dfs (int i) {
    visited[i] = 1;
    cnt++;
    for (auto j : adj[i]) {
        if (visited[j] == 0) {
            edge_visits[i][j] = 1; edge_visits[j][i] = 1;
            edge_cnt++;
            dfs(j);
        }
        else if (edge_visits[i][j] == 0) {
            edge_visits[i][j] = 1; edge_visits[j][i] = 1;
            edge_cnt++;
        }
    }
}
     
int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int n, m, k, u, v;
    ll result = 0;
    cin >> n >> m >> k;
    vector <int> gov(k);
    for (int i = 0; i < k; i++) {
        cin >> gov[i];
    }
    for (int i = 0; i < m; i++) {
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    vector < pair <ll, ll> > combi;
    for (int i = 0; i < k; i++) {
        cnt = 0; edge_cnt = 0;
        dfs(gov[i]);
        combi.push_back(mp(cnt, edge_cnt));
    }
    sort(combi.begin(), combi.end(), lambda);
    cnt = 0; edge_cnt = 0;
    for (int i = 1; i <= n; i++) {
        if (visited[i] == 0) {
            dfs(i);  
        }
    }
    result += (cnt + combi[k - 1].fi) * (cnt + combi[k - 1].fi - 1) / 2 - (edge_cnt + combi[k - 1].se);
    for (int i = 0; i < k - 1; i++) {
        result += (combi[i].fi) * (combi[i].fi - 1) / 2 - combi[i].se;
    }
    cout << result << "\n";
    return 0;
}