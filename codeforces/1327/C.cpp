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
    int n, m, k, x, y;
    string actions = "";
    cin >> n >> m >> k;
    for (int i = 0; i < 2 * k; i++) {
        cin >> x >> y;
    }
    for (int i = 1; i < n; i++) {
        actions.push_back('D');
    }
    for (int i = 1; i < m; i++) {
        actions.push_back('L');
    }
    bool up = 1;
    for (int i = 0; i < m; i++) {
        if (up) {
            for (int i = 1; i < n; i++) {
                actions.push_back('U');
            }
        }
        else {
            for (int i = 1; i < n; i++) {
                actions.push_back('D');
            }
        }
        up = !up;
        actions.push_back('R');
    }
    cout << actions.length() << "\n" << actions << "\n";
    return 0;
}