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
    int q; cin >> q;
    while (q--) {
        int c, m, x, teams = 0;
        cin >> c >> m >> x;
        int y = min(c, min(m, x));
        c -= y; m -= y; x -= y;
        teams += y;
        if (c != 0 && m != 0) {
            teams += min((c + m) / 3, min(c, m));
        }
        cout << teams << "\n";
    }
    return 0;
}