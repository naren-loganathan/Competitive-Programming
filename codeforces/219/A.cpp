#include <iostream>
#include <string>
using namespace std;

#define ll long long int

int arr[26] = {};

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int k;
    string s;
    bool possible = 1;
    cin >> k >> s;
    if(s.length() % k != 0)
        possible = 0;
    for(int i = 0; i < s.length(); i++)
        arr[s[i] - 97]++;
    for(int i = 0; i < 26; i++){
        if(arr[i] % k != 0){
            possible = 0;
            break;
        }
    }
    if(possible){
        string monomer;
        string c;
        for(int i = 0; i < 26; i++){
            c = (char) 97 + i;
            for(int j = 0; j < arr[i] / k; j++)
                monomer += c;
        }
        for(int i = 0; i < k; i++)
            cout << monomer;
    }
    else
        cout << "-1";
    cout << endl;
    return 0;
}