#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

typedef long long ll;
#define fi first
#define se second
#define mp make_pair

bool is_prime(int x) {
    bool prime = (x % 2 != 0);
    for (int i = 3; i <= ceil(sqrt(x)); i++) {
        if (x % i == 0) {
            prime = false; break;
        }
    }
    return prime;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int n; cin >> n;
    if (n % 2 == 0) {    //Goldbach's conjecture?
        cout << (n == 2 ? 1 : 2) << '\n';
    } else {
        if (is_prime(n)) {
            cout << 1 << '\n';
        } else {
            if (is_prime(n - 2)) {
                cout << 2 << '\n';
            } else {
                cout << 3 << '\n';
            }
        }
    }
    return 0;
}