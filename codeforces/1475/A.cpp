#include <iostream>
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
        while (n % 2 == 0) {
            n /= 2;
        }
        cout << (n != 1 ? "Yes" : "No") << "\n";
    }
    return 0;
}
