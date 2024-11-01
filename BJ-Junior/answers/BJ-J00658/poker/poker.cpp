#include <bits/stdc++.h>
using namespace std;
int n, vis[10][20], ans = 52;
int main()
{
    freopen("poker.in", "r", stdin);
    freopen("poker.out", "w", stdout);
    cin >> n;
    for(int i = 1; i <= n; i++)
    {
        int x, y;
        char type, num;
        cin >> type >> num;
        if(type == 'D') x = 1;
        else if(type == 'C') x = 2;
        else if(type == 'H') x = 3;
        else x = 4;
        if(num == 'T') y = 10;
        else if(num == 'J') y = 11;
        else if(num == 'Q') y = 12;
        else if(num == 'K') y = 13;
        else if(num == 'A') y = 1;
        else y = num - 48;
        if(!vis[x][y]) ans--;
        vis[x][y] = 1;
    }
    cout << ans;
    fclose(stdin);
    fclose(stdout);
    return 0;
}