#include <iostream>
#include <vector>
#include <string>
using namespace std;

typedef long long int ll;
#define fi first
#define se second
#define mp make_pair

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int n, groups = 1; 
    cin >> n;
    vector <string> magnets(n);
    for (int i = 0; i < n; i++) {
        cin >> magnets[i];
    }
    for (int i = 1; i < n; i++) {
        if (magnets[i] != magnets[i - 1]) {
            groups++;
        }
    }
    cout << groups << "\n";
    return 0;
}