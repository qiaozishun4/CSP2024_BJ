#include <bits/stdc++.h>
using namespace std;
int main(){
    freopen("explore.in","r",stdin);
    freopen("explore.out","w",stdout);
    int t; cin>>t;
    for(int i=1;i<=t;i++)
    {
        int n,m,k,x,y,d;
        cin>>n>>m>>k>>x>>y>>d;
        string s[n+1];
        int flag[n+1][m+1];
        for(int j=1;j<=n;j++)
        {
            s[j]=" ";
            string l; cin>>l;
            s[j]+=l;
            for(int l=1;l<=m;l++)
            {
                flag[j][l]=0;
            }
        }
        flag[x][y]=1;
        for(int j=1;j<=k;j++)
        {
            if(d==0)
            {
                if(y+1>m||s[x][y+1]=='x')
                {
                    d=(d+1)%4;
                    continue;
                }
                y++;
                flag[x][y]=1;
            }
            else if(d==1)
            {
                if(x+1>n||s[x+1][y]=='x')
                {
                    d=(d+1)%4;
                    continue;
                }
                x++;
                flag[x][y]=1;
            }
            else if(d==2)
            {
                if(y-1<1||s[x][y-1]=='x')
                {
                    d=(d+1)%4;
                    continue;
                }
                y--;
                flag[x][y]=1;
            }
            else if(d==3)
            {
                if(x-1<1||s[x-1][y]=='x')
                {
                    d=(d+1)%4;
                    continue;
                }
                x--;
                flag[x][y]=1;
            }
        }
        int ans=0;
        for(int j=1;j<=n;j++)
        {
            for(int l=1;l<=m;l++)
            {
                if(flag[j][l]==1) ans++;
            }
        }
        cout<<ans<<endl;
    }
    return 0;
}
