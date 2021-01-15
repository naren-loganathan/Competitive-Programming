#include <iostream>
#include <vector>
#include <algorithm>
#include <map>
#include <cmath>
using namespace std;
             
typedef long long ll;
#define fi first
#define se second
#define mp make_pair

//I suck at implementation.

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int t; cin >> t;
    while (t--) {
        int n, h, w; cin >> n;
        vector < pair <int, int> > dim(n), best_dudes;
        map <int, pair <int, int> > person;
        map <pair <int, int>, int> who;
        for (int i = 0; i < n; i++) {
            cin >> h >> w;
            int x = max(h, w), y = min(h, w);
            dim[i] = mp(x, y);
            person[i + 1] = mp(x, y);
            who[mp(x, y)] = i + 1;
        }
        sort(dim.begin(), dim.end());
        for (int i = 0; i < n; i++) {
            if (i == 0) {
                best_dudes.push_back(dim[i]);
            }
            else if (dim[i].fi != dim[i - 1].fi) {
                best_dudes.push_back(dim[i]);
            }
        }
        vector < pair <int, int> > min_width(best_dudes.size());
        min_width[0] = mp(best_dudes[0].se, 0);
        for (int i = 1; i < best_dudes.size(); i++) {
            if (best_dudes[i].se < min_width[i - 1].fi) {
                min_width[i] = mp(best_dudes[i].se, i);
            }
            else {
                min_width[i] = min_width[i - 1];
            }
        }
        for (int i = 1; i <= n; i++) {
            int idx = upper_bound(best_dudes.begin(), best_dudes.end(), mp(person[i].fi, 0)) - best_dudes.begin() - 1;
            if (idx >= 0 && min_width[idx].fi < person[i].se) {
                cout << who[best_dudes[min_width[idx].se]] << " ";
            }
            else {
                cout << "-1" << " ";
            }
        }
        cout << "\n";
    }
    return 0;
}