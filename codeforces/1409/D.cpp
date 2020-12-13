#include <iostream>
#include <vector>
using namespace std;
     
typedef long long ll;
#define fi first
#define se second
#define mp make_pair

ll sod (ll a) {
    ll k = a, sum = 0;
    while (k > 0) {
        sum += (k % 10);
        k /= 10;
    }
    return sum;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int t; cin >> t;
    while (t--) {
        ll n, s; 
        cin >> n >> s;
        vector <ll> c;
        c.push_back(n);
        for (ll i = 10; i <= 1e18; i *= 10) {
            c.push_back(n + (i - (n % i)));
        }
        for (int i = 0; i < c.size(); i++) {
            if (sod(c[i]) <= s) {
                cout << c[i] - n << "\n";
                break;
            }
        }
    }
    return 0;
}