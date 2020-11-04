#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

typedef long long int ll;
#define fi first
#define se second
#define mp make_pair

int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n; cin >> n;
    vector <ll> d(n), prefix(n), suffix(n);
    for (int i = 0; i < n; i++) {
        cin >> d[i];
        prefix[i] = (i ? prefix[i - 1] + d[i] : d[i]);
    }
    for (int i = n - 1; i >= 0; i--) {
        suffix[i] = (i == n - 1 ? d[i] : suffix[i + 1] + d[i]);
    }
    int i = 0, j = n - 1;
    ll result = 0;
    while (i < j) {
        while (suffix[j] < prefix[i] && i < j) {
            j--;
        }
        if (suffix[j] == prefix[i] && i != j) {
            result = prefix[i];
        }
        i++;
    }
    cout << result << "\n";
    return 0;
}