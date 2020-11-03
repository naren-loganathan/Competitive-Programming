#include <iostream>
#include <vector>
using namespace std;

typedef long long int ll;
#define fi first
#define se second
#define mp make_pair

int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t; cin >> t;
    while (t--) {
        int n; cin >> n;
        bool sorted = 0;
        vector <int> a(n);
        for (int i = 0; i < n; i++) {
            cin >> a[i];
        }
        vector <bool> fixed(n, 0);
        int min_exchanges = 0;
        for (int i = 0; i < n; i++) {
            if (a[i] == i + 1) {
                fixed[i] = 1;
            }
        }
        int f = 0, r = n - 1;
        while (fixed[f]) {
            f++;
            if (f == n) {
                min_exchanges = 0;
                sorted = 1;
                break;
            }
        }
        f--;
        if (!sorted) {
            while (fixed[r]) {
                r--;
            }
            r++;
            if (r > f) {
                min_exchanges = 1;
                for (int i = f + 1; i < r; i++) {
                    if (fixed[i] == 1) {
                        min_exchanges++;
                        break;
                    }
                }
            }
        }
        cout << min_exchanges << "\n";
    }
    return 0;
}