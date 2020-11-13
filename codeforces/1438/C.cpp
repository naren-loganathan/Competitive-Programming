#include <iostream>
using namespace std;
     
typedef long long int ll;
#define fi first
#define se second
#define mp make_pair
     
int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int t; cin >> t;
    while (t--) {
        int n, m;
        cin >> n >> m;
        int a[n][m];
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                cin >> a[i][j];
            }
        }
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if ((i + j) % 2) {
                    if (a[i][j] % 2) {
                        a[i][j]++;
                    }
                }
                else {
                    if (a[i][j] % 2 == 0) {
                        a[i][j]++;
                    }
                }
                cout << a[i][j] << " ";
            }
            cout << "\n";
        }
    }
    return 0;
}