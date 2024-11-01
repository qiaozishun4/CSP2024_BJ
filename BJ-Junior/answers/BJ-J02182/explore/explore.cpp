#include<bits/stdc++.h>
using namespace std;
int T;
bool a[10000][100000];
bool p[10000][100000];
string b;
long long m,n,k;
long long x,y,d,ans=1;
bool turn(int A,int B,int C)
{
    int tmpx,tmpy;
    tmpx=A;
    tmpy=B;
    if(C==0)
    {
        tmpy++;
    }
    if(C==1)
    {
        tmpx++;
    }
    if(C==2)
    {
        tmpy--;
    }
    if(C==3)
    {
        tmpx--;
    }
    if(tmpx>n||tmpy>m||a[tmpx][tmpy]||tmpx<=0||tmpy<=0)
        return 0;
    else
        return 1;
}
int main()
{
    freopen("explore.in","r",stdin);
    freopen("explore.out","w",stdout);
    cin>>T;
    for(int i=1;i<=T;i++)
    {
        ans=1;
        cin>>n>>m>>k;
        cin>>x>>y>>d;
        for(int j=1;j<=n;j++)
        {
            for(int k=1;k<=m;k++)
            {
                p[j][k]=0;
            }
        }
        for(int j=1;j<=n;j++)
        {
            cin>>b;
            for(int r=0;r<b.size();r++)
            {
                if(b[r]=='x')
                {
                    a[j][r+1]=1;
                }
                if(b[r]=='.')
                {
                    a[j][r+1]=0;
                }
            }
        }
        while(k>0)
        {
            k--;
            if(turn(x,y,d))
            {
                p[x][y]=1;
                if(d==0)
                {
                    y++;
                }
                if(d==1)
                {
                    x++;
                }
                if(d==2)
                {
                    y--;
                }
                if(d==3)
                {
                    x--;
                }
                if(p[x][y]!=1)
                {
                  ans++;
//            cout<<x<<" "<<y<<" "<<d<<endl;
                }
            }
            else
            {
                d++;
                if(d==4)
                    d=0;
            }


        }
        cout<<ans<<endl;
    }
    return 0;
}
