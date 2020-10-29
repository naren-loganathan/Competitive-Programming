#include <iostream>
#include <iomanip>
#include <cmath>
using namespace std;

typedef long long int ll;
typedef long double ld;

int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    double pi = 3.141592653;
    int t; cin >> t;
    while (t--) {
        ld n, result; 
        cin >> n;
        result = 1.0 / tan(pi / (2.0 * n));
        cout << setprecision(9) << result << "\n";
    }
    return 0;
}