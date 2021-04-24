#include <iostream>
#include <vector>
using namespace std;

typedef long long ll;
#define fi first
#define se second
#define mp make_pair

bool poss = 1;
vector < vector <int> > grid(501, vector <int> (501));

int dir_row[] = {-1, 0, 1, 0};
int dir_col[] = { 0,-1, 0, 1};
int n;

void fill(int val, int row) {
    if (poss) {
        int cnt = 1;
        pair <int, int> pos = mp(row, row);
        while (cnt < val) {
            int x, y;
            bool ok = 0;
            for (int i = 0; i < 4; i++) {
                x = pos.fi + dir_row[i];
                y = pos.se + dir_col[i];
                if (x && x <= n && y && y <= n && x > y) {
                    if (grid[x][y] == 0) {
                        grid[x][y] = val;
                        cnt += 1;
                        pos = mp(x, y);
                        ok = 1;
                        break;
                    }
                }
            }
            if (!ok) {
                poss = 0; break;
            }
        }
    }
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> n;
    vector <int> p(n);
    for (int i = 0; i < n; i++) {
        cin >> p[i];
        grid[i + 1][i + 1] = p[i];
        if (poss) {
            fill(p[i], i + 1);
        }
    }
    if (poss) {
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= i; j++) {
                cout << grid[i][j] << ' ';
            }
            cout << '\n';
        }
    } else {
        cout << -1 << '\n';
    }
    return 0;
}