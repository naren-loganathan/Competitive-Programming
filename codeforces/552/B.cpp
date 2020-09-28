#include <iostream>
#include <cmath>
using namespace std;

typedef long long int ll;
#define M 1000000007
#define pb push_back

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    ll n, i, digits = 0; 
    cin >> n;
    for (i = 10; i <= n; i *= 10) {
        digits += 9 * log10(i) * (i / 10);
    }
    if (i > n) {
        digits += (n - (i - 1) / 10) * log10(i);
    }
    cout << digits << endl;
    return 0;
}