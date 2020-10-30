#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

typedef long long int ll;
#define fi first
#define se second

int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n, k, m, sum = 0; 
    cin >> n >> k;
    vector < pair <int, int> > a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i].fi;
        a[i].se = i + 1;
        sum += a[i].fi;
    }
    sort(a.begin(), a.end());
    while (sum > k) {
        sum -= a.back().fi;
        a.pop_back();
    }
    cout << a.size() << "\n";
    for (int i = 0; i < a.size(); i++) {
        cout << a[i].se << " ";
    }
    if (a.size()) {
        cout << "\n";
    }
    return 0;
}