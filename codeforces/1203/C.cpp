#include <iostream>
#include <vector>
using namespace std;

typedef long long int ll;
#define M 1000000007
#define mp make_pair
#define ub upper_bound

ll gcd (ll a, ll b) {
    return (b ? gcd(b, a % b) : a);
}

int main(){
    ios_base::sync_with_stdio(false); 
    cin.tie(NULL);
    int n; cin >> n;
    vector <ll> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    ll result = a[0];
    int answer = 0;
    for (int i = 1; i < n; i++) {
        result = gcd(result, a[i]);
    }
    for (ll i = 1; i * i <= result; i++) {
        if (result % i == 0) {
            answer++;
            if (i * i != result) {
                answer++;
            }
        }
    }
    cout << answer << "\n";
    return 0;
}