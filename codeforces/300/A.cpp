#include <iostream>
#include <vector>
using namespace std;

typedef long long int ll;
typedef long double ld;

int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n, a; cin >> n;
    vector < vector <int> > sets(3);
    for (int i = 0; i < n; i++) {
        cin >> a;
        if (a > 0) {
            sets[1].push_back(a);
        }
        else if (a < 0) {
            sets[0].push_back(a);
        }
        else {
            sets[2].push_back(a);
        }
    }
    if (sets[1].size() == 0) {
        sets[1].push_back(sets[0].back());
        sets[0].pop_back();
        sets[1].push_back(sets[0].back());
        sets[0].pop_back();
    }
    if (sets[0].size() % 2 == 0) {
        sets[2].push_back(sets[0].back());
        sets[0].pop_back();
    }
    for (int i = 0; i < 3; i++) {
        cout << sets[i].size() << " ";
        for (int j = 0; j < sets[i].size(); j++) {
            cout << sets[i][j] << " ";
        }
        cout << "\n";  
    }
    return 0;
}