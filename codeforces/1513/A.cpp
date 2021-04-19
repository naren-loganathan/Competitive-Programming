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
        int n, k; cin >> n >> k;
        if (k > (n - 1) / 2) {
            cout << -1 << '\n';
        } else {
            vector <int> ans(n);
            int num = n;
            for (int i = 1; i < 2 * k + 1; i += 2) {
                ans[i] = num--;
            }
            num = 1;
            for (int i = 0; i < n; i++) {
                if (ans[i] == 0) ans[i] = num++;
            }
            for (int i = 0; i < n; i++) {
                cout << ans[i] << ' ';
            }
            cout << '\n';
        }
    }
    return 0;
}