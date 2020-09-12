#include <iostream>
using namespace std;

int freq_array[100001] = {};

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n, q, price, budget;
    cin >> n;
    for(int i = 0; i < n; i++){
        cin >> price;
        freq_array[price]++;
    }
    for(int i = 1; i < 100001; i++){
        freq_array[i] += freq_array[i - 1];
    }
    cin >> q;
    for(int i = 0; i < q; i++){
        cin >> budget;
        if(budget <= 100000)
            cout << freq_array[budget] << "\n";
        else
            cout << n << "\n";
    }
    return 0;
}