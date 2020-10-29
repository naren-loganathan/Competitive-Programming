#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

typedef long long int ll;

int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    ll n, max_score = 0, sum = 0; 
    cin >> n;
    vector <ll> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
        sum += a[i];
    }
    sort(a.begin(), a.end());
    max_score = sum;
    if (a.size() > 1) {
        max_score += sum;
        for (int i = 0; i < n - 2; i++) {
            sum -= a[i];
            max_score += sum;
        }
    }
    cout << max_score << "\n";
    return 0;
}