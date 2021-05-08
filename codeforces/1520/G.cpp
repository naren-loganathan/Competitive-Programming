#include <iostream>
#include <vector>
#include <queue>
#include <cmath>
using namespace std;

typedef long long ll;
#define fi first
#define se second
#define mp make_pair

int d[] = {-1, 0, 1, 0};

//BFS >>> Dijkstra ;(

vector < vector <ll> > bfs(int n, int m, int w, int sx, int sy, vector < vector <int> > &a) {
    vector < vector <ll> > t(n, vector <ll> (m, 1e18));
    queue < pair <int, int> > q;
    q.push(mp(sx, sy));
    t[sx][sy] = 0;
    while (!q.empty()) {
        pair <int, int> node = q.front(); q.pop();
        int x = node.fi, y = node.se;
        for (int i = 0; i < 4; i++) {
            int new_x = x + d[(i + 0) % 4];
            int new_y = y + d[(i + 1) % 4];
            if (new_x >= 0 && new_x < n) {
                if (new_y >= 0 && new_y < m) {
                    if (a[new_x][new_y] >= 0 && t[new_x][new_y] == 1e18) {
                        t[new_x][new_y] = t[x][y] + w;
                        q.push(mp(new_x, new_y));
                    }
                }
            }
        }
    }
    return t;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int n, m, w; cin >> n >> m >> w;
    vector < vector <int> > a(n, vector <int> (m));
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> a[i][j];
        }
    }
    vector < vector <ll> > bed_dist = bfs(n, m, w, 0, 0, a);
    vector < vector <ll> > skl_dist = bfs(n, m, w, n - 1, m - 1, a);
    ll curr_dist = bed_dist[n - 1][m - 1], teleport_cost = 1e18;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (a[i][j] > 0 && skl_dist[i][j] < 1e18) {
                teleport_cost = min((ll) a[i][j] + skl_dist[i][j], teleport_cost);
            }
        }
    }
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (a[i][j] > 0 && bed_dist[i][j] < 1e18) {
                curr_dist = min(curr_dist, bed_dist[i][j] + (ll) a[i][j] + teleport_cost);
            }
        }
    }
    if (curr_dist == 1e18) {
        cout << -1 << '\n';
    } else {
        cout << curr_dist << '\n';
    }
    return 0;
}