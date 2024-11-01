#include<bits/stdc++.h>
using namespace std;
int T;
int main(){
    freopen("color.in", "r", stdin);
    freopen("color.out", "w", stdout);
    srand(0);
    cin >> T;
    for(int i = 1; i <= T; i++){
        cout << rand()%9 << endl;
    }
    return 0;
}