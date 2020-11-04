#include <iostream>
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
        ll a, b; cin >> a >> b;
        ll result = 0;
        if (max(a, b) % min(a, b)) {
            result = -1;
        }
        else {
            ll div = max(a, b) / min(a, b);
            int pow = 0;
            while (div != 1) {
                if (div % 2) {
                    pow = -1;
                    break;
                }
                else {
                    div /= 2;
                    pow++;
                }
            }
            if (pow == -1) {
                result = -1;
            }
            else {
                result += pow / 3;
                pow %= 3;
                result += pow / 2;
                pow %= 2;
                result += pow;
            }
        }
        cout << result << "\n"; 
    }
    return 0;
}