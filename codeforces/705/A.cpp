#include <iostream>
using namespace std;
     
typedef long long ll;
#define fi first
#define se second
#define mp make_pair
     
int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int n; cin >> n;
    for (int i = 1; i < n; i++) {
        if (i % 2) {
            cout << "I hate that ";
        }
        else {
            cout << "I love that ";
        }
    }
    if (n % 2) {
        cout << "I hate it\n";
    }
    else {
        cout << "I love it\n";
    }
    return 0;
}