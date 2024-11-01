#include <bits/stdc++.h>
using namespace std;
int dx[]={0,1,0,-1};
int dy[]={1,0,-1,0};
bool flag[1010][1010];
char c[1010][1010];
int n,m,k;

bool in(int x,int y)
{
    return x>=1 && x<=n && y>=1 && y<=m;
}

bool OK(int x, int y)
{
    return c[x][y]=='.';
}

int main()
{
    freopen("explore.in","r",stdin);
    freopen("explore.out","w",stdout);
    int T;
    cin>>T;
    while(T--)
    {
        memset(flag,false,sizeof(flag));
        cin>> n>>m >>k;
        int x,y,d;
        cin>> x >>y >>d;
        flag[x][y]=true;
        int cnt=0;
        cnt++;
        for(int i=1;i<=n;i++)
        {
            string s;
            cin>> s;
            for(int j=1;j<=s.size();j++)
            {
                c[i][j]=s[j-1];
            }
        }
        for(int i=1;i<=k;i++)
        {
            int xx=x+dx[d];
            int yy=y+dy[d];
            if(in(xx,yy) && OK(xx,yy))
            {
                x=xx;
                y=yy;
                if(flag[x][y]==false)
                {
                    flag[x][y]=true;
                    cnt++;
                }
            }
            else{
                d=(d+1)%4;
            }
        }
        cout<<cnt<<endl;
    }
    return 0;
}
