#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

typedef long long int ll;
#define fi first
#define se second
#define mp make_pair

int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t; cin >> t;
    while (t--) {
        ll n; cin >> n;
        vector <ll> v(n);
        for (int i = 0; i < n; i++) {
            cin >> v[i];
        }
        bool possible = 1;
        vector <ll> a(n), b(n);
        a[0] = v[0]; b[0] = 0;
        for (int i = 1; i < n; i++) {
            a[i] = min(a[i - 1], v[i] - b[i - 1]);
            if (a[i] < 0) {
                possible = 0;
                break;
            }
            b[i] = v[i] - a[i];
        }
        cout << (possible ? "YES" : "NO") << "\n";
    }
    return 0;
}