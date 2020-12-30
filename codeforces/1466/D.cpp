#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <cmath>
using namespace std;
     
typedef long long ll;
#define fi first
#define se second
#define mp make_pair

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int t; cin >> t;
    while (t--) {
        ll n, w, u, v, sum = 0; cin >> n;
        vector <ll> k;
        vector < pair <ll, ll> > ver;
        vector < vector <int> > adj(n + 1);
        vector <ll> degree(n + 1);
        for (int i = 1; i <= n; i++) {
            cin >> w;
            sum += w;
            ver.push_back(mp(w, i));
        }
        for (int i = 1; i < n; i++) {
            cin >> u >> v;
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        k.push_back(sum);
        sort(ver.begin(), ver.end());
        reverse(ver.begin(), ver.end());
        for (int i = 1; i <= n; i++) {
            degree[i] = adj[i].size();
        }
        for (int i = 0; i < n; i++) {
            //cout << "degree of vertice: " << degree[ver[i].se] << "\n"; 
            while (degree[ver[i].se] > 1 && k.size() < n - 1) {
                k.push_back(k.back() + ver[i].fi);
                //cout << "adding value: " << ver[i].fi << "\n";
                degree[ver[i].se]--;
            }
            if (k.size() == n - 1) {
                break;
            }
        }
        for (int i = 0; i < n - 1; i++) {
            cout << k[i] << " ";
        }
        cout << "\n";
    }
    return 0;
}