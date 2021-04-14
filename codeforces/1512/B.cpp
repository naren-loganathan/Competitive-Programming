#include <iostream>
#include <vector>
#include <string>
using namespace std;

typedef long long ll;
#define fi first
#define se second
#define mp make_pair

vector < pair <int, int> > solve(vector < pair <int, int> > c1, int n) {
    vector < pair <int, int> > c2(2);
    if (c1[0].fi == c1[1].fi) {
        for (int i = 0; i < n; i++) {
            if (i != c1[0].fi) {
                c2[0] = mp(i, c1[0].se);
                c2[1] = mp(i, c1[1].se);
                break;
            }
        }
    } else if (c1[0].se == c1[1].se) {
        for (int i = 0; i < n; i++) {
            if (i != c1[0].se) {
                c2[0] = mp(c1[0].fi, i);
                c2[1] = mp(c1[1].fi, i);
                break;
            }
        }
    } else {
        c2[0] = mp(c1[0].fi, c1[1].se);
        c2[1] = mp(c1[1].fi, c1[0].se);
    }
    return c2;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int t; cin >> t;
    while (t--) {
        int n; cin >> n;
        vector < pair <int, int> > corners(2);
        vector <string> field(n);
        int idx = 0;
        for (int i = 0; i < n; i++) {
            cin >> field[i];
            for (int j = 0; j < n; j++) {
                if (field[i][j] == '*') {
                    corners[idx] = mp(i, j);
                    idx++;
                }
            }
        }
        vector < pair <int, int> > new_corners = solve(corners, n);
        for (int i = 0; i < 2; i++) {
            field[new_corners[i].fi][new_corners[i].se] = '*';
        }
        for (int i = 0; i < n; i++) {
            cout << field[i] << '\n';
        }
        //cout << '\n';
    }
    return 0;
}