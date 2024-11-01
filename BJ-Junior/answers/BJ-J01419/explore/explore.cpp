#include<bits/stdc++.h>
using namespace std;
//若 d = 0,则令 (x ′ , y ′ ) = (x, y + 1),若 d = 1,则令(x ′ , y ′ ) = (x + 1, y),若 d = 2,则令 (x ′ , y ′ ) = (x, y − 1),若 d = 3,则令(x ′ , y ′ ) = (x − 1, y)
//d ′ = (d + 1) mod 4
//1 ≤ x ′ ≤ n, 1 ≤ y ′ ≤ m
int T,nn,mm,k,xu,yu,du,mmap[1010][1010],vis[1010][1010],cnt,yp,xp;
char ttmp;
void explore(int x,int y,int d,int k){
    if(vis[x][y]!=1){
        cnt++;
        vis[x][y]=1;
    }
    if(k<=0){
        return;
    }
    if((x==xu)&&(y==yu)&&(d==du)&&(x!=xp)&&(y!=yp)){
        return;
    }
    xp=x;yp=y;
    if(d==0){
        if((1<=x)&&(x<=nn)&&(1<=(y+1))&&((y+1)<=mm)&&(!mmap[x][y+1])){
            explore(x,y+1,d,k-1);
        }
        else{
            explore(x,y,(d+1)%4,k-1);
        }    }
    if(d==1){
        if((1<=(x+1))&&((x+1)<=nn)&&(1<=y)&&(y<=mm)&&(!mmap[x+1][y])){
            explore(x+1,y,d,k-1);
        }
        else{
            explore(x,y,(d+1)%4,k-1);
        }
    }
    if(d==2){
        if((1<=x)&&(x<=nn)&&(1<=(y-1))&&((y-1)<=mm)&&(!mmap[x][y-1])){
            explore(x,y-1,d,k-1);
        }
        else{
            explore(x,y,(d+1)%4,k-1);
        }
    }
    if(d==3){
        if((1<=(x-1))&&((x-1)<=nn)&&(1<=y)&&(y<=mm)&&(!mmap[x-1][y])){
            explore(x-1,y,d,k-1);
        }
        else{
            explore(x,y,(d+1)%4,k-1);
        }
    }
}
void run(){
    cin>>nn>>mm>>k;
    cin>>xu>>yu>>du;
    for(int i=1;i<=nn;i++){
       for(int j=1;j<=mm;j++){
            cin>>ttmp;
            if(ttmp=='.'){
                mmap[i][j]=0;
                vis[i][j]=0;
            }
            if(ttmp=='x'){
                mmap[i][j]=1;
                vis[i][j]=0;
            }
        }
    }
    xp=xu;yp=yu;cnt=0;
    explore(xu,yu,du,k);
    cout<<cnt<<endl;
}
int main(){
    freopen("explore.in","r",stdin);
    freopen("explore.out","w",stdout);
    cin>>T;
    for(int i=1;i<=T;i++){
        run();
    }
    return 0;
}

