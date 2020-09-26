#include <iostream>
#include <string>
using namespace std;

typedef long long int ll;
#define M 1000000007
#define pb push_back

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n; cin >> n;
    if (n < 0) {
        if (n > -10) {
            n = 0;
        }
        else if (n > -100) {
            n *= -1;
            if(n % 10 < n / 10) {
                n = -1 * (n % 10);
            }
            else {
                n /= -10;
            }
        }
        else {
            n *= -1;
            if (n % 10 <= (n / 10) % 10) {
                n = (n / 100) * 10 + (n % 10);
                n *= -1;
            }
            else {
                n /= -10;
            }
        }
    }
    cout << n << endl;
    return 0;
}