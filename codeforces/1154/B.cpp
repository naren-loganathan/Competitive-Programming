#include <iostream>
#include <vector>
#include <set>
#include <algorithm>
using namespace std;

typedef long long int ll;

int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n, a; 
    cin >> n;
    set <int> num;
    vector <int> nomnom;
    for (int i = 0; i < n; i++) {
        cin >> a;
        if (num.find(a) == num.end()) {
            num.insert(a);
            nomnom.push_back(a);
        }
    }
    sort(nomnom.begin(), nomnom.end());
    if (nomnom.size() > 3) {
        cout << "-1" << "\n";
    }
    else if (nomnom.size() == 3) {
        if (nomnom[2] - nomnom[1] == nomnom[1] - nomnom[0]) {
            cout << nomnom[2] - nomnom[1] << "\n";
        }
        else {
            cout << "-1" << "\n";
        }
    }
    else if (nomnom.size() == 2) {
        if ((nomnom[1] - nomnom[0]) % 2) {
            cout << (nomnom[1] - nomnom[0]) << "\n";
        }
        else {
            cout << (nomnom[1] - nomnom[0]) / 2 << "\n";
        }
    }
    else {
        cout << "0" << "\n";    
    }
    return 0;
}