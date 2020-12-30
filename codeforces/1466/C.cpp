#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <cmath>
#include <set>
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
        vector <bool> changed(s.length(), 0);
        int cnt = 0;
        for (int i = 1; i < s.length(); i++) {
            if (s[i] == s[i - 1] && !changed[i - 1]) {
                changed[i] = 1;
            }
            if (s[i] == s[i - 2] && !changed[i - 2]) {
                changed[i] = 1;
            }
        }
        for (int i = 0; i < s.length(); i++) {
            if (changed[i]) {
                cnt++;
            }
        }
        cout << cnt << "\n";
    }
    return 0;
}