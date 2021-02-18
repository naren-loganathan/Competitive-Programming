#include <iostream>
#include <vector>
#include <algorithm>
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
        int n; cin >> n;
        vector <ll> x(n), y(n);
        for (int i = 0; i < n; i++) {
            cin >> x[i] >> y[i];
        }
        sort(x.begin(), x.end());
        sort(y.begin(), y.end());
        if (n % 2) {
            cout << "1" << "\n";
        }
        else {
            ll pos_x = x[n / 2] - x[n / 2 - 1] + 1;
            ll pos_y = y[n / 2] - y[n / 2 - 1] + 1;
            cout << pos_x * pos_y << "\n";
        }
    }
    return 0;
}