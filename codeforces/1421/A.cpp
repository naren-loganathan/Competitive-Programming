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
        int a, b, x = 0;
        cin >> a >> b;
        int c = 1;
        while (c <= a || c <= b) {
            int sa = a & c, sb = b & c;
            if (sa || sb) {
                x += c;
            }
            c *= 2;
        }
        cout << (a ^ x) + (b ^ x) << "\n";
    }
    return 0;
}