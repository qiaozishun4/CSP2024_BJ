#include<bits/stdc++.h>
using namespace std;
int ans,n,m,d,x,y,t,k,dx[4]={0,1,0,-1},dy[4]={1,0,-1,0};
bool arry[1001][1001],mem[1001][1001];
string s;
int main()
{
    freopen("explore3.in","r",stdin);
    freopen("explore.out","w",stdout);
   ios::sync_whith_stdio(0);
    cin>>t;
    while(t--)
    {
        cin>>n>>m>>k;
        cin>>x>>y>>d;
        memset(mem,0,sizeof(mem));
        for(int i=1;i<=n;i++)
        {
            cin>>s;
            for(int j=1;j<=m;j++)
            {
                arry[i][j]=(s[j-1]=='.');
            }
        }
        ans=1;
        mem[x][y]=1;
        while(k--)
        {
            if((x+dx[d]>=1&&x+dx[d]<=n)&&(y+dy[d]>=1&&y+dy[d]<=m)&&arry[x+dx[d]][y+dy[d]])
            {
                x+=dx[d];
                y+=dy[d];
                if(mem[x][y]==0)
                {
                    mem[x][y]=1;
                    ans++;
                }
            }
            else
            {
                d=(d+1)%4;
            }
        }
        cout<<ans<<'\n';
    }
    return 0;
}