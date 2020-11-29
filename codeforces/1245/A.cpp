#include <iostream>
using namespace std;
     
typedef long long ll;
#define fi first
#define se second
#define mp make_pair

int gcd (int a, int b) {
    return (b ? gcd(b, a % b) : a);
}
     
int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int t; cin >> t;
    while (t--) {
        int a, b; cin >> a >> b;
        cout << (gcd(a, b) == 1 ? "Finite" : "Infinite") << "\n";
    }
    return 0;
}