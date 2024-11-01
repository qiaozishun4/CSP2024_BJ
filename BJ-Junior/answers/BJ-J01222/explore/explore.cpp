#include<bits/stdc++.h>
using namespace std;
bool a[1002][1002];
short ff[1002][1002];
int t;int n,m,k,sj;
bool yxm(int x,int y);
bool move_(int x,int y,int f){
    ff[x][y]=t;
     while(k--){
        if(f==0){
            if(yxm(x,y+1)){
                y++;
                ff[x][y]=t;
                continue;
            }
            else{
                f=(f+1)%4;
                continue;
            }
        }
        if(f==1){
            if(yxm(x+1,y)){
                x++;
                ff[x][y]=t;
                continue;
            }
            else{
                f=(f+1)%4;
                continue;
            }
        }
        if(f==2){
            if(yxm(x,y-1)){
                y--;
                ff[x][y]=t;
                continue;
            }
            else{
                f=(f+1)%4;
                continue;
            }
        }
        if(f==3){
            if(yxm(x-1,y)){
                x--;
                ff[x][y]=t;
                continue;
            }
            else{
                f=(f+1)%4;
                continue;
            }
        }
       // cout<<x<<" "<<y<<" "<<f<<endl;
     }
}
bool yxm(int x,int y){
if(x<=n&&x>=1&&y<=m&&y>=1){
        if(a[x][y])
    return 1;

}
return 0;
}
int main(){
    freopen("explore.in","r",stdin);
    freopen("explore.out","w",stdout);
    cin>>t;
    t++;
    while(--t){
        int x1,y1,fx,sum=0;
        cin>>n>>m>>k;
        cin>>x1>>y1>>fx;
        for(int i=1;i<=n;i++){
            for(int j=1;j<=m;j++){
                char tmp;
                cin>>tmp;
                a[i][j]=(tmp=='.');
            }
        }


        sj=0;
        move_(x1,y1,fx);
        for(int i=1;i<=n;i++){
            for(int j=1;j<=m;j++){
                 //   cout<<ff[i][j]<<" ";
                if(ff[i][j]==t)sj++;
            }
 //           cout<<endl;
        }
        cout<<sj<<'\n';
    }
}
