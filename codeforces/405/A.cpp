#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n, a;
    vector <int> columns;
    cin >> n;
    for(int i = 0; i < n; i++){
        cin >> a;
        columns.push_back(a);
    }
    sort(columns.begin(), columns.end());
    for(int i = 0; i < n; i++){
        cout << columns[i] << " ";
    }
    cout << endl;
    return 0;
}