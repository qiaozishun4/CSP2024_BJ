#include<bits/stdc++.h>
using namespace std;
int n,w,ans;
char c,x;
int a[6][16];
int main()
{
    freopen("poker.in","r",stdin);
    freopen("poker.out","W",stdout);
    cin>>n;
    for(int i=1;i<=n;i++)
    {
        cin>>c>>x;
        if(x=='A')
        {
            w=1;
        }
        if(x=='2')
        {
            w=2;
        }
        if(x=='3')
        {
            w=3;
        }
        if(x=='4')
        {
            w=4;
        }
        if(x=='5')
        {
            w=5;
        }
        if(x=='6')
        {
            w=6;
        }
        if(x=='7')
        {
            w=7;
        }
        if(x=='8')
        {
            w=8;
        }
        if(x=='9')
        {
            w=9;
        }
        if(x=='T')
        {
            w=10;
        }
        if(x=='J')
        {
            w=11;
        }
        if(x=='Q')
        {
            w=12;
        }
        if(x=='K')
        {
            w=13;
        }
        if(c=='D')
        {
            a[1][w]=1;
        }
        if(c=='C')
        {
            a[2][w]=1;
        }
        if(c=='H')
        {
            a[3][w]=1;
        }
        if(c=='S')
        {
            a[4][w]=1;
        }
    }
    for(int i=1;i<=4;i++)
    {
        for(int j=1;j<=13;j++)
        {
            if(a[i][j]==0)
            {
                ans++;
            }
        }
    }
    cout<<ans;
    return 0;
}
