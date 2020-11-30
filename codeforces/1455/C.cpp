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
        int x, y, a = 0, b = 0;
        cin >> x >> y;
        if (x == y) {
            a = x - 1; b = y;
        }
        else if (x > y) {
            a = x - 1; b = y;
        }
        else {
            a = x - 1; b = y;
        }
        cout << a << " " << b << "\n";
    }
    return 0;
}