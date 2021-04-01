#include <iostream>
using namespace std;            

typedef long long ll;
#define fi first
#define se second
#define mp make_pair

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int a; cin >> a;
    while (a > 9) {
        int x = 0;
        while (a > 0) {
            x += (a % 10);
            a /= 10;
        }
        a = x;
    }
    cout << a << '\n';
    return 0;
}