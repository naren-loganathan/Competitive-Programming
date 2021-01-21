#include <iostream>
using namespace std;
             
typedef long long ll;
#define fi first
#define se second
#define mp make_pair

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int n; cin >> n;
    cout << 3 * n + 4 << "\n";
    int x = 0, y = 0;
    for (int i = 0; i <= n + 1; i++) {
        cout << x << " " << y << "\n";
        if (i) {
            cout << x << " " << y - 1 << "\n";
        }
        if (i <= n) {
            cout << x << " " << y + 1 << "\n";
        }
        x++; y++;
    }
    return 0;
}
