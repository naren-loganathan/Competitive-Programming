#include <iostream>
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
        int n, x, y;
        cin >> n >> x >> y;
        int mn = 0, mx = 0;

        int rem_l = (x + y <= n ? 0 : (x - 1) - max(n - y - 1, 0));
        int rem_r = (x + y <= n ? 0 : (y - 1) - max(n - x - 1, 0));
        mn = min(rem_l, rem_r) + abs(rem_l - rem_r) + 1;

        int t1 = min(x - 1, n - y);
        int t2 = min(y - 1, n - x);
        mx = t1 + t2 + 1 + min(x - 1 - t1, y - 1 - t2);
        cout << mn << ' ' << mx << '\n';
    }
    return 0;
}