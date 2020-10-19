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
        if (n == 1 || n == 2 || n == 4) {
            cout << "-1\n";
        }
        else {
            int c3 = 0, c5 = 0, c7 = 0;
            c3 = n / 3;
            n %= 3;
            while (n % 7 != 0 && n % 5 != 0) {
                c3--;
                n += 3;
            }
            if (n % 5 == 0) {
                c5 += (n / 5);
            }
            else if (n % 7 == 0) {
                c7 += (n / 7);
            }
            cout << c3 << " " << c5 << " " << c7 << "\n"; 
        }    
    }
    return 0;
}