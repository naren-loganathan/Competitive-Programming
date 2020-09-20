#include <iostream>
#include <string>
using namespace std;

#define ll long long int

int winner(string s){
    int a;
    if(s.length() % 2 != 0){
        for(int i = 0; i < s.length(); i += 2){
            if((s[i] - 48) % 2 != 0){
                return 1;
            }
        }
        return 2;
    }
    else{
        for(int i = 1; i < s.length(); i += 2){
            if((s[i] - 48) % 2 == 0){
                return 2;
            }
        }
        return 1;
    }
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t, n;
    string s;
    cin >> t;
    while(t--){
        cin >> n;
        cin >> s;
        cout << winner(s) << "\n";
    }
    return 0;
}