#include <iostream>
#include <map>
using namespace std;
     
typedef long long ll;
typedef long double ld;
#define fi first
#define se second
#define mp make_pair

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int t; cin >> t;
    while (t--) {
        ll n, pairs = 0; cin >> n;
        ll x, y, u, v, left = 0, right = 0, up = 0, down = 0;
        map <ld, ll> slopes1, slopes2;  //slopes1 -> the guy facing left, slopes2 -> the guy facing right
        for (int i = 0; i < n; i++) { 
            cin >> x >> y >> u >> v;
            if (y - v == 0) {
                if (x < u) {
                    right++;
                }
                else {
                    left++;
                }
            }
            else if (x - u == 0) {
                if (y < v) {
                    up++;
                }
                else {
                    down++;
                }
            }
            else {
                ld x1, y1, u1, v1;
                x1 = x; y1 = y; u1 = u; v1 = v;
                if (x > u) {
                    slopes1[(v1 - y1) / (u1 - x1)]++;
                }
                else {
                    slopes2[(v1 - y1) / (u1 - x1)]++;
                }
            }
        }
        for (auto it : slopes1) {
            if (slopes2.find(it.fi) != slopes2.end()) {
                pairs += it.se * slopes2[it.fi];
            }
        }
        pairs += (left * right + up * down);
        cout << pairs << "\n";
    }
    return 0;
}