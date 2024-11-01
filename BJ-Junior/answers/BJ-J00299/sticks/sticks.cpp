#include<bits/stdc++.h>
using namespace std;
struct node{
    int a;
    int b;
}d[7];
int f[10005];
int p[10005];
bool cmp(int x,int y)
{
    return x<y;
}
int add(int x,int y)
{
    int s=x;
    int t=1;
    int m=x/10;
    for(int i=1;i<=m;i++)
    {
        p[i]=(s/t)%t*10;
        t=t*10;
    }
    p[m+1]=y;
    sort(p+1,p+m+2,cmp);
    int pl;
    for(int i=1;i<=m+1;i++)
    {
        if(p[i]!=0)
        {
            pl=i;
        }
    }
    if(pl!=1)
    {
        swap(p[1],p[pl]);
    }
    int cnt=0;
    t=1;
    for(int i=m+1;i>=1;i--)
    {
        cnt+=p[i]*t;
        t=t*10;
    }
    return cnt;
}
int main()
{
    freopen("sticks.in","r",stdin);
    freopen("sticks.out","w",stdout);
    d[1].a=8;
    d[1].b=7;
    d[2].a=0;
    d[2].b=6;
    d[3].a=6;
    d[3].b=6;
    d[4].a=2;
    d[4].b=5;
    d[5].a=4;
    d[5].b=4;
    d[6].a=7;
    d[6].b=3;
    d[7].a=1;
    d[7].b=2;
    int t;
    cin>>t;
    for(int i=1;i<=10005;i++)
    {
        f[i]=100005;
    }
    f[2]=1;
    f[3]=7;
    f[4]=4;
    f[5]=2;
    f[6]=6;
    f[7]=8;
    f[8]=10;
    f[9]=18;
    f[10]=22;
    f[11]=20;
    f[12]=28;
    f[13]=80;
    for(int i=1;i<=t;i++)
    {
        int n;
        cin>>n;
        if(n<=1)
        {

            cout<<-1<<endl;
            continue;
        }
        if(n<=13)
        {
            cout<<f[n]<<endl;
            continue;
        }
        for(int j=1;j<=n;j++)
        {
            for(int k=7;k>=1;j++)
            {
                f[j]=min(f[j],add(f[j-k],k));
            }
        }
        cout<<f[n]<<endl;
    }
    return 0;
}
