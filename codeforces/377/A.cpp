#include <iostream>
#include <vector>
#include <string>
using namespace std;

typedef long long int ll;
#define fi first
#define se second
#define mp make_pair

int visits = 0, remaining = 0;

void dfs (vector <string> &maze, int i, int j, int k) {
    if (visits < remaining - k) {
        visits++;
        maze[i][j] = 'V';
        if (i > 0 && maze[i - 1][j] == '.') {
            dfs(maze, i - 1, j, k);
        }
        if (i < maze.size() - 1 && maze[i + 1][j] == '.') {
            dfs(maze, i + 1, j, k);
        }
        if (j > 0 && maze[i][j - 1] == '.') {
            dfs(maze, i, j - 1, k);
        }
        if (j < maze[i].length() && maze[i][j + 1] == '.') {
            dfs(maze, i, j + 1, k);
        }
    }
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int n, m, k;
    cin >> n >> m >> k;
    vector <string> maze(n);
    for (int i = 0; i < n; i++) {
        cin >> maze[i];
    }
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (maze[i][j] == '.') {
                remaining++;
            }
        }
    }
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (maze[i][j] == '.') {
                dfs(maze, i, j, k);
                break;
            }
        }
    }
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (maze[i][j] == 'V') {
                cout << '.';
            }
            else if (maze[i][j] == '.') {
                cout << 'X';
            }
            else {
                cout << '#';
            }
        }
        cout << "\n";
    }
    return 0;
}