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
        string a; cin >> a;
        int n = a.length();
        bool possible = 0;
        char f = a.front(), b = a.back();
        if (b != f) {
            for (int i = 0; i < n; i++) {
                if (a[i] == b) a[i] = ')';
                else if (a[i] == f) a[i] = '(';
            }
            int cnt_f = 0, cnt_b = 0;
            possible = 0;
            for (int i = 0; i < n; i++) {
                if (a[i] == '(') cnt_f += 1;
                else cnt_b += 1;
                if (cnt_f < cnt_b) {
                    break;
                }
            }
            if (cnt_f == cnt_b && cnt_f == n / 2) {
                possible = 1;
            }
            else {
                cnt_f = 0; cnt_b = 0;
                for (int i = 0; i < n; i++) {\
                    if (a[i] == ')') cnt_b += 1;
                    else cnt_f += 1;
                    if (cnt_f < cnt_b) {
                        break;
                    }
                }
                if (cnt_f == cnt_b && cnt_f == n / 2) {
                    possible = 1;
                }
            }
        }
        cout << (possible ? "YES" : "NO") << "\n";
    }
    return 0;
}