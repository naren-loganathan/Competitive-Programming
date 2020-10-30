#include <iostream>
using namespace std;

typedef long long int ll;

int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int a, b, c;
    cin >> a >> b >> c;
    if (c > 0) {
        cout << (((b - a) % c || (b - a) < 0)? "NO" : "YES") << "\n";
    }
    else if (c < 0) {
        cout << (((b - a) % c || (b - a) > 0)? "NO" : "YES") << "\n";
    }
    else {
        cout << (a != b ? "NO" : "YES") << "\n";
    }
    return 0;
}