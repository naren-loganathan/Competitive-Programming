#include <iostream>
using namespace std;

typedef long long int ll;
#define fi first
#define se second

int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n, min_cost; cin >> n;
    if (n % 2) {
        min_cost = n / 2;
    }
    else {
        min_cost = n / 2 - 1;
    }
    cout << min_cost << "\n";
    return 0;
}