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
        int a, b, cnt = 1e9; cin >> a >> b;
        for (int i = b; i <= b + 100; i++) {
            if (i != 1) {
                int x = a, op = 0;
                while (x) {
                    x /= i;
                    op++;
                }
                cnt = min(cnt, i - b + op);
            }
        }
        cout << cnt << '\n';
    }
    return 0;
}