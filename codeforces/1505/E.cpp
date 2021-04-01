#include <iostream>
#include <vector>
#include <set>
#include <string>
#include <cmath>
using namespace std;

typedef long long ll;
#define fi first
#define se second
#define mp make_pair

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int h, w, ans = 0; 
    cin >> h >> w;
    vector <string> cake(h);
    for (int i = 0; i < h; i++) {
        cin >> cake[i];
    }
    int x = 0, y = 0;
    if (cake[x][y] == '*') ans += 1;
    set <pair <int, pair <int, int> > > pts; 
    while (true) {
        for (int i = x; i < h; i++) {
            for (int j = y; j < w; j++) {
                if (cake[i][j] == '*') {
                    int dist = (i - x) + (j - y);
                    if (dist) pts.insert(mp(dist, mp(i, j)));
                }
            }
        }
        if (pts.empty()) break;
        else {
            ans += 1;
            pair <int, pair <int, int> > nxt = *(pts.begin());
            x = nxt.se.fi; y = nxt.se.se;
            pts.clear();
        }
    }
    cout << ans << '\n';
    return 0;
}