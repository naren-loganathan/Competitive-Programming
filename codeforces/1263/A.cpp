#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
using namespace std;

typedef long long int ll;
#define fi first
#define se second

int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t; cin >> t;
    while (t--) {
        vector <int> qts(3); 
        int m = 0; 
        cin >> qts[0] >> qts[1] >> qts[2];
        sort(qts.begin(), qts.end());
        m += qts[0];
        if (qts[2] - qts[1] < m) {
            qts[0] -= (qts[2] - qts[1]);
            qts[2] = qts[1];
            qts[1] -= (qts[0] / 2);
            qts[2] -= (qts[0] - qts[0] / 2);
        }
        else {
            qts[2] -= m;
        }
        m += min(qts[1], qts[2]);
        cout << m << "\n";
    }
    return 0;
}