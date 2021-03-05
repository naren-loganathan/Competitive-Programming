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
    int n, m; cin >> n >> m;
    vector <int> a(n), b(m);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    for (int i = 0; i < m; i++) {
        cin >> b[i];
    }
    int ans = 1 << 9;
    for (int mask = (1 << 9) - 1; mask >= 0; mask--) {
        bool p = 1;
        for (int i = 0; i < n; i++) {
            bool q = 0;
            for (int j = 0; j < m; j++) {
                if (((a[i] & b[j]) | mask) == mask) {
                    q = 1; break;
                }
            }
            p &= q;
        }
        if (p) ans = min(ans, mask);
    }
    cout << ans << '\n';
    return 0;
}