#include <bits/stdc++.h>
using namespace std;

bool f[9][18];

int main()
{
    freopen("poker.in","r",stdin);
    freopen("poker.out","w",stdout);
    int n;
    cin >> n;
    for(int i = 1;i <= n;i++)
    {
        string s;
        cin >> s;
        char x = s[0],y=s[1];
        int x1 = 0,x2 = 0;
        if(x=='D')
            x1=1;
        else if(x=='C')
            x1=2;
        else if(x=='H')
            x1=3;
        else
            x1=4;
        if(y>='2'&&y<=9)
            x2=y-'0';
        else if(y=='A')
            x2=1;
        else if(y=='T')
            x2=10;
        else if(y=='J')
            x2=11;
        else if(y=='Q')
            x2=12;
        else
            x2=13;
        f[x1][x2]=1;
    }
    int cnt = 0;
    for(int i = 1;i <= 4;i++)
    {
        for(int j = 1;j <= 13;j++)
        {
            if(f[i][j])
            {
                cnt++;
            }
        }
    }
    cout << 52-cnt;
    return 0;
}