#include <iostream>
#include <vector>
#include <string>
using namespace std;

typedef long long ll;
#define fi first
#define se second
#define mp make_pair

ll mod = 998244353;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    ll n, m, w = 0; 
    cin >> n >> m;
    vector <string> bo(n);
    ll dp_hor[n][m], dp_ver[n][m];
    for (int i = 0; i < n; i++) {
        cin >> bo[i];
        for (int j = 0; j < m; j++) {
            if (bo[i][j] == 'o') w += 1;
            dp_hor[i][j] = (bo[i][j] == 'o' ? 1 : 0);
            dp_ver[i][j] = (bo[i][j] == 'o' ? 1 : 0);
        }
    }
    ll len = 0;
    for (int i = 0; i < n; i++) {
        for (int j = 1; j < m; j++) {
            if (dp_hor[i][j]) {
                dp_hor[i][j] += dp_hor[i][j - 1];
                len = max(len, dp_hor[i][j]);
            }
        }
    }
    for (int j = 0; j < m; j++) {
        for (int i = 1; i < n; i++) {
            if (dp_ver[i][j]) {
                dp_ver[i][j] += dp_ver[i - 1][j];
                len = max(len, dp_ver[i][j]);
            }
        }
    }
    vector <ll> prob(len + 1), pow2(w + 1, 1);
    for (int i = 1; i <= w; i++) {
        pow2[i] = (pow2[i - 1] * 2) % mod;
    }
    for (int i = 2; i <= len; i++) {
        ll val = pow2[w - i];
        if (i % 2) {
            val = mod - val;
        }
        prob[i] = (prob[i - 1] + val) % mod;
    }
    ll ans = 0;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            ans = (ans + prob[dp_hor[i][j]]) % mod;
            ans = (ans + prob[dp_ver[i][j]]) % mod;
        }
    }
    cout << ans << '\n';
    return 0;
}