#include<bits/stdc++.h>
using namespace std;
int T=0;
int n=0;
int m=0;
bool map1[1001][1001];
bool romap[1001][1001];
int ans=0;

int robot(int x,int y,int d,int k)
{
    int xn=0,yn=0;
    if(romap[x][y]==0)
    {
        romap[x][y]=1;
        ans++;
    }
    if(k==0) return ans;
    if(d==0)
    {
        xn=0;
        yn=1;
    }
    else if(d==1)
    {
        xn=1;
        yn=0;
    }
    else if(d==2)
    {
        xn=0;
        yn=-1;
    }
    else
    {
        xn=-1;
        yn=0;
    }

    if(x+xn>=1 && x+xn<=n && y+yn>=1 && y+yn<=m)
    {
        if(map1[x+xn][y+yn]) return robot(x+xn,y+yn,d,k-1);
        else return robot(x,y,(d+1)%4,k-1);
    }
    else return robot(x,y,(d+1)%4,k-1);
}

int main()
{
    freopen("explore.in","r",stdin);
    freopen("explore.out","w",stdout);
    cin>>T;
    int x=0,y=0,d=0,k=0;
    string temp;
    for(int t=0;t<T;t++)
    {
        cin>>n>>m>>k;
        cin>>x>>y>>d;
        for(int i=1;i<=n;i++)
        {
            cin>>temp;
            for(int j=0;j<m;j++)
            {
                if(temp[j]=='.') map1[i][j+1]=1;
                else if(temp[j]=='x') map1[i][j+1]=0;
            }
        }
        cout<<robot(x,y,d,k)<<endl;
        ans=0;
        for(int i=1;i<=n;i++)
        {
            for(int j=1;j<=m;j++)
            {
                romap[i][j]=0;
            }
        }
    }
    return 0;
}