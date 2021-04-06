#include <iostream>
#include <vector>
#include <string>
using namespace std;

typedef long long ll;
#define fi first
#define se second
#define mp make_pair

int moves[] = {0, 1, 0, -1}, vis[50][50];
int n, m, cnt;

void dfs(int i, int j, vector <string> &maze) {
    vis[i][j] = 1;
    if (maze[i][j] == 'G') {
        cnt += 1;
    }
    for (int k = 0; k < 4; k++) {
        int row = i + moves[k], col = j + moves[(k + 1) % 4];
        if (row >= 0 && row < n && col >= 0 && col < m) {
            if (!vis[row][col] && maze[row][col] != '#') {
                dfs(row, col, maze);
            }
        }
    }
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int t; cin >> t;
    while (t--) {
        cin >> n >> m;
        vector <string> maze(n);
        for (int i = 0; i < n; i++) {
            cin >> maze[i];
        }
        bool poss = 1;
        int good_cnt = 0;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (maze[i][j] == 'B') {
                    for (int k = 0; k < 4; k++) {
                        int row = i + moves[k], col = j + moves[(k + 1) % 4];
                        if (row >= 0 && row < n && col >= 0 && col < m) {
                            if (maze[row][col] == 'G') {
                                poss = 0;
                            } else if (maze[row][col] == '.') {
                                maze[row][col] = '#';
                            }
                        }
                    }
                } else if (maze[i][j] == 'G') {
                    good_cnt += 1;
                }
            }
        }
        if (poss) {
            if (good_cnt) {
                if (maze[n - 1][m - 1] == '#') {
                    poss = 0;
                } else {
                    cnt = 0;
                    for (int i = 0; i < n; i++) {
                        for (int j = 0; j < m; j++) {
                            vis[i][j] = 0;
                        }
                    }
                    dfs(n - 1, m - 1, maze);
                    if (cnt != good_cnt) {
                        poss = 0;
                    }
                }
            }
        }
        cout << (poss ? "Yes" : "No") << '\n';
    }
    return 0;
}