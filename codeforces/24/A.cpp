    #include <iostream>
    #include <vector>
    #include <cmath>
    using namespace std;
     
    typedef long long ll;
    #define fi first
    #define se second
    #define mp make_pair
     
    vector < vector < pair <int, int> > > adj(101);
    vector <bool> visited(101, 0);
     
    int money = 0;
     
    void dfs (int u) {
        visited[u] = 1;
        bool done = 1;
        for (auto edge : adj[u]) {
            if (!visited[edge.fi]) {
                done = 0;
                if (edge.se < 0) {
                    money -= edge.se;
                }
                dfs(edge.fi);
            }
        }
        if (done) {
            for (auto edge : adj[u]) {
                if (edge.fi == 1) {
                    if (edge.se < 0) {
                        money -= edge.se;
                    }
                }
            }
        }
    }
     
    int main() {
        ios_base::sync_with_stdio(0);
        cin.tie(0);
        int n, sum = 0; cin >> n;
        for (int i = 0; i < n; i++) {
            int a, b, c;
            cin >> a >> b >> c;
            adj[a].push_back(mp(b, c));
            adj[b].push_back(mp(a, -c));
            sum += c;
        }
        dfs(1);
        cout << min(money, sum - money) << "\n";
        return 0;
    }