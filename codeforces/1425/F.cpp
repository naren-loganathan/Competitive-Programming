#include <iostream>
#include <vector>
using namespace std;

typedef long long int ll;
#define M 1000000007
#define pb push_back

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n, l, r; cin >> n;
    vector <int> prefix_sum_array(n + 1);
    prefix_sum_array[0] = 0;
    for (int i = n; i > 1; i--) {
        cout << "? 1 " << i << endl;
        cin >> prefix_sum_array[i];
    }
    cout << "? 2 " << n << endl;
    cin >> prefix_sum_array[1];
    prefix_sum_array[1] = prefix_sum_array[n] - prefix_sum_array[1];
    cout << "! ";
    for (int i = 1; i <= n; i++) {
        cout << prefix_sum_array[i] - prefix_sum_array[i - 1] << " ";
    }
    cout << endl;
    return 0;
}