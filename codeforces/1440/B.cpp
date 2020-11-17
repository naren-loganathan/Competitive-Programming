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
        int n, k; cin >> n >> k;
        vector <ll> a(n * k + 1);
        for (int i = 1; i <= n * k; i++) {
            cin >> a[i];
        }
        ll sum = 0; int cnt = 0;
        for (int i = n * k - ceil(n / 2); cnt < k; i -= ceil(n / 2) + 1) {
            sum += a[i]; cnt++;
        }
        cout << sum << "\n";
    }
    return 0;
}