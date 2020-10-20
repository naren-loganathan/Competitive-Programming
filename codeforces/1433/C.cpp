#include <iostream>
#include <vector>
#include <cmath>
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
        int first, second, largest = -1;
        int n; cin >> n;
        vector <int> a(n);
        for (int i = 0; i < n; i++) {
            cin >> a[i];
            largest = max(largest, a[i]);
        }
        bool impossible = 1;
        for (int i = 0; i < n; i++) {
            if (a[i] != largest) {
                impossible = 0;
                break;
            }
        }
        if (impossible) {
            cout << "-1\n";
            continue;
        }
        for (int i = 0; i < n; i++) {
            if (a[i] == largest) {
                if (i == 0 && a[i + 1] < largest) {
                    cout << i + 1 << "\n";  
                    break;
                } 
                if (i == n - 1 && a[i - 1] < largest) {
                    cout << i + 1 << "\n";  
                    break;
                }
                if (i > 0 && i < n && (a[i + 1] + a[i - 1] < 2 * largest)) {
                    cout << i + 1 << "\n";  
                    break;
                }
            }
        }
    }
    return 0;
}