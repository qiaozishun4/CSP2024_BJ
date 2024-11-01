#include<bits/stdc++.h>
using namespace std;
char mp[1010][1010];
bool vis[1010][1010];
int main()
{
    freopen("explore.in","r",stdin);
    freopen("explore.out","w",stdout);
    int t,n,m,k,x,y,d,cnt;
    cin>>t;
    while(t--) {
        cnt=1;
        cin>>n>>m>>k>>x>>y>>d;
        for(int i=1;i<=n;i++) {
            for(int j=1;j<=m;j++) {
                cin>>mp[i][j];
                vis[i][j]=0;
            }
        }
        vis[x][y]=1;
        while(k--) {
            if(d==0) {
                if(y+1>m||mp[x][y+1]=='x') {
                    d=(d+1)%4;
                }
                else {
                    y+=1;
                    if(!vis[x][y]) {
                        vis[x][y]=1;
                        cnt++;
                    }
                }
            }
            else if(d==1) {
                if(x+1>n||mp[x+1][y]=='x') {
                    d=(d+1)%4;
                }
                else {
                    x+=1;
                    if(!vis[x][y]) {
                        vis[x][y]=1;
                        cnt++;
                    }
                }
            }
            else if(d==2) {
                if(y-1<1||mp[x][y-1]=='x') {
                    d=(d+1)%4;
                }
                else {
                    y-=1;
                    if(!vis[x][y]) {
                        vis[x][y]=1;
                        cnt++;
                    }
                }
            }
            else {
                if(d==3) {
                    if(x-1<1||mp[x-1][y]=='x') {
                        d=(d+1)%4;
                    }
                    else {
                        x-=1;
                        if(!vis[x][y]) {
                            vis[x][y]=1;
                            cnt++;
                        }
                    }
                }
            }
        }
        cout<<cnt<<endl;
    }
    return 0;
}

