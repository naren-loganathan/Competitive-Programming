#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

typedef long long int ll;
#define M 1000000007
#define mp make_pair
#define ub upper_bound

int lowbit (int x) {
    return (x & (-x));
}

int main(){
    ios_base::sync_with_stdio(false); 
    cin.tie(NULL);
    int sum, limit, try_sum;
    cin >> sum >> limit;
    vector <int> ans;
    for (int i = limit; i > 0; i--) {
        if (lowbit(i) <= sum) {
            sum -= lowbit(i);
            ans.push_back(i);
        }
        if (sum == 0) {
            break;
        }
    }
    if (sum) {
        cout << "-1\n";
    }
    else {
        cout << ans.size() << "\n";
        for (int i = 0; i < ans.size(); i++){
            cout << ans[i] << " ";
        }
        cout << "\n";
    }
    return 0;
}