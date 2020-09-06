#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int a, n, your_money = 0, twins_money = 0;
    vector <int> coins;
    cin >> n;
    for(int i = 0; i < n; i++){
        cin >> a;
        coins.push_back(a);
        twins_money += a;
    }
    int i = coins.size() - 1;
    sort(coins.begin(), coins.end());
    while(your_money <= twins_money){
        twins_money -= coins[i];
        your_money += coins[i];
        i--;
    }
    cout << coins.size() - i - 1 << endl;
    return 0;
}