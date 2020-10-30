#include <iostream>
using namespace std;

typedef long long int ll;

int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n, ways = 0; cin >> n;
    if (n % 2 == 0) {
        n /= 2;
        ways = n / 2;
        if (n % 2 == 0) {
            ways--;
        }
    }
    cout << ways << "\n";
    return 0;
}