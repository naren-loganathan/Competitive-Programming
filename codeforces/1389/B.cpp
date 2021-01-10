#include <iostream>
#include <vector>
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
        int n, k, z, result = 0;
        cin >> n >> k >> z;
        vector <int> a(n), p(n), best_pair(n + 1, 0);
        for (int i = 0; i < n; i++) {
            cin >> a[i];
            p[i] = (i ? a[i] + p[i - 1] : a[i]);
            if (i) {
                best_pair[i] = max(a[i] + a[i - 1], best_pair[i - 1]);
            }
        }
        for (int pairs = 0; pairs <= min(z, k / 2); pairs++) {
            int score = p[k - 2 * pairs] + pairs * best_pair[k + 1 - 2 * pairs];
            result = max(result, score);
        }
        cout << result << "\n";
    }
    return 0;
}