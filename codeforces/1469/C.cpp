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
        bool possible = 1;
        int n, k; cin >> n >> k;
        vector <int> h(n), l(n - 1), r(n - 1);
        for (int i = 0; i < n; i++) {
            cin >> h[i];
        }
        l[0] = h[0]; r[0] = h[0];
        for (int i = 1; i < n - 1; i++) {
            l[i] = max(h[i], l[i - 1] - k + 1);
            r[i] = min(h[i] + k - 1, r[i - 1] + k - 1);
            if (l[i] > r[i]) {
                possible = 0;
                break;
            }
        }
        if (l[n - 2] >= h[n - 1] + k || r[n - 2] <= h[n - 1] - k) {
            possible = 0;
        }
        cout << (possible ? "Yes" : "No") << "\n";
    }
    return 0;
}