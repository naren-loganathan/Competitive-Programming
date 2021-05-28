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
        int x; cin >> x;
        bool poss = false;
        if (x % 11 == 0) {
            poss = true;
        } else {
            int y = x % 11;
            if (y * 111 <= x) {
                poss = true;
            }
        }
        cout << (poss ? "YES" : "NO") << '\n';
    }
    return 0;
}