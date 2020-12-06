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
        int n, k, x, y;
        cin >> n >> k;
        vector < pair <int, int> > c(n);
        for (int i = 0; i < n; i++) {
            cin >> x >> y;
            c[i] = mp(x, y);
        }
        bool possible = 0;
        for (int i = 0; i < n; i++) {
            int cnt = 0;
            for (int j = 0; j < n; j++) {
                if (abs(c[i].fi - c[j].fi) + abs(c[i].se - c[j].se) <= k) {
                    cnt++;
                }
            }
            if (cnt == n) {
                possible = 1;
                break;
            }
        }
        cout << (possible ? "1" : "-1") << "\n";
    }
    return 0;
}