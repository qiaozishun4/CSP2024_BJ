#include<iostream>
using namespace std;
int x,y;
int cnt;
int dx,dy;
int cx;
char a[1000][1000];
int f(int dx,int dy,int cx,int cnt){
    if(cnt==0){
        return 1;
    }
    a[dx][dy]='1';
    if(cx==0){
        if(dx>=1&&dx<=x&&dy+1>=1&&dy+1<=y&&a[dx][dy+1]!='x'){
            if(a[dx][dy+1]!='1'){
            a[dx][dy+1]='1';
            return 1+f(dx,dy+1,cx,cnt-1);
            }else{
            return f(dx,dy+1,cx,cnt-1);
            }
        }else{
            cx=(cx+1)%4;
            return f(dx,dy,cx,cnt-1);
        }
    }
    if(cx==1){
        if(dx+1>=1&&dx+1<=x&&dy>=1&&dy<=y&&a[dx+1][dy]!='x'){
            if(a[dx+1][dy]!='1'){
            a[dx+1][dy]='1';
            return 1+f(dx+1,dy,cx,cnt-1);
            }else{
            return f(dx+1,dy,cx,cnt-1);
            }
        }else{
            cx=(cx+1)%4;
            return f(dx,dy,cx,cnt-1);
        }
    }
    if(cx==2){
        if(dx>=1&&dx<=x&&dy-1>=1&&dy-1<=y&&a[dx][dy-1]!='x'){
            if(a[dx][dy-1]!='1'){
            a[dx][dy-1]='1';
            return 1+f(dx,dy-1,cx,cnt-1);
            }else{
            return f(dx,dy-1,cx,cnt-1);
            }
        }else{
            cx=(cx+1)%4;
            return f(dx,dy,cx,cnt-1);
        }
    }
    if(cx==3){
        if(dx-1>=1&&dx-1<=x&&dy>=1&&dy<=y&&a[dx-1][dy]!='x'){
            if(a[dx-1][dy]!='1'){
            a[dx-1][dy]='1';
            return 1+f(dx-1,dy,cx,cnt-1);
            }else{
            return f(dx-1,dy,cx,cnt-1);
            }
        }else{
            cx=(cx+1)%4;
            return f(dx,dy,cx,cnt-1);
        }
    }
}
int main(){
freopen("explore.in","r",stdin);
freopen("explore.out","w",stdout);
    int w;
    cin>>w;
    while(w--){
        cin>>x>>y;
        cin>>cnt;
        cin>>dx>>dy;
        cin>>cx;

        for(int i=1;i<=x;i++){
            for(int j=1;j<=y;j++){
                cin>>a[i][j];
            }
        }
        cout<<f(dx,dy,cx,cnt)<<endl;
    }
    return 0;
}
