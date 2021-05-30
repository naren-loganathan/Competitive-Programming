#include <iostream>
#include <vector>
using namespace std;

typedef long long ll;
#define fi first
#define se second
#define mp make_pair

ll mod = 1e9 + 7;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int n; cin >> n;
    vector <ll> d(n + 1), p(n + 1);
    d[1] = 1; p[1] = 1;
    for (int i = 2; i <= n; i++) {
        d[i] = (1 + p[i - 1]);
        p[i] = (p[i - 2] + d[i]) % mod;
    }
    ll ans = 0;
    for (int i = 1; i <= n; i++) {
        ans = (ans + d[i]) % mod;
    }
    cout << ans << '\n';
    return 0;
}