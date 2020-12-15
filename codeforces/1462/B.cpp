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
        bool possible = 0;
        int n; cin >> n;
        string s, f = "", r = ""; 
        cin >> s;
        for (int i = 0; i < 2; i++) {
            f += s[i];
        }
        for (int i = n - 1; i > n - 3; i--) {
            r += s[i];
        }
        if (f == "20" && r == "02") {
            possible = 1;
        }
        if (!possible) {
            for (int i = 2; i < 4; i++) {
                f += s[i];
            }
            for (int i = n - 3; i > n - 5; i--) {
                r += s[i];
            }
            if (f == "2020" || r == "0202") {
                possible = 1;
            }
        }
        if (!possible) {
            f = ""; r = "";
            r += s[n - 1];
            for (int i = 0; i < 3; i++) {
                f += s[i];
            }
            if (r == "0" && f == "202") {
                possible = 1;
            }
            f = ""; r = "";
            f += s[0];
            for (int i = n - 1; i > n - 4; i--) {
                r += s[i];
            }
            if (r == "020" && f == "2") {
                possible = 1;
            }
        }
        cout << (possible ? "YES" : "NO") << "\n";
    }
    return 0;
}