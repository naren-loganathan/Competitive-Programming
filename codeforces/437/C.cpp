#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

typedef long long int ll;
#define M 1000000007
#define mp make_pair
#define ub upper_bound

int main(){
    ios_base::sync_with_stdio(false); 
    cin.tie(NULL);
    ll n, m, x, y, min_energy = 0; 
    cin >> n >> m;
    vector <ll> energies(n + 1);
    for (int i = 1; i <= n; i++) {
        cin >> energies[i];
    }
    for (int i = 0; i < m; i++) {
        cin >> x >> y;
        min_energy += min(energies[x], energies[y]);
    }
    cout << min_energy << "\n";
    return 0;
}