#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

typedef long long int ll;

int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t; cin >> t;
    while (t--) {
        int n, odd = 0, even = 0; 
        cin >> n;
        bool possible = 0;
        vector <int> a(n);
        for (int i = 0; i < n; i++) {
            cin >> a[i];
            (a[i] % 2 ? odd++ : even++);
        }
        if (odd % 2) {
            sort(a.begin(), a.end());
            for (int i = 1; i < n; i++) {
                if (a[i] == a[i - 1] + 1) {
                    possible = 1;
                    break;
                }
            }
        }
        else {
            possible = 1;
        }
        cout << (possible ? "YES" : "NO") << "\n";
    }
    return 0;
}