#include <iostream>
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
        int n, k1, k2;
        cin >> n >> k1 >> k2;
        int w, b;
        cin >> w >> b;
        bool p = 0;
        if (w * 2 <= (k1 + k2)) {
            if (2 * b <= (2 * n - (k1 + k2))) {
                p = 1;
            }
        }
        cout << (p ? "YES" : "NO") << '\n';
    }
    return 0;
}