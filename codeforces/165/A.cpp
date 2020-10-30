#include <iostream>
#include <vector>
using namespace std;

typedef long long int ll;
#define fi first
#define se second

int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n, supercentral = 0; 
    cin >> n;
    vector < pair <int, int> > pts(n);
    for (int i = 0; i < n; i++) {
        cin >> pts[i].fi >> pts[i].se;
    }
    for (int i = 0; i < n; i++) {
        bool r = 0, l = 0, d = 0, u = 0;
        for (int j = 0; j < n; j++) {
            if (pts[i].fi == pts[j].fi) {
                if (pts[i].se > pts[j].se) {
                    d = 1;
                }
                else if (pts[i].se < pts[j].se) {
                    u = 1;
                }
            }
            if (pts[i].se == pts[j].se) {
                if (pts[i].fi > pts[j].fi) {
                    l = 1;
                }
                else if (pts[i].fi < pts[j].fi) {
                    r = 1;
                }
            }
            if (r && l && d && u) {
                supercentral++;
                break;
            }
        }
    }
    cout << supercentral << "\n";
    return 0;
}