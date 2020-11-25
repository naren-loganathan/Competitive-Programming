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
        int n, op = 69420; 
        cin >> n;
        vector <int> a(n);
        vector < vector < pair <int, int> > > bleh(n + 1);
        for (int i = 0; i < n; i++) {
            cin >> a[i];
        }
        int ap, length, start;
        for (int i = 0; i < n; i++) {
            if (i == 0) {
                start = 0;
                length = 1;
                ap = a[i];
            }
            else {
                if (a[i] != ap) {
                    bleh[ap].push_back(mp(start, length));
                    start = i;
                    length = 1;
                    ap = a[i];
                }
                else {
                    length++;
                }
            }
        }
        bleh[ap].push_back(mp(start, length));
        for (int i = 1; i <= n; i++) {
            if (bleh[i].size()) {
                int x = bleh[i].size() + 1;
                for (int j = 0; j < bleh[i].size(); j++) {
                    if (bleh[i][j].fi == 0 && bleh[i][j].se == n) {
                        x = 0;
                    }
                    else if (bleh[i][j].fi == 0 || bleh[i][j].fi + bleh[i][j].se == n) {
                        x--;
                    }
                }
                op = min(op, x);
            }
        }
        /*for (int i = 0; i <= n; i++) {
            for (int j = 0; j < bleh[i].size(); j++) {
                cout << "start -> " << bleh[i][j].fi << " " << "length -> " << bleh[i][j].se << " ";
            }
            cout << "\n";
        }*/
        cout << op << "\n";
    }
    return 0;
}