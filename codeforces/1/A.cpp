#include <iostream>
#include <cmath>
using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    double n, m, a;
    cin >> n >> m >> a;
    long long int num_flagstones = ceil(n / a) * ceil(m / a);
    cout << num_flagstones << endl;
    return 0;
}