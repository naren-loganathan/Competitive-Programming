#include <iostream>
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
        ll n, result = 0; 
        cin >> n;
        for (ll i = n; i > 0; i -= 2) {
            result += 4 * (i - 1) * (i / 2);
        }
        cout << result << "\n";
    }
    return 0;
}