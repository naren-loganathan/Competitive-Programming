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
        int n, x; cin >> n >> x;
        ll min_sum = 0, max_sum = 0, lol = 0;
        vector <ll> a(n), y;
        for (int i = 0; i < n; i++) {
            cin >> a[i];
            if (a[i] % x) {
                max_sum += (a[i] / x) + 1;
                lol += a[i];
            }
            else {
                max_sum += (a[i] / x);
                min_sum += (a[i] / x);
            }
        }
        if (lol % x == 0) {
            min_sum += (lol / x);
        }
        else {
            min_sum += (lol / x) + 1;
        }
        cout << min_sum << " " << max_sum << "\n";
    }
    return 0;
}