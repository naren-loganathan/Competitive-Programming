#include <iostream>
#include <vector>
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
        int first, second;
        int n; cin >> n;
        vector <int> a(n);
        for (int i = 0; i < n; i++) {
            cin >> a[i];
            if (a[i] == 1) {
                second = i;
            }
        }
        for (int i = 0; i < n; i++) {
            if (a[i] == 1) {
                first = i;
                break;
            }
        }
        int shift = 0;
        for (int i = first; i <= second; i++) {
            if (a[i] == 0) {
                shift++;
            }
        }
        cout << shift << "\n";
    }
    return 0;
}