#include <iostream>
#include <vector>
#include <cmath>
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
        int a[n][n];
        vector <int> result(10, 0);
        for (int i = 0; i < n; i++) {
            string s; cin >> s;
            for (int j = 0; j < n; j++) {
                a[i][j] = s[j] - 48;
            }
        }
        vector <int> u(10, n);
        vector <int> d(10, -1);
        vector <int> l(10, n);
        vector <int> r(10, -1);
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                u[a[i][j]] = min(u[a[i][j]], i);
                d[a[i][j]] = max(d[a[i][j]], i);
                l[a[i][j]] = min(l[a[i][j]], j);
                r[a[i][j]] = max(r[a[i][j]], j);
            }
        }
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                int x = max(max(i - u[a[i][j]], d[a[i][j]] - i) * max(n - 1 - j, j), max(j - l[a[i][j]], r[a[i][j]] - j) * max(n - 1 - i, i));
                result[a[i][j]] = max(result[a[i][j]], x);
            }
        }
        for (int i = 0; i < 10; i++) {
            cout << result[i] << " ";
        }
        cout << "\n";
    }
    return 0;
}