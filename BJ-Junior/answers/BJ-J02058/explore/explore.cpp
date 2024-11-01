#include<bits/stdc++.h>
using namespace std;
int main(){
    freopen("explore.in","r",stdin);
    freopen("explore.out","w",stdout);
    int t,n,m,k,x,y,d,ans;
    char ch;
    bool a[1005][1005],b[1005][1005];
    cin>>t;
    while(t--)
        {
            memset(a,0,sizeof(a));memset(b,0,sizeof(b));ans=0;
            cin>>n>>m>>k>>x>>y>>d;
            for(int i=1;i<=n;i++)
                {
                    for(int j=1;j<=m;j++)
                        {
                            cin>>ch;
                            if(ch=='.')b[i][j]=true;
                        }
                }
            for(int i=1;i<=k;i++)
                {
                    a[x][y]=true;
                    if(d==0)
                        {
                            if(b[x][y+1]==true)
                                {
                                    y++;
                                    continue;
                                }
                            else 
                                {
                                    d=1;
                                    continue;
                                }
                        }
                    if(d==1)
                        {
                            if(b[x+1][y]==true)
                                {
                                    x++;
                                    continue;
                                }
                            else 
                                {
                                    d=2;
                                    continue;
                                }
                        }
                    if(d==2)
                        {
                            if(b[x][y-1]==true)
                                {
                                    y--;
                                    continue;
                                }
                            else 
                                {
                                    d=3;
                                    continue;
                                }
                        }
                    if(d==3)
                        {
                            if(b[x-1][y]==true)
                                {
                                    x--;
                                    continue;
                                }
                            else 
                                {
                                    d=0;
                                    continue;
                                }
                        }
                }
            for(int i=1;i<=n;i++)for(int j=1;j<=m;j++)if(a[i][j]==true)ans++;
            cout<<ans<<endl;
        }
    return 0;
}