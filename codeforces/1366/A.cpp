#include <iostream>
#include <cmath>
using namespace std;

typedef long long int ll;

int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t; cin >> t;
    while (t--) {
        int a, b; 
        cin >> a >> b;
        cout << min(a, min(b, (a + b) / 3)) << "\n";
    }
    return 0;
}