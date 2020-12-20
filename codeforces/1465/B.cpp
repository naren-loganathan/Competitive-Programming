#include <iostream>
#include <vector>
#include <string>
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
        bool fair = 0;
        while (!fair) {
            fair = 1;
            ll x = n;
            while (x > 0) {
                if (x % 10 && n % (x % 10) != 0) {
                    fair = 0;
                    break;
                }
                else {
                    x /= 10;
                }
            }
            if (!fair) {
                n++;
            }
        }
        cout << n << "\n";
    }
    return 0;
}