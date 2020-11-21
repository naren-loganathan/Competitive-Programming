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
        int n, ans; 
        cin >> n;
        if (n == 1) {
            ans = 0;
        }
        else if (n == 2) {
            ans = 1;
        }
        else if (n == 3) {
            ans = 2;
        }
        else if (n > 3 && n % 2) {
            ans = 3;
        }
        else {
            ans = 2;
        }
        cout << ans << "\n";
    }
    return 0;
}