#include<bits/stdc++.h>
using namespace std;

long long T;
long long sum=0;
long long n,m;
string s;
int mp[1010][1010];
long long ans[10];

void work(int x,int y,int d,int k)
{
    if(k<=0) return ;
    while(1)
    {
        if(d==0)
        {
            if(mp[x][y+1]!=2 && x>0 && y+1>0 && x<=n && y+1<=m)
            {
                mp[x][y+1]=1;
                work(x,y+1,d,k-1);
                return ;
            }
            else
            {
                d=1;
                k--;
                if(k==0) return ;
            }
        }
        if(d==1)
        {
            if(mp[x+1][y]!=2 && x+1>0 && y>0 && x+1<=n && y<=m)
            {
                mp[x+1][y]=1;
                work(x+1,y,d,k-1);
                return ;
            }
            else
            {
                d=2;
                k--;
                if(k==0) return ;
            }
        }
        if(d==2)
        {
            if(mp[x][y-1]!=2 && x>0 && y-1>0 && x<=n && y-1<=m)
            {
                mp[x][y-1]=1;
                work(x,y-1,d,k-1);
                return ;
            }
            else
            {
                d=3;
                k--;
                if(k==0) return ;
            }
        }
        if(d==3)
        {
            if(mp[x-1][y]!=2 && x-1>0 && y>0 && x-1<=n && y<=m)
            {
                mp[x-1][y]=1;
                work(x-1,y,d,k-1);
                return ;
            }
            else
            {
                d=0;
                k--;
                if(k==0) return ;
            }
        }
    }
    return ;
}

int main()
{
    freopen("explore.in","r",stdin);
    freopen("explore.out","w",stdout);
    int k;
    int x,y,d;
    cin>>T;
    int temp=0;
    while(temp<=T)
    {
        temp++;
        cin>>n>>m>>k;
        cin>>x>>y>>d;

        for(int i=1;i<=n;i++)
        {
            for(int j=1;j<=m;j++)
            {
                mp[i][j]=0;//初始化
            }
        }

        for(int i=1;i<=n;i++)
        {
            cin>>s;
            for(int j=0;j<m;j++)
            {
                if(s[j]=='.') mp[i][j+1]=0;
                else if(s[j]=='x') mp[i][j+1]=2;
            }
        }
        sum=0;//初始化
        mp[x][y]=1;
        work(x,y,d,k);
        for(int i=1;i<=n;i++)
        {
            for(int j=1;j<=m;j++)
            {
                if(mp[i][j]==1) sum++;
                mp[i][j]=0;
            }
        }
        cout<<sum<<endl;
    }
    return 0;
}
