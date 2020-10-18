#include <iostream>
#include <cmath>
using namespace std;

typedef long long int ll;
#define M 1000000007
#define mp make_pair
#define ub upper_bound

int main(){
    ios_base::sync_with_stdio(false); 
    cin.tie(NULL);
    ll a1, a2, a3, l, b, h;
    cin >> a1 >> a2 >> a3;
    l = (floor(sqrt(a1 * a2 * a3 / a1 / a1)));
    b = (floor(sqrt(a1 * a2 * a3 / a2 / a2)));
    h = (floor(sqrt(a1 * a2 * a3 / a3 / a3)));
    cout << 4 * (l + b + h) << "\n";
    return 0;
}