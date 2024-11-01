#include<bits/stdc++.h>
using namespace std;
int c[2010][2010];
string mp[2010];
void f(){
    int n,m,k,x,y,d;
    char h;
    scanf("%d%d%d%d%d%d",&n,&m,&k,&x,&y,&d);
    for(int i=0; i<n; i++){
        cin >> mp[i];
    }
    for(int i=0; i<n; i++){
        for(int l=0; l<m; l++){
            c[i][l]=0;
        }
    }
    x--;
    y--;
    for(int i=0; i<k; i++){
        c[x][y]=1;
        if(d==0){
            if(y+1>=m or mp[x][y+1]=='x'){
                d++;
                d=d%4;
            }else{
                y++;
            }
        }else if(d==2){
            if(y-1<0 or mp[x][y-1]=='x'){
                d++;
                d=d%4;
            }else{
                y--;
            }
        }else if(d==1){
            if(x+1>=n or mp[x+1][y]=='x'){
                d++;
                d=d%4;
            }else{
                x++;
            }
        }else if(d==3){
            if(x-1<0 or mp[x-1][y]=='x'){
                d++;
                d=d%4;
            }else{
                x--;
            }
        }
    }
    c[x][y]=1;
    int ret=0;
    for(int i=0; i<n; i++){
        for(int l=0; l<m; l++){
            if(c[i][l]==1){
                ret++;
            }
        }
    }
    printf("%d\n",ret);
    return;
}
int main(){
    freopen("explore.in","r",stdin);
    freopen("explore.out","w",stdout);
    int T;
    scanf("%d",&T);
    for(int i=0; i<T; i++){
        f();
    }
    return 0;
}
