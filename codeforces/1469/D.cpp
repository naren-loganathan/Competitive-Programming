#include <iostream>
#include <vector>
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
        int n; cin >> n;
        vector < pair <int, int> > moves;
        for (int i = n - 1; i > 2; i--) {
            if (i != 8) {
                moves.push_back(mp(i, n));
            }
        }
        int x = n;
        if (n > 8) {
            while (x != 1) {
                moves.push_back(mp(n, 8));
                if (x % 8 == 0) {
                    x /= 8;
                }
                else {
                    x /= 8;
                    x++;
                }
            }
            for (int i = 0; i < 3; i++) {
                moves.push_back(mp(8, 2));
            }
        }
        else {
            while (x != 1) {
                moves.push_back(mp(n, 2));
                if (x % 2 == 0) {
                    x /= 2;
                }
                else {
                    x /= 2;
                    x++;
                }
            }
        }
        cout << moves.size() << "\n";
        for (int i = 0; i < moves.size(); i++) {
            cout << moves[i].fi << " " << moves[i].se << "\n";
        }
    }
    return 0;
}