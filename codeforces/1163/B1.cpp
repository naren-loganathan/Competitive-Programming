#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
             
typedef long long ll;
#define fi first
#define se second
#define mp make_pair

vector <int> cnt(10, 0);

bool streak () {
    vector <int> a;
    for (int i = 0; i < 10; i++) {
        if (cnt[i]) {
            a.push_back(cnt[i]);
        }
    }
    int n = a.size();
    sort(a.begin(), a.end());
    if (n > 1) {
        if (a[0] == a[n - 2] && a[0] == a[n - 1] - 1) {
            return 1;
        }
        else if (a[1] == a[n - 1] && a[0] == 1) {
            return 1;
        }
        else {
            return 0;
        }
    } 
    else {
        return 1;
    }
    return 0;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int n; cin >> n;
    vector <int> u(n);
    for (int i = 0; i < n; i++) {
        cin >> u[i];
        cnt[u[i] - 1]++;
    }
    int x = n;
    while (!streak()) {
        cnt[u[x - 1] - 1]--; x--;
    }
    cout << x << "\n";
    return 0;
}
