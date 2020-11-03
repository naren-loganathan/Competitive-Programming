#include <iostream>
#include <vector>
#include <string>
using namespace std;

typedef long long int ll;
#define fi first
#define se second
#define mp make_pair

int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n, min_cost = 0; 
    cin >> n;
    string a, b; cin >> a >> b;
    vector <int> v;
    for (int i = 0; i < n; i++) {
        if (a[i] != b[i]) {
            v.push_back(i);
        }
    }
    if (v.size() == 1) {
        min_cost = 1;
    }
    else {
        for (int i = 0; i < v.size(); i++) {
            if (i < v.size() - 1) {
                if (v[i] == v[i + 1] - 1 && a[v[i]] != a[v[i + 1]]) {
                    i++;
                }
            }
            min_cost++;
        }
    }
    cout << min_cost << "\n";
    return 0;
}