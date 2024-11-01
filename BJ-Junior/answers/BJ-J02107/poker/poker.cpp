#include<bits/stdc++.h>
using namespace std;
int cnt[10][30];
int main()
{
    freopen("poker.in","r",stdin);
    freopen("poker.out","w",stdout);
    int n;
    scanf("%d\n",&n);
    for(int i=1;i<=n;i++)
    {
        char c1,c2;
        scanf("%c%c\n",&c1,&c2);
        if(c1=='D')
        {
            if(c2=='A')
            {
                cnt[1][1]=1;
            }
            else if(c2>='2'&&c2<='9')
            {
                cnt[1][c2-'0']=1;
            }
            else if(c2=='T')
            {
                cnt[1][10]=1;
            }
            else if(c2=='J')
            {
                cnt[1][11]=1;
            }
            else if(c2=='Q')
            {
                cnt[1][12]=1;
            }
            else
            {
                cnt[1][13]=1;
            }
        }
        else if(c1=='C')
        {
            if(c2=='A')
            {
                cnt[2][1]=1;
            }
            else if(c2>='2'&&c2<='9')
            {
                cnt[2][c2-'0']=1;
            }
            else if(c2=='T')
            {
                cnt[2][10]=1;
            }
            else if(c2=='J')
            {
                cnt[2][11]=1;
            }
            else if(c2=='Q')
            {
                cnt[2][12]=1;
            }
            else
            {
                cnt[2][13]=1;
            }
        }
        else if(c1=='H')
        {
            if(c2=='A')
            {
                cnt[3][1]=1;
            }
            else if(c2>='2'&&c2<='9')
            {
                cnt[3][c2-'0']=1;
            }
            else if(c2=='T')
            {
                cnt[3][10]=1;
            }
            else if(c2=='J')
            {
                cnt[3][11]=1;
            }
            else if(c2=='Q')
            {
                cnt[3][12]=1;
            }
            else
            {
                cnt[3][13]=1;
            }
        }
        else
        {
            if(c2=='A')
            {
                cnt[4][1]=1;
            }
            else if(c2>='2'&&c2<='9')
            {
                cnt[4][c2-'0']=1;
            }
            else if(c2=='T')
            {
                cnt[4][10]=1;
            }
            else if(c2=='J')
            {
                cnt[4][11]=1;
            }
            else if(c2=='Q')
            {
                cnt[4][12]=1;
            }
            else
            {
                cnt[4][13]=1;
            }
        }
    }
    int ans=0;
    for(int i=1;i<=4;i++)
    {
        for(int j=1;j<=13;j++)
        {
            if(cnt[i][j]==0)
            {
                ans++;
            }
        }
    }
    printf("%d",ans);
    return 0;
}
