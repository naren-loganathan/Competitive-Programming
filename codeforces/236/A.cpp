#include <iostream>
#include <string>
using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int arr[26] = {}, count = 0;
    bool is_it_a_she = 0;
    string s;
    cin >> s;
    for(int i = 0; i < s.length(); i++)
        arr[s[i] - 97]++;
    for(int i = 0; i < 26; i++)
        if(arr[i]) count++;
    if(count % 2 == 0)
        is_it_a_she = 1;
    if(is_it_a_she) 
        cout << "CHAT WITH HER!" << endl;
    else 
        cout << "IGNORE HIM!" << endl;
    return 0;
}