#include <iostream>
#include <vector>
using namespace std;

typedef long long ll;
#define fi first
#define se second
#define mp make_pair

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int n; cin >> n;
    vector <pair <int, int> > w, b;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            ((i + j) % 2 ? w.push_back(mp(i, j)) : b.push_back(mp(i, j)));
        }
    }
    for (int i = 0; i < n * n; i++) {
        int a; cin >> a;
        if (a == 1) {
            if (!b.empty()) {
                cout << 2 << ' ' << b.back().fi << ' ' << b.back().se << endl;
                b.pop_back();
            } else {
                cout << 3 << ' ' << w.back().fi << ' ' << w.back().se << endl;
                w.pop_back();
            }
        } else if (a == 2) {
            if (!w.empty()) {
                cout << 1 << ' ' << w.back().fi << ' ' << w.back().se << endl;
                w.pop_back();
            } else {
                cout << 3 << ' ' << b.back().fi << ' ' << b.back().se << endl;
                b.pop_back();
            }
        } else {
            if (!w.empty()) {
                cout << 1 << ' ' << w.back().fi << ' ' << w.back().se << endl;
                w.pop_back();
            } else {
                cout << 2 << ' ' << b.back().fi << ' ' << b.back().se << endl;
                b.pop_back();
            }
        }
    }
    return 0;
}