#include <iostream>
#include <vector>
#include <string>
using namespace std;

typedef long long ll;
#define fi first
#define se second
#define mp make_pair

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int n; cin >> n;
    vector <string> board(n), res(2 * n - 1, string (2 * n - 1, 'x'));
    res[n - 1][n - 1] = 'o';
    vector < pair <int, int> > pieces;
    for (int i = 0; i < n; i++) {
        cin >> board[i];
        for (int j = 0; j < n; j++) {
            if (board[i][j] == 'o') {
                pieces.push_back(mp(i, j));
            }
        }
    }
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (board[i][j] == '.') {
                for (int k = 0; k < pieces.size(); k++) {
                    int x = n - 1 + i - pieces[k].fi;
                    int y = n - 1 + j - pieces[k].se;
                    res[x][y] = '.'; 
                }
            }
        }
    }
    bool poss = true;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (board[i][j] == 'x') {
                bool found = false;
                for (int k = 0; k < pieces.size(); k++) {
                    int x = n - 1 + i - pieces[k].fi;
                    int y = n - 1 + j - pieces[k].se;
                    if (res[x][y] == 'x') {
                        found = true;
                        break;
                    }
                }
                if (!found) {
                    poss = false;
                }
            }
        }
    }
    if (poss) {
        cout << "YES" << '\n';
        for (int i = 0; i < 2 * n - 1; i++) {
            cout << res[i] << '\n';
        }
    } else {
        cout << "NO" << '\n';
    }
    return 0;
}