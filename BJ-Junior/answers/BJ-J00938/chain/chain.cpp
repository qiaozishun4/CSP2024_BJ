#include<bits/stdc++.h>
using namespace std;
int main(){
    freopen("chain.in", "r", stdin);
    freopen("chain.out", "w", stdout);
    srand(time(0));
    int a, b, c, d;
    cin >> a >> b >> c >> d;
    for(int i = 1; i <= d; i++)
        cout << (rand() % 2) << endl;
    return 0;
}
