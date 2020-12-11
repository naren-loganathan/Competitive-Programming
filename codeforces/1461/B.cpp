#include <iostream>
#include <vector>
#include <string>
#include <cmath>
using namespace std;
     
typedef long long ll;
#define fi first
#define se second
#define mp make_pair

int n, m;
vector <string> c(501);
int d[501][501];

void screw_you_spruce (int i, int j, int level) {
    int l = j - 1, r = j + 1, depth = i + 1, x = 1e6;
    c[i][j] = 'v';
    d[i][j] = level;
    if (depth < n && l >= 0 && r < m) {
        for (int k = l; k <= r; k++) {
            if (c[depth][k] != '*' && c[depth][k] != 'v') {
                return;
            }
            else if (c[depth][k] == '*') {
                screw_you_spruce(depth, k, 1);
                x = min(d[depth][k], x);
            }
            else if (c[depth][k] == 'v') {  //Next time, don't recompute things like an idiot.
                x = min(d[depth][k], x);
            }
        }
        d[i][j] += x;
    }
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int t; cin >> t;
    while (t--) {
        cin >> n >> m;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                d[i][j] = 0;
            }
        }
        for (int i = 0; i < n; i++) {
            cin >> c[i];
        }
        ll cnt = 0;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (c[i][j] == '*') {
                    screw_you_spruce(i, j, 1);
                }
            }
        }
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                cnt += d[i][j];
            }
        }
        cout << cnt << "\n";
    }
    return 0;
}