#include <iostream>
#include <vector>
#include <set>
using namespace std;

typedef long long ll;
#define fi first
#define se second
#define mp make_pair

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int n, m; cin >> n >> m;
    vector <int> p;
    p.push_back(1);
    for (int x = m; x < n; x *= m) {
        p.push_back(x);
    }
    int len = p.size();
    set <int> s;
    while (!p.empty()) {
        s.insert(n / p.back());
        n %= p.back();
        p.pop_back();
    }
    cout << (len == s.size() ? "YES" : "NO") << '\n';
    return 0;
}