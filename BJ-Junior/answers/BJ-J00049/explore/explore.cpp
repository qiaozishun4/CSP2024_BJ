#include<bits/stdc++.h>
using namespace std;

int m,n,k,xt,yt,d;
char a[1100][1100];
bool b[1100][1100];

struct xy{
    int x,y;
    xy(){x=0,y=0;}
    xy(int x_,int y_){x=x_,y=y_;}
};

xy cal(int & d1,int x,int y,bool f=0)
{
    if(f)d1=(d1+1)%4;
    if(d1==0)return xy(x,y+1);
    if(d1==1)return xy(x+1,y);
    if(d1==2)return xy(x,y-1);
    if(d1==3)return xy(x-1,y);
}

bool in(xy ss)
{
    if(ss.x>0&&ss.x<=n&&ss.y>0&&ss.y<=m&&a[ss.x][ss.y]=='.')return 1;
    return 0;
}

int main()
{
    freopen("explore.in","r",stdin);
    freopen("explore.out","w",stdout);
    int T;
    cin>>T;
    while(T--)
    {
        memset(a,0,sizeof(a));
        memset(b,0,sizeof(b));
        cin>>n>>m>>k>>xt>>yt>>d;
        for(int i=1;i<=n;i++)
        {
            for(int j=1;j<=m;j++)
            {
                cin>>a[i][j];
            }
        }
        int cnt=0;
        b[xt][yt]=1;
        while(k--)
        {
            if(in(cal(d,xt,yt)))xt=cal(d,xt,yt).x,yt=cal(d,xt,yt).y;
            else cal(d,xt,yt,1);
            b[xt][yt]=1;
        }
        for(int i=1;i<=n;i++)
        {
            for(int j=1;j<=m;j++)
            {
                if(b[i][j]==1)cnt++;
            }
        }
        cout<<cnt<<endl;
    }
    return 0;
}
