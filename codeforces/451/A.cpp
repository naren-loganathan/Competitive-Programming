#include <iostream>
#include <cmath>
using namespace std;

#define ll long long int

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n, m;
    cin >> n >> m;
    if(min(n, m) % 2 != 0)
        cout << "Akshat" << endl;
    else
        cout << "Malvika" << endl;
    return 0;
}