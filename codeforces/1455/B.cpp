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
        int x, cnt = 0; cin >> x;
        int n = 1;
        while (n * (n + 1) / 2 < x) {
            n++;
        }
        if (n * (n + 1) / 2 == x) {
            cnt = n;
        }
        else {
            int c = n + (n * (n + 1) / 2 - x);
            if (n != 2) {
                n--;
                int diff = x - n * (n + 1) / 2;
                cnt = n + (diff / (n - 1)) + (diff % (n - 1) ? 1 : 0);
                cnt = min(cnt, c);
            }
            else {
                cnt = c;
            }
        }
        cout << cnt << "\n";
    }
    return 0;
}