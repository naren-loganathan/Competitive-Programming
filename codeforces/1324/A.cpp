#include <iostream>
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
        int n, cnt = 0; cin >> n;
        for (int i = 0; i < n; i++) {
            int a; cin >> a;
            cnt += (a % 2);
        }
        cout << ((cnt == 0 || cnt == n) ? "YES" : "NO") << "\n";
    }
    return 0;
}