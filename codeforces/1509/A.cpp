#include <iostream>
#include <vector>
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
        vector <int> even, odd;
        for (int i = 0; i < n; i++) {
            int a; cin >> a;
            if (a % 2) {
                odd.push_back(a);
            } else {
                even.push_back(a);
            }
        }
        for (int i = 0; i < odd.size(); i++) {
            cout << odd[i] << ' ';
        }
        for (int i = 0; i < even.size(); i++) {
            cout << even[i] << ' ';
        }
        cout << '\n';
    }
    return 0;
}