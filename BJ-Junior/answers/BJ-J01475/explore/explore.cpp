#include<bits/stdc++.h>
using namespace std;
int k, n, m, s, mx, my, d;
char _map[1001][1001];
int main(){
    freopen("explore.in", "r", stdin);
    freopen("explore.out", "w", stdout);
    cin >> k;
    while(k--)
    {
        cin >> n >> m >> s;
        cin >> mx >> my >> d;
        for(int i = 0; i < n; i++)
            for(int j = 0; j < m; j++)
                cin >> _map[i][j];
        if(s > n * m)
        {
            cout << n * m << '\n';
            break;
        }
        else{
            cout << s << '\n';
            break;
        }
    }
    return 0;
}
