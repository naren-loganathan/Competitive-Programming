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
    int t; cin >> t;
    while (t--) {
        int n, m, x, cnt = 0;
        cin >> n >> m;
        vector <bool> ver(101, 0);
        vector <bool> hor(101, 0);
        for (int i = 0; i < n; i++) {
            cin >> x;
            ver[x] = 1;
        }
        for (int i = 0; i < m; i++) {
            cin >> x;
            hor[x] = 1;
        }
        for (int i = 0; i < 101; i++) {
            if (hor[i] && ver[i]) {
                cnt++;
            }
        }
        cout << cnt << "\n";
    }
    return 0;
}