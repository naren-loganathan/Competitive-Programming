#include <iostream>
#include <cmath>
using namespace std;
     
typedef long long ll;
#define fi first
#define se second
#define mp make_pair

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int a, b; cin >> a >> b;
    int x = min(a, b);
    cout << x << " ";
    a -= x; b -= x;
    cout << (a + b) / 2 << "\n";
    return 0;
}