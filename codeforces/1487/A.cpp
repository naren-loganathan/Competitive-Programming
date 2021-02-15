#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
             
typedef long long ll;
#define fi first
#define se second
#define mp make_pair

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int t; cin >> t;
    while (t--) {
        int n; cin >> n;
        vector <int> a(n);
        for (int i = 0; i < n; i++) {
            cin >> a[i];
        }
        sort(a.begin(), a.end());
        int answer = 0;
        for (int i = 0; i < n; i++) {
            if (a[i] != a.front()) {
                answer++;
            }
        }
        cout << answer << "\n";
    }
    return 0;
}