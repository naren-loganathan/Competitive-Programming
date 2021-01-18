#include <iostream>
#include <string>
#include <vector>
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
        ll n, good = 0; cin >> n;
        string s; cin >> s;
        map <ll, ll> f;
        vector <ll> p(n + 1, 0);
        for (int i = 1; i <= n; i++) {
           p[i] = s[i - 1] - 48 + p[i - 1];
           f[p[i] - i]++;
        }
        for (auto it : f) {
            if (it.fi == 0) {
                it.se++;
            }
            good += (it.se * (it.se - 1) / 2);
        }
        cout << good << "\n";
    }
    return 0;
}
