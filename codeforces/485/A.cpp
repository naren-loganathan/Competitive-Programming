#include <iostream>
#include <set>
using namespace std;

typedef long long ll;
#define fi first
#define se second
#define mp make_pair
 
int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int a, m; cin >> a >> m;
    set <int> s;
    int x = a % m;
    bool possible = 1;
    while (possible) {
        if (x) {
            s.insert(x);
        }
        else {
            break;
        }
        while (x < m) {
            x *= 2;
        }
        if (x == m) {
            break;
        }
        else if (x > m) {
            x %= m;
            if (s.find(x) != s.end()) {
                possible = 0;
            }
        }
    }
    cout << (possible ? "Yes" : "No") << "\n";
    return 0;
}