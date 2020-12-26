#include <iostream>
#include <string>
#include <vector>
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
        int pos_x = 0, pos_y = 0, res_x = 0, res_y = 0;
        vector < pair <int, int> > o;
        for (int i = 0; i < s.length(); i++) {
            if (s[i] == 'R') {
                pos_x++;
            } 
            else if (s[i] == 'L') {
                pos_x--;
            }
            else if (s[i] == 'U') {
                pos_y++;
            }
            else if (s[i] == 'D') {
                pos_y--;
            }
            o.push_back(mp(pos_x, pos_y));
        }
        for (int i = 0; i < o.size(); i++) {
            pos_x = 0; pos_y = 0;
            for (int j = 0; j < s.length(); j++) {
                if (s[j] == 'R' && (o[i].se != pos_y || pos_x + 1 != o[i].fi)) {
                    pos_x++;
                } 
                else if (s[j] == 'L' && (o[i].se != pos_y || pos_x - 1 != o[i].fi)) {
                    pos_x--;
                }
                else if (s[j] == 'U' && (o[i].fi != pos_x || pos_y + 1 != o[i].se)) {
                    pos_y++;
                }
                else if (s[j] == 'D' && (o[i].fi != pos_x || pos_y - 1 != o[i].se)) {
                    pos_y--;
                }
            }
            if (pos_x == 0 && pos_y == 0) {
                res_x = o[i].fi; res_y = o[i].se;
                break;
            }
        }
        cout << res_x << " " << res_y << "\n";
    }
    return 0;
}