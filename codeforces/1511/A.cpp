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
        int n; cin >> n;
        vector <int> r(n);
        int cnt = 0;
        for (int i = 0; i < n; i++) {
            cin >> r[i];
            if (r[i] != 2) {
                cnt++;
            }
        }
        cout << cnt << '\n';
    }
    return 0;
}