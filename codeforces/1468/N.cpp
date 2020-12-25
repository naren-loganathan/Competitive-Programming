#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>
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
        vector <int> c(3), a(5);
        bool possible = 1;
        for (int i = 0; i < 3; i++) {
            cin >> c[i];
        }
        for (int i = 0; i < 5; i++) {
            cin >> a[i];
        }
        for (int i = 0; i < 3; i++) {
            c[i] -= a[i];
        }
        for (int i = 0; i < 3; i++) {
            if (c[i] < 0) {
                possible = 0;
            }
        }
        a[4] -= min(a[4], c[1]);
        a[3] -= min(a[3], c[0]);
        if (c[2] < a[4] + a[3]) {
            possible = 0;
        }
        cout << (possible ? "Yes" : "No") << "\n";
    }
    return 0;
}