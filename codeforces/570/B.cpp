#include <iostream>
using namespace std;

typedef long long int ll;
#define fi first
#define se second

int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n, m; cin >> n >> m;
    if (n == 1) {
        cout << "1" << "\n";
    }
    else {
        if (m <= n / 2) {
            cout << m + 1 << "\n";
        }
        else {
            cout << m - 1 << "\n";
        }
    }
    return 0;
}