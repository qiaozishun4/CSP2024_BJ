#include <bits/stdc++.h>
using namespace std;
bool s[4][14];
int main()
{
    freopen("poker.in","r",stdin);
    freopen("poker.out","w",stdout);
    int n;
    cin>>n;
    for(int i = 1;i <= n;i++)
    {
        char a,b;
        cin>>a>>b;
        int x,y;
        if(a == 'C') x = 0;
        else if(a == 'D') x = 1;
        else if(a == 'H') x = 2;
        else if(a == 'S') x = 3;
        if(b >= '2' && b <= '9') y = b - '0';
        else if(b == 'A') y = 1;
        else if(b == 'T') y = 10;
        else if(b == 'J') y = 11;
        else if(b == 'Q') y = 12;
        else if(b == 'K') y = 13;
        s[x][y] = 1;
    }
    int ans = 0;
    for(int i = 0;i <= 3;i++)
    {
        for(int j = 1;j <= 13;j++)
        {
            if(s[i][j] == 0) ans++;
        }
    }
    cout<<ans;
    return 0;
}
