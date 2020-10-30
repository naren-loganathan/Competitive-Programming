#include <iostream>
#include <cmath>
using namespace std;

typedef long long int ll;

int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n, m, sx, sy;
    cin >> n >> m >> sx >> sy;
    cout << sx << " " << sy << "\n";
    for (int i = 1; i <= m; i++) {
        if (i != sy) {
            cout << sx << " " << i << "\n";
        }
    }
    bool shift = 0;
    for (int i = 1; i <= n; i++) {
        if (i != sx) {
            for (int j = 1; j <= m; j++) {
                if (shift) {
                    cout << i << " " << j << "\n";
                }
                else {
                    cout << i << " " << m + 1 - j << "\n";
                }
            }
            shift = !shift;
        }
    }
    return 0;
}