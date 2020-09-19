#include <iostream>
#include <string>
using namespace std;

#define ll long long int

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    string s;
    cin >> s;
    cout << s;
    for(int i = s.length() - 1; i > -1; i--)
        cout << s[i];
    cout << "\n";
    return 0;
}