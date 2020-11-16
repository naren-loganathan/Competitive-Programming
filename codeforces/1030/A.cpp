#include <iostream>
using namespace std;
     
typedef long long ll;
#define fi first
#define se second
#define mp make_pair
     
int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    bool easy = 1;
    int n, a; cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> a;
        if (a) {
            easy = 0;
        }
    }
    cout << (easy ? "EASY" : "HARD") << "\n";
    return 0;
}