#include<iostream>
#include<cstring>
using namespace std;

int t,n,m,k,x,y,d;
int dx[4]={0,1,0,-1};
int dy[4]={1,0,-1,0};
bool a[1010][1010];
bool vis[1010][1010];

int main()
{
    freopen("explore.in","r",stdin);
    freopen("explore.out","w",stdout);

    cin.tie(0),cout.tie(0);
    cin>>t;

    while(t--)
    {
        cin>>n>>m>>k;
        cin>>x>>y>>d;
        
        for(int i=1; i<=n; i++)
        {
            for(int j=1; j<=m; j++)
            {
                char c;
                cin>>c;
                a[i][j]=(c=='x');
            }
        }
        
        int cnt=1;
        memset(vis,0,sizeof(vis));
        vis[x][y]=1;
        
        while(k--)
        {
            int r=x+dx[d];
            int c=y+dy[d];
            
            if(a[r][c] || r<1 || r>n || c<1 || c>m)
                d=(d+1)%4;
            else if(vis[r][c]==0)
            {
                cnt++;
                x=r,y=c;
                vis[x][y]=1;
            }
        }
        cout<<cnt<<"\n";
    }

    return 0;
}