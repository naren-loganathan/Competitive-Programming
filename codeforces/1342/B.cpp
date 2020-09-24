#include <iostream>
#include <string>
using namespace std;

typedef long long int ll;
#define M 1000000007
#define pb push_back

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    string s;
    cin >> t;
    while(t--){
        int count_1 = 0, count_0 = 0;
        cin >> s;
        for(int i = 0; i < s.length(); i++){
            if(s[i] == '1'){
                count_1++;
            }else{
                count_0++;
            }
        }
        if(!(count_1 == s.length()) && !(count_0 == s.length())){
            for(int i = 0; i < s.length() - 1; i++){
                if(s[i] == s[i + 1]){
                    if(s[i] == '0'){
                        s.insert(i + 1, "1");
                    }else{
                        s.insert(i + 1, "0");
                    }
                    i++;
                }
            }
        }
        cout << s << "\n";
    }
    return 0;
}