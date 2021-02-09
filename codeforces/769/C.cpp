#include <iostream>
#include <vector>
#include <string>
#include <queue>
using namespace std;

typedef long long ll;
#define fi first
#define se second
#define mp make_pair

//could be cleaner

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int n, m, k; cin >> n >> m >> k;
    vector <string> maze(n + 2, "");
    for (int i = 0; i < m + 2; i++) {
        maze[0].push_back('*'); maze[n + 1].push_back('*');
    }
    for (int i = 1; i <= n; i++) {
        maze[i].push_back('*');
        string s; cin >> s;
        maze[i] += s; maze[i] += '*';
    }
    if (k % 2) {
        cout << "IMPOSSIBLE" << "\n";
    }
    else {
        string result = "";
        pair <int, int> pos;
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= m; j++) {
                if (maze[i][j] == 'X') {
                    pos = mp(i, j);
                    maze[i][j] = '.';
                }
            }
        }
        vector < vector <int> > dist(n + 2, vector <int> (m + 2, 0));
        vector < vector <int> > vis(n + 2, vector <int> (m + 2, 0));
        vis[pos.fi][pos.se] = 1;
        queue < pair <int, int> > q;
        q.push(pos);
        while (!q.empty()) {    //messy BFS
            int x = q.front().fi, y = q.front().se;
            int d = dist[x][y];
            q.pop();
            if (maze[x + 1][y] == '.' && !vis[x + 1][y]) {
                vis[x + 1][y] = 1;
                dist[x + 1][y] = d + 1;
                q.push(mp(x + 1, y));
            }
            if (maze[x][y - 1] == '.' && !vis[x][y - 1]) {
                vis[x][y - 1] = 1;
                dist[x][y - 1] = d + 1;
                q.push(mp(x, y - 1));
            }
            if (maze[x][y + 1] == '.' && !vis[x][y + 1]) {
                vis[x][y + 1] = 1;
                dist[x][y + 1] = d + 1;
                q.push(mp(x, y + 1));
            }
            if (maze[x - 1][y] == '.' && !vis[x - 1][y]) {
                vis[x - 1][y] = 1;
                dist[x - 1][y] = d + 1;
                q.push(mp(x - 1, y));
            }
        }
        int x = pos.fi, y = pos.se;
        while (result.size() < k) {
            int max_steps = k - result.size();
            if (maze[x + 1][y] == '.' && dist[x + 1][y] <= max_steps) {
                result.push_back('D'); x++;
            }
            else if (maze[x][y - 1] == '.' && dist[x][y - 1] <= max_steps) {
                result.push_back('L'); y--;
            }
            else if (maze[x][y + 1] == '.' && dist[x][y + 1] <= max_steps) {
                result.push_back('R'); y++;
            }
            else if (maze[x - 1][y] == '.' && dist[x - 1][y] <= max_steps) {
                result.push_back('U'); x--;
            }
            else {
                break;
            }
        }
        cout << (result.size() == k ? result : "IMPOSSIBLE") << "\n";
    }
    return 0;
}