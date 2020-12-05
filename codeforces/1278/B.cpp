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
        ll a, b, diff, cnt = 0; 
        cin >> a >> b;
        diff = abs(a - b);
        while (cnt * (cnt + 1) / 2 < diff) {
            cnt++;
        }
        if ((cnt * (cnt + 1) / 2 - diff) % 2) {
            if (cnt % 2) {
                cnt += 2;
            }
            else {
                cnt++;
            }
        }
        cout << cnt << "\n";
    }
    return 0;
}