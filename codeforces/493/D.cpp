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
    if (n % 2 == 0) {
        cout << "white" << "\n" << "1 2" << "\n";
    }
    else {
        cout << "black" << "\n";
    }
    return 0;
}