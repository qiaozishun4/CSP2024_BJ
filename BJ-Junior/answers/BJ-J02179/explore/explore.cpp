#include<bits/stdc++.h>
using namespace std;
long long t,x,y,k,n,m,d,res,c[1010][1010];
char mapp[1010][1010];
void ex(){
    cin>>n>>m>>k;
    cin>>x>>y>>d;
    res++;
    c[x][y]=1;
    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            cin>>mapp[i][j];
        }
    }
    for(int i=0;i<k;i++){
        if(d==0){
            if(y+1<=m&&mapp[x][y+1]!='x'){
                y++;
                if(c[x][y]==0){

                    c[x][y]=1;
                    res++;
                }
                continue;
            }
            else{
                d+=1;
                d%=4;
                continue;
            }
        }
        else if(d==1){
            if(x+1<=n&&mapp[x+1][y]!='x'){
                x++;
                if(c[x][y]==0){
                    c[x][y]=1;
                    res++;
                }
                continue;
            }
            else{
                d+=1;
                d%=4;
                continue;
            }
        }
        else if(d==2){
            if(y-1>0&&mapp[x][y-1]!='x'){
                y--;
                if(c[x][y]==0){
                    c[x][y]=1;
                    res++;
                }
                continue;
            }
            else{
                d+=1;
                d%=4;
                continue;
            }
        }
        else if(d==3){
            if(x-1>0&&mapp[x-1][y]!='x'){
                x--;
                if(c[x][y]==0){
                    c[x][y]=1;
                    res++;
                }
                continue;
            }
            else{
                d+=1;
                d%=4;
                continue;
            }
        }
    }
    cout<<res<<endl;
    res=k=x=y=d=0;
    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            c[i][j]=0;
        }
    }
    n=m=0;
}
int main(){
    freopen("explore.in","r",stdin);
    freopen("explore.out","w",stdout);
    cin>>t;
    for(int i=0;i<t;i++){
        ex();
    }
    return 0;
}
