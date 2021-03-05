#include <iostream>
using namespace std;
             
typedef long long ll;
#define fi first
#define se second
#define mp make_pair

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int n, m; cin >> n >> m;
    int a[n][m];
    for (int i = 0; i < n; i += 1) {
        for (int j = 0; j < m; j += 1) {
            cin >> a[i][j];
            if ((i + j) % 2) a[i][j] = 720720;
            else {
                for (int k = 1; k * k * k * k < 1e6; k += 1) {
                    int d = 720720 - k * k * k * k;
                    if (d % a[i][j] == 0) {
                        a[i][j] = d;
                    }
                }
            }
        }
    }
    for (int i = 0; i < n; i += 1) {
        for (int j = 0; j < m; j += 1) {
            cout << a[i][j] << ' ';
        }
        cout << '\n';
    }
    return 0;
}