#include<bits/stdc++.h>
using namespace std;
int n,ans;
bool a[5][20];
char s[10],b;
int pd1()
{
    b=s[0];
    if(b=='D')
        return 1;
    if(b=='C')
        return 2;
    if(b=='H')
        return 3;
    if(b=='S')
        return 4;
}
int pd2()
{
    b=s[1];
    if(b=='A')
        return 1;
    if(b=='T')
        return 10;
    if(b=='J')
        return 11;
    if(b=='Q')
        return 12;
    if(b=='K')
        return 13;
    return b-'0';
}
int main()
{
    freopen("poker.in","r",stdin);
    freopen("poker.out","w",stdout);
    ans=0;
    memset(a,false,sizeof(a));
    scanf("%d",&n);
    for(int i=1,x,y;i<=n;i++)
    {
        scanf("%s",s);
        x=pd1();
        y=pd2();
        a[x][y]=true;
    }
    for(int i=1;i<=4;i++)
        for(int j=1;j<=13;j++)
            if(!a[i][j])
                ans++;
    printf("%d",ans);
    return 0;
}
