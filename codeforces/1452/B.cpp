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
        ll n; cin >> n;
        ll sum = 0, largest = 0;
        vector <ll> a(n);
        for (int i = 0; i < n; i++) {
            cin >> a[i];
            sum += a[i];
            largest = max(largest, a[i]);
        }
        ll diff = (sum % (n - 1) ? n - 1 - (sum % (n - 1)) : (ll) 0);
        cout << max(largest * (n - 1) - sum, diff) << "\n";
    }
    return 0;
}