#include <iostream>
using namespace std;

typedef long long int ll;
#define fi first
#define se second
#define mp make_pair

int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    ll a, b, count = 0; 
    cin >> a >> b;
    while (a && b) {
        count += a / b;
        a %= b;
        swap(a, b);
    }
    cout << count << "\n";
    return 0;
}