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
        ll n, sum = 0; cin >> n;
        vector <ll> a(n), b(n, 1);
        for (int i = 0; i < n; i++) {
            cin >> a[i];
            sum += a[i];
        }
        ll suml = 0, sumr = 0, lcnt = 0, rcnt = 0;
        for (int i = 0; i < n; i += 2) {
            suml += a[i];
            lcnt++;
        }
        for (int i = 1; i < n; i += 2) {
            sumr += a[i];
            rcnt++;
        }
        if (2 * (suml - lcnt) <= sum) {
            for (int i = 1; i < n; i += 2) {
                b[i] = a[i];
            }
        }
        else {
            for (int i = 0; i < n; i += 2) {
                b[i] = a[i];
            }
        }
        for (int i = 0; i < n; i++) {
            cout << b[i] << " ";
        }
        cout << "\n";
    }
    return 0;
}