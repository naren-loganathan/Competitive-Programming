#include <iostream>
#include <vector>
#include <cmath>
#include <map>
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
        vector <int> a(n), mod2(n, 1);
        map <int, int> f;
        for (int i = 0; i < n; i++) {
            cin >> a[i];
            int x = a[i];
            for (int j = 2; j <= ceil(sqrt(x)); j += 2 - !(j % 2)) {
                if (x % j == 0) {
                    int cnt = 0;
                    while (x % j == 0) {
                        x /= j; cnt++;
                    }
                    if (cnt % 2) {
                        mod2[i] *= j;
                    }
                }
            }
            if (x > 1) {
                mod2[i] *= x;
            }
            f[mod2[i]]++;
        }
        int ans0 = 0, ans1 = 0;
        for (auto it = f.begin(); it != f.end(); it++) {
            ans0 = max(ans0, it -> se);
            if (it -> fi == 1 || it -> se % 2 == 0) {
                ans1 += it -> se;
            }
        }
        ans1 = max(ans0, ans1);
        int q; cin >> q;
        while (q--) {
            ll w; cin >> w;
            cout << (w ? ans1 : ans0) << "\n";
        }
    }
    return 0;
}

