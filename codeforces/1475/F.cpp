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
    int t; cin >> t;
    while (t--) {
        int n; cin >> n;
        bool possible = 1;
        vector <string> g1(n), g2(n);
        for (int i = 0; i < n; i++) {
            cin >> g1[i];
        }
        for (int i = 0; i < n; i++) {
            cin >> g2[i];
        }
        vector <int> ver(n, 0), hor(n, 0);
        for (int i = 0; i < n; i++) {
            if (g1[0][i] != g2[0][i]) {
                ver[i] = 1;
            }
        }
        for (int i = 0; i < n; i++) {
            if (g1[i][0] == g2[i][0] && ver[0]) {
                hor[i] = 1;
            }
            else if (g1[i][0] != g2[i][0] && ver[0] == 0) {
                hor[i] = 1;
            }
        }
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (g1[i][j] != g2[i][j]) {
                    if ((ver[j] + hor[i]) % 2 == 0) {
                        possible = 0;
                    }
                }
                else {
                    if ((ver[j] + hor[i]) % 2) {
                        possible = 0;
                    }
                }
            }
        }
        cout << (possible ? "YES" : "NO") << "\n";
    }
    return 0;
}