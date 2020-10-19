#include <iostream>
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
        int n; cin >> n;
        cout << "2\n";
        cout << n << " " << n - 1 << "\n";
        while (n > 2) {
            cout << n << " " <<  n - 2 << "\n";
            n--;
        }
    }
    return 0;
}