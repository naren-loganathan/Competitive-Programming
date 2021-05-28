#include <iostream>
#include <string>
#include <vector>
#include <cmath>
using namespace std;            

typedef long long ll;
#define fi first
#define se second
#define mp make_pair

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    vector < vector <ll> > ans(10, vector <ll> (10, 0)), d[10][10];
    string s; cin >> s;
    for (int i = 0; i < 10; i++) {
        for (int j = 0; j < 10; j++) {
            vector < vector <ll> > a(10, vector <ll> (10, 1e9));
            for (int x = 0; x < 10; x++) {
                for (int y = 0; y < 10; y++) {
                    if (y == (x + i) % 10 || y == (x + j) % 10) {
                        a[x][y] = 1;
                    }
                }
            }
            for (int p = 0; p < 10; p++) {
                for (int x = 0; x < 10; x++) {
                    for (int y = 0; y < 10; y++) {
                        a[x][y] = min(a[x][y], a[x][p] + a[p][y]);
                    }
                }
            }
            d[i][j] = a;
        }
    }
    int cur, nxt;
    for (int c = 0; c < s.length(); c++) {
        if (c == 0) {
            if (s[c] == '0') {
                continue;
            } else {
                for (int i = 0; i < 10; i++) {
                    for (int j = 0; j < 10; j++) {
                        ans[i][j] += 1;
                    }
                }
                cur = 0; nxt = s[c] - '0';
            }
        } else {
            cur = s[c - 1] - '0'; nxt = s[c] - '0';
        }
        for (int i = 0; i < 10; i++) {
            for (int j = 0; j < 10; j++) {
                if (ans[i][j] != -1) {
                    if (d[i][j][cur][nxt] < 1e9) {
                        ans[i][j] += d[i][j][cur][nxt] - 1;
                    } else {
                        ans[i][j] = -1;
                    }
                }
            }
        }
    }
    for (int i = 0; i < 10; i++) {
        for (int j = 0; j < 10; j++) {
            cout << ans[i][j] << ' ';
        }
        cout << '\n';
    }
    return 0;
}