#include <bits/stdc++.h>
using namespace std;
bool flag[5][14] = {};
int main()
{
    freopen("poker.in","r",stdin);
    freopen("poker.out","w",stdout);
    int n;
    cin>>n;
    char a,b;
    int x,y;
    for(int i = 1;i <= n;i++) {
        cin>>a>>b;
        if(a == 'D')
           x = 1;
        if(a == 'C')
           x = 2;
        if(a == 'H')
           x = 3;
        if(a == 'S')
           x = 4;
        if(b == 'T')
            y = 10;
        else if(b == 'J')
            y = 11;
        else if(b == 'Q')
            y = 12;
        else if(b == 'K')
            y = 13;
        else if(b == 'A')
            y = 1;
        else y = int(b-'0');
        flag[x][y] = 1;
    }
    int cnt = 0;
    for(int i = 1;i <= 4;i++) {
        for(int j = 1;j <= 13;j++) {
            if(flag[i][j] == 0) cnt++;
        }
    }
    cout << cnt;
    return 0;
}