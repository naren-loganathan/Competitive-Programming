#include <iostream>
#include <string>
#include <map>
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
        int n, min_length = 1e9; cin >> n;
        string path; cin >> path;
        map < pair <int, int> , int> vis;
        pair <int, int> pos = mp(0, 0), removal;
        vis[pos] = 1;
        for (int i = 0; i < n; i++) {
            if (path[i] == 'L') {
                pos.fi--;
            }
            else if (path[i] == 'R') {
                pos.fi++;
            }
            else if (path[i] == 'U') {
                pos.se++;
            }
            else {
                pos.se--;
            }
            if (vis[pos]) {
                if (i + 2 - vis[pos] < min_length) {
                    min_length = i + 2 - vis[pos];
                    removal = mp(vis[pos], i + 1);
                }
            }
            vis[pos] = i + 2;
        }
        if (min_length == 1e9) {
            cout << "-1" << "\n";
        }
        else {
            cout << removal.fi << " " << removal.se << "\n";
        }
    }
    return 0;
}
