#include <iostream>
#include <vector>
#include <map>
using namespace std;

typedef long long int ll;
#define M 1000000007
#define mp make_pair
#define ub upper_bound

int main(){
    ios_base::sync_with_stdio(false); 
    cin.tie(NULL);
    int q; cin >> q;
    while (q--) {
        bool possible = 1;
        int n, s; cin >> n;
        map <ll, int> numbers;
        for (int i = 0; i < n; i++) {
            cin >> s;
            if (numbers.find(s) == numbers.end()) {
                numbers.insert(mp(s, 1));
            }
            else {
                numbers[s]++;
            }
        }
        int i = 2048, j = 1;
        while (i > 0) {
            if (numbers.find(i) != numbers.end() && numbers[i] >= j) {
                break;
            }
            else {
                if (numbers.find(i) != numbers.end()) {
                    j = 2 * (j - numbers[i]);
                }
                else {
                    j *= 2;
                }
                i /= 2;
            }
        }
        if (i == 0) {
            possible = 0;
        }
        cout << (possible ? "YES\n" : "NO\n");
    }
    return 0;
}