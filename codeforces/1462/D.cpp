#include <iostream>
#include <cmath>
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
        int n, sum = 0; cin >> n;
        vector <int> a(n);
        for (int i = 0; i < n; i++) {
            cin >> a[i];
            sum += a[i];
        }
        int result = n - 1;
        for (int i = n; i > 0; i--) {
            if (sum % i == 0) {
                bool possible = 0;
                int msum = sum / i, d = 0;
                for (int j = 0; j < n; j++) {
                    d += a[j];
                    if (d > msum) {
                        possible = 0;
                        break;
                    }
                    else if (d == msum) {
                        if (j == n - 1) {
                            possible = 1;
                        }
                        d = 0;
                    }
                }
                if (possible) {
                    result = n - i;
                    break;
                }
            }
        }
        cout << result << "\n";
    }
    return 0;
}