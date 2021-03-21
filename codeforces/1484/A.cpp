#include <iostream>
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
        int a, b; cin >> a >> b;
        cout << a * b << '\n';
    }
    return 0;
}