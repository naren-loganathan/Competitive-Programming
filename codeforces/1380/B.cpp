#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
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
        string s, r; cin >> s;
        vector < pair <int, char> > cnt;
        cnt.push_back(mp(0, 'R'));
        cnt.push_back(mp(0, 'P'));
        cnt.push_back(mp(0, 'S'));
        for (int i = 0; i < s.length(); i++) {
            if (s[i] == 'R') {
                cnt[0].fi++;
            }
            else if (s[i] == 'P') {
                cnt[1].fi++;
            }
            else {
                cnt[2].fi++;
            }
        }
        sort(cnt.begin(), cnt.end());
        for (int i = 0; i < s.length(); i++) {
            if (cnt[2].se == 'R') {
                r.push_back('P');
            }
            else if (cnt[2].se == 'P') {
                r.push_back('S');
            }
            else {
                r.push_back('R');
            }
        }
        cout << r << "\n";
    }
    return 0;
}