#include <iostream>
#include <set>
using namespace std;
             
typedef long long ll;
#define fi first
#define se second
#define mp make_pair

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int s;
    set <int> h;
    for (int i = 0; i < 4; i++) {
        cin >> s;
        h.insert(s);
    }
    cout << 4 - h.size() << "\n";
    return 0;
}

//lazy ik