#include <iostream>
#include <string>
using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n, num_remove = 0;
    cin >> n;
    string s;
    cin >> s;
    for(int i = 0; i < n - 1; i++){
        if(s[i] == s[i + 1])
            num_remove++;
    }
    cout << num_remove << endl;
    return 0;
}