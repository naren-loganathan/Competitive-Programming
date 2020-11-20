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
        int x, y; cin >> x >> y;
        int n = max(x, y), m = min(x, y);
        cout << 2 * m + max(2 * (n - m) - 1, 0) << "\n";
    }
    return 0;
}