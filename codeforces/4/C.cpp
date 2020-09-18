#include <iostream>
#include <string>
#include <map>
using namespace std;

#define ll long long int

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n;
    string s;
    map <string, int> database;
    cin >> n;
    for(int i = 0; i < n; i++){
        cin >> s;
        if(database[s] == 0)
            cout << "OK\n";
        else
            cout << s << database[s] << "\n";
        database[s]++;
    }
    return 0;
}