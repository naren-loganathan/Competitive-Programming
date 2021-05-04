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
    int n, k, x; cin >> n >> k >> x;
    vector <int> cnt(1024);
    for (int i = 0; i < n; i++) {
        int a; cin >> a; 
        cnt[a] += 1;
    }
    for (int j = 1; j <= k; j++) {
        vector <int> new_cnt(1024);
        int prev = 0;
        for (int i = 0; i < 1024; i++) {
            if (prev % 2) {
                new_cnt[i] += (cnt[i] + 1) / 2;
                new_cnt[i ^ x] += cnt[i] / 2;
            } else {
                new_cnt[i] += cnt[i] / 2;
                new_cnt[i ^ x] += (cnt[i] + 1) / 2;
            }
            prev += cnt[i];
        }
        cnt = new_cnt;
    }
    int mn = 0, mx = 1023;
    while (!cnt[mn]) mn++;
    while (!cnt[mx]) mx--;
    cout << mx << ' ' << mn << '\n';
    return 0;
}