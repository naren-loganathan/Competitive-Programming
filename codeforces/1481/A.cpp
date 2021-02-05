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
        bool possible = 1;
        int px, py; cin >> px >> py;
        string s; cin >> s;
        int l = 0, r = 0, u = 0, d = 0;
        for (int i = 0; i < s.length(); i++) {
            if (s[i] == 'L') {
                l++;
            }
            else if (s[i] == 'R') {
                r++;
            }
            else if (s[i] == 'U') {
                u++;
            }
            else if (s[i] == 'D') {
                d++;
            }
        }
        if (px > 0) {
            if (r < px) {
                possible = 0;
            }
        }
        else {
            if (l < (-1) * px) {
                possible = 0;
            }
        }
        if (py > 0) {
            if (u < py) {
                possible = 0;
            }
        }
        else {
            if (d < (-1) * py) {
                possible = 0;
            }
        }
        cout << (possible ? "YES" : "NO") << "\n";
    }
    return 0;
}
