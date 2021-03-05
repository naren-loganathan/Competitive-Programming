#include <iostream>
#include <vector>
#include <map>
using namespace std;
             
typedef long long ll;
#define fi first
#define se second
#define mp make_pair

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    ll n; cin >> n;
    vector <ll> p(n);
    map <ll, int> idx; 
    for (int i = 0; i < n; i++) {
        cin >> p[i];
        if (i) p[i] += p[i - 1];
        idx[p[i]] = -1;
    }
    int cnt = 0, ins = -1;
    for (int i = 0; i < n; i++) {
        if (idx[p[i]] != -1) {
            if (ins <= idx[p[i]]) {
                ins = i - 1; cnt += 1;
            }
        }
        else {
            if (p[i] == 0 && ins == -1) {
                ins = i - 1; cnt += 1;
            }
        }
        idx[p[i]] = i;
    }
    cout << cnt << '\n';
    return 0;
}