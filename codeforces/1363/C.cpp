#include <iostream>
#include <vector>
using namespace std;
         
typedef long long ll;
#define fi first
#define se second
#define mp make_pair

int N = 1005;
vector < vector <int> > adj(N);

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int t; cin >> t;
    while (t--) {
        int n, x, u, v; cin >> n >> x;
        for (int i = 1; i <= n; i++) {
            adj[i].clear();
        }
        for (int i = 1; i < n; i++) {
            cin >> u >> v;
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        bool ayush = 0;
        if ((n - 2) % 2 == 0 || adj[x].size() == 1 || n == 1) {
            ayush = 1;
        }
        cout << (ayush ? "Ayush" : "Ashish") << "\n";
    }
    return 0;
}