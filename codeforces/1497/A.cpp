#include <iostream>
#include <set>
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
        set <int> a;
        multiset <int> m;
        for (int i = 0; i < n; i++) {
            int num; cin >> num;
            a.insert(num);
            m.insert(num);
        }
        while (!a.empty()) {
            int p = *(a.begin());
            cout << p << ' ';
            a.erase(p);
            m.erase(m.find(p));
        }
        while (!m.empty()) {
            int p = *(m.begin());
            cout << p << ' ';
            m.erase(m.find(p));
        }
        cout << '\n';
    }
    return 0;
}