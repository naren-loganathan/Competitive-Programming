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
    ll n, result; cin >> n;
    if (n < 3) {
        result = n;
    }
    else {
        if (n % 2) {
            result = n * (n - 1) * (n - 2);
        }
        else {
            result = (n - 1) * (n - 2) * (n - 3);
            if (n % 3) {
                result /= (n - 2);
                result *= n;
            }
        }
    }
    cout << result << "\n";
    return 0;
}