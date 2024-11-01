#include<iostream>
#include<cstdio>
#include<cstring>
using namespace std;
int T,n,m,k,x,y,d;
int mp[1010][1010];
int dx[10]={0,1,0,-1};
int dy[10]={1,0,-1,0};
int main()
{
    freopen("explore.in","r",stdin);
    freopen("explore.out","w",stdout);
    cin>>T;
    while(T--)
    {
        int cnt=0;
        cin>>n>>m>>k;
        for(int i=0;i<=1000;i++)
        {
            for(int j=0;j<=1000;j++)
            {
                mp[i][j]=1;
            }
        }
        cin>>x>>y>>d;
        for(int i=1;i<=n;i++)
        {
            for(int j=1;j<=m;j++)
            {
                char ch;
                cin>>ch;
                if(ch=='x')mp[i][j]=1;
                else mp[i][j]=0;
            }
        }
        mp[x][y]=3;
        cnt++;
        for(int i=1;i<=k;i++)
        {
            if(mp[x+dx[d]][y+dy[d]]==1)d=(d+1)%4;
            else
            {
                x+=dx[d];
                y+=dy[d];
                if(mp[x][y]!=3)cnt++;
                mp[x][y]=3;
            }
        }
        cout<<cnt<<endl;
    }
    return 0;
}
