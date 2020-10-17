#include <iostream>
#include <cmath>
using namespace std;

typedef long long int ll;
#define M 1000000007
#define mp make_pair
#define ub upper_bound

int main(){
    ios_base::sync_with_stdio(false); 
    cin.tie(NULL);
    ll t; cin >> t;
    while (t--) {
        ll x1, y1, x2, y2;
        cin >> x1 >> y1 >> x2 >> y2;
        if (x1 == x2 || y1 == y2) {
            cout << abs(x1 - x2 + y1 - y2) << "\n";
        }
        else {
            cout << abs(x1 - x2) + 2 + abs(y1 - y2) << "\n";
        }
    }
    return 0;
}