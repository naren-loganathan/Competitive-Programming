#include <iostream>
#include <vector>
#include <map>
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
        int n; cin >> n;
        map <ll, ll> cnt;
        vector <ll> a(n), bits(32);
        for (int i = 0; i < n; i++) {
            cin >> a[i];
            cnt[a[i]]++;
            for (int j = 0; j <= 30; j++) {
                if ((1LL << j) & a[i]) {
                    bits[j]++;
                }
            }
        }
        ll ans = 1, ends = 0;
        for (int i = 0; i <= 30; i++) {
            if (bits[i] == n) {
                ends += (1LL << i);
            }
        }
        if (cnt[ends] < 2) {
            ans = 0;
        } else {
            ans = (cnt[ends] * (cnt[ends] - 1)) % mod;
            for (ll i = n - 2; i > 0; i--) {
                ans = (ans * i) % mod;
            }
        }
        cout << ans << '\n';
    }
    return 0;
}