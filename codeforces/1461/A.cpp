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
        int n, k; cin >> n >> k;
        string res = "";
        for (int i = 0; i < n; i++) {
            if (i % 3 == 0) {
                res += 'a';
            }
            else if (i % 3 == 1) {
                res += 'b';
            }
            else if (i % 3 == 2) {
                res += 'c';
            }
        }
        cout << res << "\n";
    }
    return 0;
}