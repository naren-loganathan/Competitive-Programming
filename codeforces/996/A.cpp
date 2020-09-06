#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int denominations[5] = {1, 5, 10, 20, 100};
    int n, min_bills = 0;
    cin >> n;
    for(int i = 4; i >= 0; i--){
        min_bills += (n / denominations[i]);
        n %= denominations[i];
    }
    cout << min_bills << endl;
    return 0;
}