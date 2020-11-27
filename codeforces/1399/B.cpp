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
        ll n, x = 6969696969, y = 6969696969; 
        cin >> n;
        vector <ll> a(n), b(n);
        for (int i = 0; i < n; i++) {
            cin >> a[i];
            x = min(x, a[i]);
        }
        for (int i = 0; i < n; i++) {
            cin >> b[i];
            y = min(y, b[i]);
        }
        ll sum = 0;
        for (int i = 0; i < n; i++) {
            sum += max(a[i] - x, b[i] - y);
        }
        cout << sum << "\n";
    }
    return 0;
}