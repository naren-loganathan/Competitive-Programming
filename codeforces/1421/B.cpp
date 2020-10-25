#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <cmath>
using namespace std;

typedef long long int ll;
typedef long double ld;
#define mod 1000000007
#define N 200005
#define mp make_pair
#define ub upper_bound
#define lb lower_bound
#define fi first
#define se second

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t = 1; 
    cin >> t;
    while (t--) {
        int n; cin >> n;
        vector <string> grid(n);
        vector < pair <int, int> > inversions;
        for (int i = 0; i < n; i++) {
            cin >> grid[i];
        }
        if (grid[0][1] == grid[1][0]) {
            if (grid[n - 2][n - 1] == grid[n - 1][n - 2]) {
                if (grid[n - 2][n - 1] == grid[0][1]) {
                    inversions.push_back(mp(1, 2));
                    inversions.push_back(mp(2, 1));
                }
            }
            else {
                if (grid[n - 2][n - 1] == grid[0][1]) {
                    inversions.push_back(mp(n - 1, n));
                }
                else {
                    inversions.push_back(mp(n, n - 1));
                }
            }
        }
        else {
            if (grid[n - 2][n - 1] == grid[n - 1][n - 2]) {
                if (grid[n - 2][n - 1] == grid[0][1]) {
                    inversions.push_back(mp(1, 2));
                }
                else {
                    inversions.push_back(mp(2, 1));
                }
            }
            else {
                inversions.push_back(mp(n - 1, n));
                if (grid[n - 1][n - 2] == grid[0][1]) {
                    inversions.push_back(mp(1, 2));
                }
                else {
                    inversions.push_back(mp(2, 1));
                }
            }
        }
        cout << inversions.size() << "\n";
        for (int i = 0; i < inversions.size(); i++) {
            cout << inversions[i].fi << " " << inversions[i].se << "\n";
        }
    }
    return 0;
}