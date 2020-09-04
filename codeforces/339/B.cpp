#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n, m, current_house = 1;
    long long int time = 0;
    cin >> n >> m;
    vector <int> tasks;
    tasks.reserve(m);
    for(int i = 0; i < m; i++){
        cin >> tasks[i];
        if(tasks[i] >= current_house)
            time += (tasks[i] - current_house);
        else
            time += (n + tasks[i] - current_house);
        current_house = tasks[i];
    }
    cout << time << endl;
    return 0;
}