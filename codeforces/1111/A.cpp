#include <iostream>
#include <string>
using namespace std;

typedef long long int ll;
#define M 1000000007
#define pb push_back

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    string s, t;
    cin >> s >> t;
    bool transform = 1;
    if(s.length() != t.length()){
        transform = 0;
    }
    else{
        for(int i = 0; i < s.length(); i++){
            bool vowel_s = 0, vowel_t = 0;
            switch(s[i]){
                case 'a':
                case 'e':
                case 'i':
                case 'o':
                case 'u':
                    vowel_s = 1;
                    break;
            }
            switch(t[i]){
                case 'a':
                case 'e':
                case 'i':
                case 'o':
                case 'u':
                    vowel_t = 1;
                    break;
            }
            if(vowel_s ^ vowel_t){
                transform = 0;
                break;
            }
        }
    }
    cout << (transform ? "Yes\n" : "No\n");
    return 0;
}