#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

typedef long long int ll;
#define M 1000000007
#define mp make_pair
#define ub upper_bound

int main(){
    ios_base::sync_with_stdio(false); 
    cin.tie(NULL);
    int t; cin >> t;
    while (t--) {
        int n; cin >> n;
        vector <int> e(n);
        vector <bool> going(n, 0);
        for (int i = 0; i < n; i++) {
            cin >> e[i];
        }
        sort(e.begin(), e.end());
        int groups = 0;
        for (int i = 0; i < n; i++) {
            int j = i - 1;
            int count = 1;
            while (j > -1) {
                if (going[j] == 1 || count == e[i]) {
                    break;
                }
                else {
                    count++;
                    j--;
                }
            }
            if (count == e[i]) {
                j++;
                while (j <= i) {
                    going[j] = 1;
                    j++;
                }
                groups++;
            }
        }
        cout << groups << "\n";
    }
    return 0;
}