#include <iostream>
#include <vector>
#include <map>
#include <cmath>
using namespace std;

typedef long long ll;
#define fi first
#define se second
#define mp make_pair

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int n; cin >> n;
    vector <int> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    map <int, int> dp;
    for (int i = 0; i < n; i++) {
        dp[a[i]] = max(dp[a[i] - 1] + 1, dp[a[i]]);
    }
    int val = 0, start = 0;
    map <int, int> :: iterator it;
    for (it = dp.begin(); it != dp.end(); it++) {
        if (it -> se > val) {
            val = it -> se; start = it -> fi;
        }
    }
    vector <int> subseq;
    for (int i = n - 1; i >= 0; i--) {
        if (a[i] == start) {
            subseq.push_back(i + 1);
            start--;
        }
    }
    cout << subseq.size() << '\n';
    for (int i = subseq.size() - 1; i >= 0; i--) {
        cout << subseq[i] << ' ';
    }
    cout << '\n';
    return 0;
}