#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

typedef long long int ll;

int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n; cin >> n;
    vector <int> a(2 * n);
    for (int i = 0; i < 2 * n; i++) {
        cin >> a[i];
    }
    sort(a.begin(), a.end());
    if (a[0] == a[2 * n - 1]) {
        cout << "-1" << "\n";
    }
    else {
        for (int i = 0; i < 2 * n; i++) {
            cout << a[i] << " ";
        }
        cout << "\n";
    }
    return 0;
}