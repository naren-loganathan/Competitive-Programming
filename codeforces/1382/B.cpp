#include <iostream>
#include <vector>
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
        bool first_wins = 0, greater_than_one = 0;
        int n; cin >> n;
        vector <int> a(n);
        for (int i = 0; i < n; i++) {
            cin >> a[i];
            if (a[i] > 1) {
                greater_than_one = 1;
            }
        }
        if (greater_than_one) {
            int i = 0;
            while (a[i] == 1) {
                i++;
            }
            if (i % 2 == 0) {
                first_wins = 1;
            }
        }
        else {
            if (n % 2 == 1) {
                first_wins = 1;
            }
        }
        cout << (first_wins ? "First\n" : "Second\n");
    }
    return 0;
}