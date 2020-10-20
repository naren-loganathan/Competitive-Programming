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
        int x, count = 0; 
        cin >> x;
        int lim = x % 10;
        for (int i = 1; i < lim; i++) {
            count += 10;
        }
        count++;
        int j = lim, k = 2;
        while (j < x) {
            j = j * 10 + lim;
            count += k;
            k++;
        }
        cout << count << "\n";
    }
    return 0;
}