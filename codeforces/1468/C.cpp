#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>
#include <queue>
using namespace std;
     
typedef long long ll;
#define fi first
#define se second
#define mp make_pair

bool cmp (pair <int, int> &a, pair <int, int> &b) {
    if (a.fi > b.fi) {
        return 1;
    }
    else if (a.fi == b.fi) {
        return (a.se > b.se ? 0 : 1);
    }
    else {
        return 0;
    }
}
     
int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int j = 0, k = 1;
    vector < pair <int, int> > customers;
    priority_queue < pair <int, int> > polycarp;
    vector <int> res;
    int q; cin >> q;
    vector <bool> served(q + 1, 0);
    for (int i = 1; i <= q; i++) {
        int type, m;
        cin >> type;
        if (type == 1) {
            cin >> m;
            customers.push_back(mp(m, k));
            polycarp.push(mp(m, q - k));
            k++;
        }
        else if (type == 2) {
            while (served[customers[j].se] == 1) {
                j++;
            }
            //cout << customers[j].se << "\n";
            served[customers[j].se] = 1;
            res.push_back(customers[j].se);
            j++;
        }
        else {
            while (served[q - polycarp.top().se] == 1) {
                polycarp.pop();
            }
            //cout << polycarp.top().se << "\n";
            res.push_back(q - polycarp.top().se);
            served[q - polycarp.top().se] = 1;
            polycarp.pop();
        }
    }
    for (int i = 0; i < res.size(); i++) {
        cout << res[i] << " ";
    }
    cout << "\n";
    return 0;
}