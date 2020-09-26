#include <iostream>
using namespace std;

typedef long long int ll;
#define M 1000000007
#define pb push_back

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t, n;
    cin >> t;
    while(t--){
        cin >> n;
        int pow = 4;
        while (n % (pow - 1) != 0) {
            pow *= 2;
        }
        cout << n / (pow - 1) << endl;
    }
    return 0;
}