#include <iostream>
#include <vector>
#include <set>
#include <algorithm>
using namespace std;
     
typedef long long ll;
#define fi first
#define se second
#define mp make_pair

//Implementation! Reeeeeeeeee!

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int t; cin >> t;
    while (t--) {
        bool possible = 0;
        int n, x; cin >> n;
        vector <int> a(2 * n);
        for (int i = 0; i < 2 * n; i++) {
            cin >> a[i];
        }
        sort (a.begin(), a.end());
        vector < pair <int, int> > moves;
        for (int i = 0; i < 2 * n - 1; i++) {
            multiset <int, greater <int> > b;
            for (auto num : a) {
                b.insert(num);
            }
            x = a[i] + a.back();
            moves.push_back(mp(a[i], a.back()));
            int temp_x = a.back();
            b.erase(b.find(a[i])); b.erase(b.find(a.back()));
            while (!b.empty()) {
                int q = *(b.begin());
                b.erase(b.find(q));
                int p = temp_x - q;
                if (b.find(p) != b.end()) {
                    b.erase(b.find(p));
                    moves.push_back(mp(p, q));
                    temp_x = q;
                }
                else {
                    break;
                }
            }
            if (b.empty()) {
                possible = 1;
                break;
            }
            else {
                moves.clear();
            }
        }
        if (possible) {
            cout << "YES" << "\n" << x << "\n";
            for (auto pairs : moves) {
                cout << pairs.fi << " " << pairs.se << "\n";
            }
        }
        else {
            cout << "NO" << "\n";
        }
    }
    return 0;
}