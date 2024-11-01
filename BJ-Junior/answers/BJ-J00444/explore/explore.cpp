#include<bits/stdc++.h>
using namespace std;
char s[1001][1001];
bool b[1001][1001];
int dx[10]={0,1,0,-1};
int dy[10]={1,0,-1,0};
int n,m,k;
bool inn(int x,int y)
{
    if(x>0&&x<=n&&y>0&&y<=m&&s[x][y]=='.') return 1;
    return 0;
}
int main()
{
    freopen("explore.in","r",stdin);
    freopen("explore.out","w",stdout);
    int t,x,y,d,xx,xy,ans;
    cin >> t;
    while(t--)
    {
        memset(b,0,sizeof b);
        ans=1;
        cin >>n >>m >>k >>x >> y >> d;
        for(int i=1;i<=n;i++) cin >>s[i]+1;
        b[x][y]=1;
        while(k--)
        {
            xx=x+dx[d],xy=y+dy[d];
            if(inn(xx,xy))
            {
                x=xx;
                y=xy;
 //               cout << "?? "<<x << ' ' <<y <<endl;
                if(!b[x][y])
                {
                    b[x][y]=1;
                    ans++;
   //                 cout << "++" << endl;
                }
            }
            else
            {
                d=(d+1)%4;
   //             cout << "!! " << d <<endl;
            }

        }
        cout <<ans << endl;
    }
    return 0;
}
