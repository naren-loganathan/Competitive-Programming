#include <iostream>
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
    int t; cin >> t;
    while (t--) {
        int n; cin >> n;
        vector <int> a(n);
        int mn = 2e9 + 1, min_idx = -1;
        for (int i = 0; i < n; i++) {
            cin >> a[i];
            if (a[i] < mn) {
                mn = a[i];
                min_idx = i;
            }
        }
        if (n > 1) {
            cout << n << '\n';
            if (min_idx == 0) {
                min_idx++;        
            }
            if (mn == 1) {
                cout << 1 << ' ' << min_idx + 1 << ' ' << 1 << ' ' << 1 << '\n';
                for (int i = 2; i <= n; i++) {
                    cout << 1 << ' ' << i << ' ' << 1 << ' ' << 1 << '\n';
                }
            } else {
                cout << 1 << ' ' << min_idx + 1 << ' ' << mn << ' ' << mn << '\n';
                for (int i = 2; i <= n; i++) {
                    cout << 1 << ' ' << i << ' ' << mn << ' ' << mn + (i + 1) % 2 << '\n';
                }
            }
        } else {
            cout << 0 << '\n';
        }
    }
    return 0;
}