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
        int q, d; cin >> q >> d;
        while (q--) {
            bool possible = 0;
            int a; cin >> a;
            if (a >= d * 10) {
                possible = 1;
            }
            else {
                int x = a, cnt = 0;
                while (x > 0 && cnt <= 10) {
                    cnt++;
                    x -= d;
                    if (x % 10 == 0) {
                        possible = 1;
                        break;
                    }
                }
            }
            cout << (possible ? "Yes" : "No") << "\n";
        }
    }
    return 0;
}