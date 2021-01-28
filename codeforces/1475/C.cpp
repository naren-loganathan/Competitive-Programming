#include <iostream>
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
        ll a, b, k; cin >> a >> b >> k;
        vector <ll> guys(k), girls(k);
        map <ll, ll> bb, gg;
        for (int i = 0; i < k; i++) {
            cin >> guys[i];
            bb[guys[i]]++;
        }
        for (int i = 0; i < k; i++) {
            cin >> girls[i];
            gg[girls[i]]++;
        }
        ll ways = k * (k - 1);
        for (int i = 0; i < k; i++) {
            ways -= (bb[guys[i]] + gg[girls[i]] - (ll) 2);
        }
        ways /= 2;
        cout << ways << "\n";
    }
    return 0;
}
