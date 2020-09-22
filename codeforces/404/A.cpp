#include <iostream>
#include <string>
using namespace std;

typedef long long int ll;
#define M 1000000007

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n, left, right;  
    string s; 
    bool is_it_x = 1;
    cin >> n;
    cin >> s;
    char a = s[0], b = s[1];
    if(a != b && s[n - 1] == a){
        for(int i = 1; i < n - 1; i++){
            if(s[i] != b){
                is_it_x = 0;
            }
        }
    }
    else{
        is_it_x = 0;
    }
    left = 1;
    right = n - 2;
    for(int i = 1; i < n; i++){
        cin >> s;
        for(int j = 0; j < n; j++){
            if(j == left || j == right){
                if(s[j] != a){
                    is_it_x = 0;
                }
            }
            else{
                if(s[j] != b){
                    is_it_x = 0;
                }
            }
        }
        left++;
        right--;
    }
    if(is_it_x){
        cout << "YES" << endl;
    }
    else{
        cout << "NO" << endl;
    }
    return 0;
}