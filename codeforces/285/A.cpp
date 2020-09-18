#include <iostream>
#include <string>
using namespace std;

#define ll long long int

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    string s;
    int n, k;
    cin >> n >> k;
    for(int i = k + 1; i <= n; i++)
        cout << i << " ";
    for(int i = k; i > 0; i--)
        cout << i << " ";
    cout << endl;
    return 0;
}