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
        ll n, ans = 0; 
        cin >> n;
        vector <ll> a(n), b(n);
        for (int i = 0; i < n; i++) {
            cin >> a[i] >> b[i];
        }
        ll start = 1e18;
        for (int i = 0; i < n; i++) {
            int j = (i + 1) % n;
            ans += max(0LL, a[j] - b[i]);
            start = min(start, a[j] - max(0LL, a[j] - b[i]));
        }
        ans += start;
        cout << ans << '\n';
    }
    return 0;
}