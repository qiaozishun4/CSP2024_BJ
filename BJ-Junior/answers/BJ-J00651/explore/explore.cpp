#include<bits/stdc++.h>
using namespace std;
int main(){
    freopen("explore.in","r",stdin);
    freopen("explore.out","w",stdout);
    int T;
    cin>>T;
    while(T--){
        int n,m,k,x,y,d,vis=1;
        int v[1010][1010]={};
        char a[1010][1010];
        memset(v,0,sizeof(v));
        cin>>n>>m>>k>>x>>y>>d;
        for (int i=1;i<=n;i++)
            for (int j=1;j<=m;j++)
                cin>>a[i][j];
        v[x][y]=1;
        for (int i=1;i<=k;i++){
            if (d==0){
                if (y+1>m || a[x][y+1]=='x'){
                    d=(d+1)%4;
                    continue;
                }
                else{
                    if (v[x][y+1]==0){
                        v[x][y+1]=1;
                        vis++;
                    }
                    y++;
                }
            }
            else if (d==1){
                if (x+1>n || a[x+1][y]=='x'){
                    d=(d+1)%4;
                    continue;
                }
                else{
                    if (v[x+1][y]==0){
                        v[x+1][y]=1;
                        vis++;
                    }
                    x++;
                }
            }
            else if (d==2){
                if (y-1<1 || a[x][y-1]=='x'){
                    d=(d+1)%4;
                    continue;
                }
                else{
                    if (v[x][y-1]==0){
                        v[x][y-1]=1;
                        vis++;
                    }
                    y--;
                }
            }
            else if (d==3){
                if (x-1<1 || a[x-1][y]=='x'){
                    d=(d+1)%4;
                    continue;
                }
                else{
                    if (v[x-1][y]==0){
                        v[x-1][y]=1;
                        vis++;
                    }
                    x--;
                }
            }
        }
        cout<<vis<<endl;
    }
    return 0;
}