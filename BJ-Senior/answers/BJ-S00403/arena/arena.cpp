#include<bits/stdc++.h>
using namespace std;

int a[510],c[510],d[5],aa,df[510];
char s[510][510];

void dfs(int x,int lun)
{
    if(x==1)
    {
        aa=df[1];
        return ;
    }
    for(int i=2;i<=x;i+=2)
    {
        if(s[lun][i/2-1]=='0')
        {
            if(a[df[i-1]]>=lun)
                df[i/2]=df[i-1];
            else
                df[i/2]=df[i];
        }
        else
        {
            if(a[df[i]]>=lun)
                df[i/2]=df[i];
            else
                df[i/2]=df[i-1];
        }
    }
    return ;
}

int main()
{
    freopen("arena.in","r",stdin);
    freopen("arena.out","w",stdout);
    int T;
    cin>>T;
    int n,m;
    cin>>n>>m;
    for(int i=1;i<=n;i++)
    {
        cin>>a[i];
    }
    for(int i=1;i<=m;i++)
        cin>>c[i];
    int num=0;
    while(true)
    {
        num++;
        cin>>s[num];
        if(strlen(s[num])==1)
        {
            break;
        }
    }
    for(int i=1;i<=4;i++)
        cin>>d[i];
    for(int i=1;i<=n;i++)
        a[i]=a[i]^(d[i%4]);
    int ans=0;
    for(int i=1;i<=m;i++)
    {
        aa=0;
        for(int i=1;i<=n;i++)
            df[i]=i;
        dfs(c[i],1);
        if(i==1)
            ans=aa;
        else
            ans=ans^(i*aa);
    }
    cout<<ans;
    return 0;
}
