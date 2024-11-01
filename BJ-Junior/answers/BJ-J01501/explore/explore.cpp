#include <bits/stdc++.h>
using namespace std;
int n,m,k,X,Y,D,maxn=0,a[1001][1001];
char s[1001][1001];
bool check(int x,int y)
{
    if(x>0&&y>0&&x<=n&&y<=m&&s[x][y]=='.') return 1;
    return 0;
}
void dfs(int x,int y,int d,int i)
{
    if(i>k)
    {
        int cnt=0;
        for(int i=1;i<=n;i++)
        {
            for(int j=1;j<=m;j++)
            {
                if(a[i][j]) cnt++;
            }
        }
        if(cnt>maxn) maxn=cnt;
        return;
    }
    for(int j=1;j<=k;j++)
    {
        if(d==0)
        {
            if(check(x,y+1))
            {
                a[x][y+1]=1;
                dfs(x,y+1,d,i+1);
                a[x][y+1]=0;
            }
            else d=(d+1)%4;
        }
        else if(d==1)
        {
            if(check(x+1,y))
            {
                a[x+1][y]=1;
                dfs(x+1,y,d,i+1);
                a[x+1][y]=0;
            }
            else d=(d+1)%4;
        }
        else if(d==2)
        {
            if(check(x,y-1))
            {
                a[x][y-1]=1;
                dfs(x,y-1,d,i+1);
                a[x][y-1]=0;
            }
            else d=(d+1)%4;
        }
        else
        {
            if(check(x-1,y))
            {
                a[x-1][y]=1;
                dfs(x-1,y,d,i+1);
                a[x-1][y]=0;
            }
            else d=(d+1)%4;
        }
    }
}
int t;
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    freopen("explore.in","r",stdin);
    freopen("explore.out","w",stdout);
    cin>>t;
    while(t--)
    {
        cin>>n>>m>>k>>X>>Y>>D;
        for(int i=1;i<=n;i++)
        {
            for(int j=1;j<=m;j++) cin>>s[i][j];
        }
        if(k==1)
        {
            if(D==1)
            {
                if(check(X,Y+1)) cout<<2<<endl;
                else cout<<1<<endl;
            }
            if(D==2)
            {
                if(check(X+1,Y)) cout<<2<<endl;
                else cout<<1<<endl;
            }
            if(D==3)
            {
                if(check(X,Y-1)) cout<<2<<endl;
                else cout<<1<<endl;
            }
            if(D==4)
            {
                if(check(X-1,Y)) cout<<2<<endl;
                else cout<<1<<endl;
            }
            continue;
        }
        maxn=0;
        memset(a,0,sizeof(a));
        dfs(X,Y,D,1);
        cout<<maxn<<endl;
    }
    return 0;
}
