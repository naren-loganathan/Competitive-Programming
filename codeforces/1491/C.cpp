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
        ll n; cin >> n;
        vector <ll> s(n + 1, 0), cnt(n + 1, 0);
        for (ll i = 1; i <= n; i++) {
            cin >> s[i];
        }
        ll passes = 0;
        for (ll i = 1; i <= n; i++) {
            if (s[i] - cnt[i] > 1) {
                passes += s[i] - cnt[i] - 1;
                cnt[i] = s[i] - 1;
            }
            //cnt[i] is now >= s[i] - 1
            if (i < n) cnt[i + 1] += cnt[i] - (s[i] - 1);
            for (ll j = i + 2; j <= min(n, i + s[i]); j++) {
                cnt[j] += 1;
            }
        }
        cout << passes << "\n";
    }
    return 0;
}