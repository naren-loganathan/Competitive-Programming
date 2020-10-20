#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

typedef long long int ll;
#define M 1000000007
#define mp make_pair
#define ub upper_bound

int main(){
    ios_base::sync_with_stdio(false); 
    cin.tie(NULL);
    int t; cin >> t;
    while (t--) {
        bool possible = 0;
        int n, unequal; 
        cin >> n;
        vector <int> a(n + 1);
        for (int i = 1; i <= n; i++) {
            cin >> a[i];
            if (i > 1) {
                if (a[i] != a[i - 1]) {
                    possible = 1;
                }
            }
        }
        if (possible) {
            int one = 1, two;
            cout << "YES\n";
            for (int i = 2; i <= n; i++) {
                if (a[i] != a[1]) {
                    cout << one << " " << i << "\n";
                    two = i;
                }
            }
            for (int i = 2; i <= n; i++) {
                if (a[i] == a[1]) {
                    cout << two << " " << i << "\n";
                }
            }
        }
        else {
            cout << "NO\n";
        }
    }
    return 0;
}