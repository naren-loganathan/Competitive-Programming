#include <iostream>
#include <string>
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
        string r, b; cin >> r >> b;
        int cntr = 0, cntb = 0, cnte = 0;
        for (int i = 0; i < n; i++) {
            if (b[i] > r[i]) {
                cntb++;
            }
            else if (b[i] < r[i]) {
                cntr++;
            }
            else {
                cnte++;
            }
        }
        if (cnte == n || (cntr == cntb)) {
            cout << "EQUAL" << "\n";
        }
        else {
            cout << (cntb > cntr ? "BLUE" : "RED") << "\n";
        }
    }
    return 0;
}