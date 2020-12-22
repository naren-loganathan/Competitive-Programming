#include <iostream>
#include <vector>
using namespace std;

typedef long long ll;
#define fi first
#define se second
#define mp make_pair
#define N 100

vector < vector <int> > adj(N);
vector <bool> visited(N, 0);

void dfs (int u) {
    visited[u] = 1;
    for (auto v : adj[u]) {
        if (!visited[v]) {
            dfs(v);
        }
    }
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    vector < pair <int, int> > intervals;
    int n, x, y, type; cin >> n;
    while (n--) {
        cin >> type >> x >> y;
        if (type == 1) {
            intervals.push_back(mp(x, y));
            int n = intervals.size();
            for (int i = 0; i < n - 1; i++) {
                if ((intervals[i].fi < x && intervals[i].se > x) || (intervals[i].fi < y && intervals[i].se > y)) {
                    adj[i].push_back(n - 1);
                    adj[n - 1].push_back(i);
                }
                else if ((intervals[i].fi > x && intervals[i].fi < y) || (intervals[i].se > x && intervals[i].se < y)) {
                    adj[i].push_back(n - 1);
                }
            }
        }
        else if (type == 2) {
            for (int i = 0; i < N; i++) {
                visited[i] = 0;
            }
            dfs(x - 1);
            cout << (visited[y - 1] ? "YES" : "NO") << "\n";
        }
    }
    return 0;
}