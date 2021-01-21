#include <iostream>
#include <vector>
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
        bool possible = 1;
        int n; cin >> n;
        map <int, int> pos;
        vector <int> p(n), gen(n, 0);
        for (int i = 0; i < n; i++) {
            cin >> p[i];
            pos[p[i]] = i;
        }
        int cnt = 1;
        while (cnt <= n) {
            if (gen[pos[cnt]]) {
                possible = 0;
                break;
            }
            for (int i = pos[cnt]; i < n && !gen[i]; i++) {
                gen[i] = cnt;
                cnt++;
            }
        }
        if (p != gen) {
            possible = 0;
        }
        cout << (possible ? "Yes" : "No") << "\n";
    }
    return 0;
}
