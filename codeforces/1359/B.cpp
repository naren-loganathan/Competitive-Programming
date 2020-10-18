#include <iostream>
#include <vector>
#include <string>
#include <cmath>
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
        int n, m, x, y, min_price = 0;
        cin >> n >> m >> x >> y;
        vector <string> square(n);
        for (int i = 0; i < n; i++) {
            cin >> square[i];
            for (int j = 0; j < m; j++) {
                if (square[i][j] == '.') {
                    if (j < m - 1 && square[i][j + 1] == '.') {
                        min_price += min(2 * x, y);
                        j++;
                    }
                    else {
                        min_price += x;
                    }
                }
            }
        }
        cout << min_price << "\n";
    }
    return 0;
}