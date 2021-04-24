#include <iostream>
using namespace std;

typedef long long ll;
#define fi first
#define se second
#define mp make_pair

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int n, m, k;
    cin >> n >> m >> k;
    int path[n][m][k / 2 + 1], w[n][m][4], dir[] = {0,-1, 0, 1}; //LURD
    //path[i][j][k] -> minimum path of length k / 2 with an endpoint at {i, j}
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            for (int d = 0; d < 4; d++) {
                w[i][j][d] = 0;
            }
            for (int l = 0; l <= k / 2; l++) {
                path[i][j][l] = (l ? 1e9 : 0);
            }
        }
    }
    for (int i = 0; i < n; i++) {
        for (int j = 1; j < m; j++) {
            int exhibits; cin >> exhibits;
            w[i][j - 1][2] = exhibits;
            w[i][j][0] = exhibits;
        }
    }
    for (int i = 1; i < n; i++) {
        for (int j = 0; j < m; j++) {
            int exhibits; cin >> exhibits;
            w[i - 1][j][3] = exhibits;
            w[i][j][1] = exhibits;
        }
    }
    if (k % 2) {
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                cout << -1 << ' ';
            }
            cout << '\n';
        }
    } else {
        for (int l = 1; l <= k / 2; l++) {
            for (int i = 0; i < n; i++) {
                for (int j = 0; j < m; j++) {
                    for (int d = 0; d < 4; d++) {
                        int x = i + dir[(d + 0) % 4];
                        int y = j + dir[(d + 1) % 4];
                        if (x >= 0 && x < n && y >= 0 && y < m) {
                            if (w[i][j][d]) {
                                path[x][y][l] = min(path[x][y][l], path[i][j][l - 1] + w[i][j][d]);
                            }
                        }
                    }
                }
            }
        }
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                cout << 2 * path[i][j][k / 2] << ' ';
            }
            cout << '\n';
        }
    }
    return 0;
}