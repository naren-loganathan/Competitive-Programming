#include <iostream>
#include <vector>
using namespace std;

typedef long long int ll;
#define M 1000000007
#define pb push_back

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    ll n, energy = 0, min_money = 0; 
    cin >> n;
    vector <ll> heights(n + 1);
    heights[0] = 0;
    for (int i = 1; i <= n; i++) {
        cin >> heights[i];
        energy += heights[i - 1] - heights[i];
        if (energy < 0) {
            heights[i - 1] += energy * (-1);
            min_money += energy * (-1);
            energy = 0;
        }
    }
    cout << min_money << "\n";
    return 0;
}