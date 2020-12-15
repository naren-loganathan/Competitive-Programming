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
        int x; cin >> x;
        string res = "";
        bool possible = 1;
        if (x > 45) {
            possible = 0;
        }
        else {
            vector <bool> include(10, 0);
            int sum = 0;
            for (int i = 9; i > 0; i--) {
                if (sum < x) {
                    if (sum + i <= x) {
                        sum += i;
                        include[i] = 1;
                    }
                }
            }
            for (int i = 1; i <= 9; i++) {
                if (include[i]) {
                    char c = 48 + i;
                    res += c;
                }
            }
        }
        if (possible) {
            cout << res << "\n";
        }
        else {
            cout << "-1" << "\n";
        }
    }
    return 0;
}