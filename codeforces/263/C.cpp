#include <iostream>
#include <vector>
#include <set>
using namespace std;

typedef long long ll;
#define fi first
#define se second
#define mp make_pair

int n;
vector < vector <int> > adj(1e5 + 1);
set <int> rem;
vector <int> ord;

void search(int pred1, int pred2) {
    if (ord.size() == n) return;
    int nxt = 0;
    for (int j = 0; j < 4 && nxt == 0; j++) {
        for (int k = 0; k < 4; k++) {
            int x = adj[pred1][j], y = adj[pred2][k];
            if (x == y && rem.find(x) != rem.end()) {
                nxt = x; rem.erase(x); break;
            }
        }
    }
    if (nxt) {
        ord.push_back(nxt);
        search(nxt, pred1);
    }
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> n;
    for (int i = 0; i < 2 * n; i++) {
        int a, b; cin >> a >> b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }
    for (int i = 1; i <= n; i++) {
        if (adj[i].size() != 4) {
            cout << -1 << '\n';
            return 0;
        }
    }
    for (int i = 0; i < 4; i++) {
        for (int j = i + 1; j < 4; j++) {
            rem.clear();
            ord.clear();
            for (int k = 2; k <= n; k++) {
                rem.insert(k);
            }
            ord.push_back(adj[1][i]); rem.erase(adj[1][i]);
            ord.push_back(1);
            ord.push_back(adj[1][j]); rem.erase(adj[1][j]);
            search(adj[1][j], 1);
            if (ord.size() == n) {
                for (int i = 0; i < n; i++) {
                    cout << ord[i] << ' ';
                }
                cout << '\n';
                return 0;
            }
        }
    } 
    cout << -1 << '\n';
    return 0;
}