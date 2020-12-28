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
        string s; cin >> s;
        bool possible = 1;
        int cntf = 0, cntb = 0;
        if (s.length() % 2 || s[0] == ')' || s[s.length() - 1] == '(') {
            possible = 0;
        }
        for (int i = 0; i < s.length(); i++) {
            if (s[i] == '(') {
                cntf++;
            }
            else if (s[i] == ')') {
                cntb++;
            }
            else {
                if (cntf > cntb) {
                    cntb++;
                }
                else {
                    cntf++;
                }
            }
        }
        if (cntf != s.length() / 2 || cntb != s.length() / 2) {
            possible = 0;
        }
        cout << (possible ? "YES" : "NO") << "\n";
    }
    return 0;
}