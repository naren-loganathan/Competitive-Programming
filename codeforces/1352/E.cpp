#include <iostream>
#include <vector>
#include <set>
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
        int n, cnt = 0; cin >> n;
        vector <int> a(n), p(n + 1, 0);
        for (int i = 0; i < n; i++) {
            cin >> a[i];
            p[i + 1] = a[i] + p[i];
        }
        vector <bool> special(n + 1, 0);
        for (int i = 2; i <= n; i++) {
            for (int j = i - 2; (j >= 0 && p[i] - p[j] <= n); j--) {
                special[p[i] - p[j]] = 1;
            }
        }
        for (int i = 0; i < n; i++) {
            if (special[a[i]]) {
                cnt++;
            }
        }
        cout << cnt << "\n";
    }
    return 0;
}
