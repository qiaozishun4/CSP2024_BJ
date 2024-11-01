#include<bits/stdc++.h>
using namespace std;
string a[1010];
int vis[1010][1010];
void d(int x,int y,int b,int s){
    if(!s){
        return;
    }
    if(b==0){
        if(a[x][y+1]=='x'){
            d(x,y,(b+1)%4,s);
            return;
        }
        vis[x][y+1]=1;
        d(x,y+1,b,s-1);
        return;
    }
    if(b==1){
        if(a[x+1][y]=='x'){
            d(x,y,(b+1)%4,s);
            return;
        }
        vis[x+1][y]=1;
        d(x+1,y,b,s-1);
    }
    if(b==2){
        if(a[x][y-1]=='x'||(y-1)<1){
            d(x,y,(b+1)%4,s);
            return;
        }
        vis[x][y-1]=1;
        d(x,y-1,b,s-1);
    }
    if(b==3){
        if(a[x-1][y]=='x' ||(x-1)<1){
            d(x,y,(b+1)%4,s);
            return;
        }
        vis[x-1][y]=1;
        d(x-1,y,b,s-1);
    }
}
int main(){
    freopen("jiqiren.in","r",stdin);
    freopen("jiqiren.out","w",stdout);
    int p=0;
    cin>>p;
    for(int g=1;g<=p;g++){
        int n=0,m=0,b=0,k=0,cnt=0,x,y;
        cin>>n>>m>>k>>x>>y>>b;
        for(int i=1;i<=n;i++){
            cin>>a[i];
        }
        for(int i=1;i<=n;i++){
            a[i][m+1]='x';
        }
        for(int i=1;i<=m;i++){
            a[n+1][i]='x';
        }
        d(x,y,b,k);
        for(int i=1;i<=n;i++){
            for(int j=1;j<=m;j++){
                if(vis[i][j]){
                    cnt++;
                    vis[i][j]=0;
                }
            }
        }
        cout<<cnt<<endl;
    }
    return 0;
}
