#include<bits/stdc++.h>
using namespace std;
bool a[1005][1005];
bool f[1005][1005];
int dx[4]={0,1,0,-1};
int dy[4]={1,0,-1,0};
long long ans;
void func(int x,int y,int d,int k,int n,int m)
{
    f[x][y]=true;
    while(k--)
    {
        x+=dx[d],y+=dy[d];
        if(x>=1&&x<=n&&y>=1&&y<=m&&a[x][y])
        {
            if(!f[x][y])
            {
                ans++;
                f[x][y]=true;
            }
        }
        else
        {
            x-=dx[d],y-=dy[d];
            d=(d+1)%4;
        }
    }
    return;
}
int main()
{
    freopen("explore.in","r",stdin);
    freopen("explore.out","w",stdout);
    int t;
    cin>>t;
    for(int i=1;i<=t;i++)
    {
        ans=1;
        memset(a,false,sizeof(a));
        memset(f,false,sizeof(f));
        int n,m,k,x,y,d;
        cin>>n>>m>>k>>x>>y>>d;
        for(int j=1;j<=n;j++)
        {
            string tmp;
            cin>>tmp;
            for(int s=1;s<=tmp.size();s++)
                a[j][s]=(tmp[s-1]=='x'?false:true);
        }
        func(x,y,d,k,n,m);
        cout<<ans<<endl;
    }
    return 0;
}
