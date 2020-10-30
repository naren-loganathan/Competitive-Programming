#include <iostream>
#include <cmath>
using namespace std;

typedef long long int ll;
#define fi first
#define se second

int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int a, b; cin >> a >> b;
    cout << ((a || b) && abs(a - b) < 2 ? "YES" : "NO") << "\n";
    return 0;
}