#include <iostream>
#include <string>
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
        int n, k; cin >> n >> k;
        string s, result; cin >> s;
        sort(s.begin(), s.end());
        vector <string> a(k);
        for (int i = 0; i < k; i++) {
            a[i].push_back(s[i]);
        }
        if (a[k - 1] != a[0] || s.length() == k) {
            result = a[k - 1];
        }
        else {
            s = s.substr(k, n - 1);
            if (s.front() != s.back()) {
                result = a[0] + s;
            }
            else {
                result = a[0] + s.substr(0, s.length() / k + (s.length() % k != 0));
            }
        }
        cout << result << "\n";
    }
    return 0;
}