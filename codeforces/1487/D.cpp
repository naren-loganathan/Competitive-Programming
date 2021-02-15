#include <iostream>
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
        int n; cin >> n;
        n = floor(sqrt(2 * n - 1));
        if (n % 2 == 0) {
            cout << n / 2 - 1 << "\n";
        }
        else {
            cout << n / 2 << "\n";
        }
    }
    return 0;
}