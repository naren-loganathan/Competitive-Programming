#include <iostream>
#include <vector>
#include <map>
using namespace std;

typedef long long int ll;
#define M 1000000007
#define mp make_pair
#define ub upper_bound

int main(){
    ios_base::sync_with_stdio(false); 
    cin.tie(NULL);
    ll n, m, pairs = 0;
    cin >> n >> m;
    for (int i = 1; i < 5; i++) {
        ll a = n / 5, b = m / 5;
        if (n % 5 >= i) {
            a++;
        }
        if (m % 5 >= (5 - i)) {
            b++;
        }
        pairs += a * b;
    }
    pairs += (n / 5) * (m / 5);
    cout << pairs << "\n";
    return 0;
}