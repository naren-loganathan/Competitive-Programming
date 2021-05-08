#include <iostream>
#include <vector>
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
        if (n == 2) {
            cout << -1 << '\n';
        } else {
            vector < vector <int> > a(n, vector <int> (n));
            int curr = 1;
            for (int i = 0; i < n; i++) {
                for (int j = 0; j < n; j++) {
                    if (a[i][j] == 0 && curr <= n * n) {
                        a[i][j] = curr;
                        curr += 2;
                    }
                }
            }
            curr = 2;
            for (int i = 0; i < n; i++) {
                for (int j = 0; j < n; j++) {
                    if (a[i][j] == 0 && curr <= n * n) {
                        a[i][j] = curr;
                        curr += 2;
                    }
                }
            }
            for (int i = 0; i < n; i++) {
                for (int j = 0; j < n; j++) {
                    cout << a[i][j] << ' ';
                }
                cout << '\n';
            }
        }
    }
    return 0;
}