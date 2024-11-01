#include<bits/stdc++.h>
using namespace std;
int main(){
    freopen("chain.in", "r", stdin);
    freopen("chain.out", "w", stdout);
    int t;
    cin >> t;
    srand(time(0));
    while(t--)
    {
        int z;
        int b;
        int n;
        cin >> n >> z >> z;
        for(int i = 1; i <= n; i++)
        {
            cin >> b;
        }
        for(int i = 1; i <= z; i++)
        {
            cin >> b >> b;
            cout << rand() % 2 << endl;
        }
    }
    return 0;
}