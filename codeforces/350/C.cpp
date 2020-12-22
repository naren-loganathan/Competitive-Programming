#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
using namespace std;

typedef long long ll;
#define fi first
#define se second
#define mp make_pair

bool cmp (pair <int, int> &a, pair <int, int> &b) {
    return (abs(a.fi) + abs(a.se) < abs(b.fi) + abs(b.se));
}
 
int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int n, x, y, moves = 0; cin >> n;
    vector < pair <int, int> > bombs(n);
    for (int i = 0; i < n; i++) {
        cin >> x >> y;
        bombs[i] = mp(x, y);
        moves += ((x == 0 || y == 0) ? 4 : 6);
    }
    sort(bombs.begin(), bombs.end(), cmp);
    cout << moves << "\n";
    for (int i = 0; i < n; i++) {
        x = bombs[i].fi; y = bombs[i].se;
        if (x) {
            if (x > 0) {
                cout << "1" << " " << x << " " << "R" << "\n"; 
            }
            else {
                cout << "1" << " " << (-1) * x << " " << "L" << "\n";
            }
        }
        if (y) {
            if (y > 0) {
                cout << "1" << " " << y << " " << "U" << "\n"; 
            }
            else {
                cout << "1" << " " << (-1) * y << " " << "D" << "\n"; 
            }
        }
        cout << "2" << "\n";
        if (x) {
            if (x > 0) {
                cout << "1" << " " << x << " " << "L" << "\n"; 
            }
            else {
                cout << "1" << " " << (-1) * x << " " << "R" << "\n";
            }
        }
        if (y) {
            if (y > 0) {
                cout << "1" << " " << y << " " << "D" << "\n"; 
            }
            else {
                cout << "1" << " " << (-1) * y << " " << "U" << "\n";
            }
        }
        cout << "3" << "\n";
    }
    return 0;
}