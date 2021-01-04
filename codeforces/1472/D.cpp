#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <set>
#include <stack>
#include <queue>
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
        ll n; cin >> n;
        vector <ll> a(n);
        for (int i = 0; i < n; i++) {
            cin >> a[i];
        }
        ll alice = 0, bob = 0;
        sort(a.begin(), a.end(), greater <ll> ());
        for (int i = 0; i < n; i++) {
            if (i % 2 == 0) {
                if (a[i] % 2 == 0) {
                    alice += a[i];
                }
            }
            else {
                if (a[i] % 2) {
                    bob += a[i];
                }
            }
        }
        if (alice == bob) {
            cout << "Tie" << "\n";
        }
        else {
            cout << (alice > bob ? "Alice" : "Bob") << "\n";
        }
    }
    return 0;
}