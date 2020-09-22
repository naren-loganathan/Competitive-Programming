#include <iostream>
#include <string>
using namespace std;

typedef long long int ll;
#define M 1000000007

int arr[26];

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    cin >> t;
    string s;
    while(t--){
        for(int i = 0; i < 26; i++){
            arr[i] = 0;
        }
        cin >> s;
        char a = s[0];
        if(s.length() == 1){
            arr[a - 97] = 1;
        }
        int length = 1;
        for(int i = 1; i < s.length(); i++){
            if(s[i] == a){
                length++;
                if(i == s.length() - 1 && length % 2){
                    arr[a - 97] = 1;
                }
            }
            else{
                if(length % 2 != 0){
                    arr[a - 97] = 1;
                }
                length = 1;
                a = s[i];
                if(i == s.length() - 1){
                    arr[a - 97] = 1;
                }
            }
        }
        for(int i = 0; i < 26; i++){
            if(arr[i]){
                char a = (97 + i);
                cout << a;
            }
        }
        cout << endl;
    }
    return 0;
}