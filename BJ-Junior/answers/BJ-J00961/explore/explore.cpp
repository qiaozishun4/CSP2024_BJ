#include<bits/stdc++.h>
using namespace std;
char a[10000][10000];
int main(){
    freopen("explore.in","r",stdin);
    freopen("explore.out","w",stdout);
    int T,n,m,k,x,y,d;//(x,y)当前坐标，d朝向,n行m列
    cin>>T;
    for(int o=0;o<T;o++){
        int len=1;
        cin>>n>>m>>k;
        cin>>x>>y>>d;
        for(int i=1;i<=n;i++){
            for(int j=1;j<=m;j++){
                cin>>a[i][j];
            }
        }
        while(k>0){
            if(d=0&&k>0){
                if(y+1>n){
                    k-=1;
                    d=(d+1)%4;
                }
                else if(a[x][y+1]=='x'){
                    k-=1;
                    d=(d+1)%4;
                }
                else{
                    y=y+1;
                    k-=1;
                    len+=1;
                }
            }
        if(d=1&&k>0){
            if(x+1>m){
                k-=1;
                d=(d+1)%4;
            }
            else if(a[x+1][y]=='x'){
                k-=1;
                d=(d+1)%4;
            }
            else{
                x=x+1;
                k-=1;
                len+=1;
            }
        }
        if(d=2&&k>0){
            if(y-1<=0){
                k-=1;
                d=(d+1)%4;
            }
            else if(a[x][y-1]=='x'){
                k-=1;
                d=(d+1)%4;
            }
            else{
                y=y-1;
                k-=1;
                len+=1;
            }
        }
        if(d=3&&k>0){
            if(x-1<=0){
                k-=1;
                d=(d+1)%4;
            }
            else if(a[x-1][y]=='x'){
                k-=1;
                d=(d+1)%4;
            }
            else{
                x=x-1;
                k-=1;
                len+=1;
            }
        }
    }
    cout<<len<<endl;
    }
    fclose(stdin);
    fclose(stdout);
    return 0;
}
