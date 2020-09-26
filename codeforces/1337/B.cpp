#include <iostream>
using namespace std;

typedef long long int ll;
#define M 1000000007
#define pb push_back

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t; cin >> t;
    while (t--) {
        bool possible = 0;
        int x, n, m;
        cin >> x >> n >> m;
        int lightning_hits = 10 * m;
        while (x > lightning_hits && n > 0) {
            x = x / 2 + 10;
            n--;
        }
        if (x <= lightning_hits) {
            possible = 1;
        }
        cout << (possible ? "YES\n" : "NO\n");
    }
    return 0;
}