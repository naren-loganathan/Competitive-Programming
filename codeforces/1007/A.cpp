#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
using namespace std;
             
typedef long long ll;
#define fi first
#define se second
#define mp make_pair

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int n, cnt = 0, itr = 0; cin >> n;
    vector <int> a(n);
    deque <int> store;
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    sort(a.begin(), a.end());
    for (int i = n - 1; i > 0; i--) {
        if (a[i] > a[i - 1]) {
            cnt++;
        }
        else {
            store.push_back(a[i]);
            if (!store.empty() && store.front() > a[i - 1]) {
                store.pop_front(); cnt++;
            }
        }
    }
    cout << cnt << "\n";
    return 0;
}
