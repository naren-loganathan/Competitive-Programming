#include <iostream>
#include <set>
using namespace std;

typedef long long int ll;

int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n, a; cin >> n;
    set <int> numba;
    for (int i = 0; i < n; i++) {
        cin >> a;
        while (!(a % 3)) {
            a /= 3;
        }
        while (!(a % 2)) {
            a /= 2;
        }
        numba.insert(a);
    }
    cout << (numba.size() == 1 ? "Yes\n" : "No\n");
    return 0;
}