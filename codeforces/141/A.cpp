#include <iostream>
#include <string>
using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    bool permutable = 1;
    int zero_count = 0, ones_count = 0;
    string guest, host, pile;
    cin >> guest >> host >> pile;
    int arr[26] = {};
    for(int i = 0; i < guest.length(); i++)
        arr[guest[i] - 65]++;
    for(int i = 0; i < host.length(); i++)
        arr[host[i] - 65]++;
    for(int i = 0; i < pile.length(); i++)
        arr[pile[i] - 65]--;
    for(int i = 0; i < 26; i++){
        if(arr[i] != 0){
            permutable = 0;
            break;
        }
    }
    if(permutable)
        cout << "YES" << endl;
    else
        cout << "NO" << endl;
    return 0;
}