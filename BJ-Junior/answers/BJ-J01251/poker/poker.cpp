#include<bits/stdc++.h>
using namespace std;
int p[10][20];
int main()
{
    freopen("poker.in","r",stdin);
    freopen("poker.out","w",stdout);
    int n,ans=52;
    char x,y;
    scanf("%d",&n);
    for(int i=1;i<=n;i++)
    {
        cin>>x>>y;
        if(x=='D')
            x=1;
        if(x=='C')
            x=2;
        if(x=='H')
            x=3;
        if(x=='S')
            x=4;
//      printf("%d\n",x);
        if(y=='A')
            y=1;
        else
        {
            if(y=='T')
                y=10;
            else
            {
                if(y=='J')
                    y=11;
                else
                {
                    if(y=='Q')
                        y=12;
                    else
                    {
                        if(y=='K')
                            y=13;
                        else
                            y-='0';
                    }
                }
            }
        }
        p[x][y]=1;
//      printf("%d %d %d\n",x,y,p[x][y]);
    }
    for(int i=1;i<=4;i++)
    {
        for(int j=1;j<=13;j++)
        {
            if(p[i][j])
                ans--;
        }
    }
    printf("%d",ans);
    return 0;
}