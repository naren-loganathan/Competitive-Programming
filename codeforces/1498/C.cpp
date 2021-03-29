#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

typedef long long ll;
#define fi first
#define se second
#define mp make_pair

ll mod = 1e9 + 7;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int t; cin >> t;
    while (t--) {
        ll n, k, ans = 1; 
        cin >> n >> k;
        vector <int> cnt(n, 1), p(n);
        bool l = 0; k -= 1;
        while (k > 0) {
            /*for (int i = 0; i < n; i++) {
                cout << cnt[i] << ' ';
            }
            cout << '\n';*/
            for (int i = 0; i < n; i++) {
                ans = (ans + cnt[i]) % mod;
            }
            k -= 1;
            if (l == 0) {
                for (int i = n - 1; i >= 0; i--) {
                    p[i] = (cnt[i] + (i < n - 1 ? p[i + 1] : 0)) % mod;
                }
                cnt.back() = 0;
                for (int i = n - 2; i >= 0; i--) {
                    cnt[i] = p[i + 1];
                }
            } else {
                for (int i = 0; i < n; i++) {
                    p[i] = (cnt[i] + (i ? p[i - 1] : 0)) % mod;
                }
                cnt.front() = 0;
                for (int i = 1; i < n; i++) {
                    cnt[i] = p[i - 1];
                }
            }
            l = !l;
        }
        cout << ans << '\n';
    }
    return 0;
}