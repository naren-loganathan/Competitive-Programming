#include <iostream>
#include <string>
using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    cin >> t;
    while(t--){
        int n, arr[100] = {};
        cin >> n;
        for(int i = 0; i < n; i++)
            cin >> arr[i];
        string s = "aaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa";
        cout << s << "\n";
        for(int i = 0; i < n; i++){
            if(s[arr[i]] == 'a')
                s[arr[i]] = 'b';
            else
                s[arr[i]] = 'a';
            cout << s << "\n";
        }   
    }
    return 0;
}