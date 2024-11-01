#include<bits/stdc++.h>
using namespace std;
int n,m,t,k,xf,yf,df,dx[]={0,1,0,-1},dy[]={1,0,-1,0};
char c[1005][1005];
bool f[1005][1005];
struct Node
{
    int x,y,d,cnt;
};
inline void bfs(int xe,int ye,int de)
{
    queue <Node> q;
    q.push({xe,ye,de,k});
    f[xe][ye]=true;
    while(!q.empty())
    {
        int x=q.front().x,y=q.front().y,d=q.front().d,cnt=q.front().cnt;
        q.pop();
        if(cnt==0) return;
        while(!((x+dx[d])<=n&&(x+dx[d])>=1&&(y+dy[d])<=m&&(y+dy[d])>=1&&c[x+dx[d]][y+dy[d]]!='x'))
        {
        
            d=(d+1)%4;
            cnt--;
            if(!cnt) return;
        }
        q.push({x+dx[d],y+dy[d],d,cnt-1});
        f[x+dx[d]][y+dy[d]]=true;
    }
}
int main()
{
    freopen("explore.in","r",stdin);
    freopen("explore.out","w",stdout);
    cin>>t;
    while(t--)
    {
        cin>>n>>m>>k;
        cin>>xf>>yf>>df;
     //   cout<<"begin"<<" "<<n<<" "<<m<<" "<<k<<endl;
        for(int i=1;i<=n;i++)
        {
            string s;
            cin>>s;
            for(int j=1;j<=m;j++)
            {
                c[i][j]=s[j-1];
                //if(k==975128) cout<<n<<" "<<m<<" "<<c[i][j]<<endl;
            }
        }
        bfs(xf,yf,df);
        int ft=0;
        for(int i=1;i<=n;i++)
        {
            for(int j=1;j<=m;j++)
            {
                if(f[i][j]) ft++;
                f[i][j]=false;
            }
        }
        cout<<ft<<endl;
      //  cout<<"end "<<n<<" "<<m<<" "<<k<<endl;
    }
    return 0;
}