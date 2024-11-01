#include<bits/stdc++.h>
using namespace std;
const int N=1e3+5;
int t;
int main(){
    freopen("explore.in","r",stdin);
    freopen("explore.out","w",stdout);
    cin>>t;
    while(t--){
        int n,m,k;
        cin>>n>>m>>k;
        string s[n+5];
        int x,y,d;
        cin>>x>>y>>d;
        for(int i=1;i<=n;i++){
            cin>>s[i];
        }
        bool vis[N][N]={};
        vis[x][y]=1;
        int cnt=1;
        while(k--){
            if(d==0){
                int x1=x,y1=y+1;
                if(s[x1][y1-1]!='x'&&x1<=n&&y1<=m&&x1>=1&&y1>=1){
                    x=x1;
                    y=y1;
                    if(!vis[x][y]){
                        vis[x][y]=true;
                        cnt++;
                    }
                }
                else{
                    d=(d+1)%4;
                }
            }
            else if(d==1){
                int x1=x+1,y1=y;
                if(s[x1][y1-1]!='x'&&x1<=n&&y1<=m&&x1>=1&&y1>=1){
                    x=x1;
                    y=y1;
                    if(!vis[x][y]){
                        vis[x][y]=true;
                        cnt++;
                    }
                }
                else{
                    d=(d+1)%4;
                }
            }
            else if(d==2){
                int x1=x,y1=y-1;
                if(s[x1][y1-1]!='x'&&x1<=n&&y1<=m&&x1>=1&&y1>=1){
                    x=x1;
                    y=y1;
                    if(!vis[x][y]){
                        vis[x][y]=true;
                        cnt++;
                    }
                }
                else{
                    d=(d+1)%4;
                }
            }
            else{
                int x1=x-1,y1=y;
                if(s[x1][y1-1]!='x'&&x1<=n&&y1<=m&&y1>=1&&x1>=1){
                    x=x1;
                    y=y1;
                    if(!vis[x][y]){
                        vis[x][y]=true;
                        cnt++;
                    }
                }
                else{
                    d=(d+1)%4;
                }
            }
        }
        cout<<cnt<<endl;
    }
    return 0;
}

