#include <iostream>
#include <vector>
#include <algorithm>
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
        int n, m; 
        cin >> n >> m;
        vector <int> b[n], b_it(n);
        int path[m][n];
        vector < pair <int, pair <int, int> > > c;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                int len; cin >> len;
                b[i].push_back(len);
                c.push_back(mp(len, mp(i, j)));
            }
        }
        sort(c.begin(), c.end());
        for (int i = 0; i < m; i++) {
            b[c[i].se.fi][c[i].se.se] = -1;
        }
        for (int i = 0; i < m; i++) {
            pair <int, pair <int, int> > must = c[i];
            for (int j = 0; j < n; j++) {
                if (must.se.fi == j) {
                    path[i][j] = must.fi;
                } else {
                    while (b[j][b_it[j]] == -1 && b_it[j] < m) {
                        b_it[j]++;
                    }
                    path[i][j] = b[j][b_it[j]];
                    b[j][b_it[j]] = -1;
                }
            }
        }
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                cout << path[j][i] << ' ';
            }
            cout << '\n';
        }
    }
    return 0;
}