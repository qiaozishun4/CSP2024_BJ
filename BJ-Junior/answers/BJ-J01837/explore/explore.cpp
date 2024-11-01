#include<bits/stdc++.h>
using namespace std;
struct node{
    int d;
    int step;
    int x,y;
}q[200006],temp,newtemp;
int f,r,t;
void bfs(){
    int n,m,k,xx,yy,dd;
    f=0;
    r=0;
    char a[1006][1006];
    bool h[1006][1006]={false};
    int sum=0;
    cin>>n>>m>>k;
    cin>>xx>>yy>>dd;
    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            cin>>a[i][j];
        }
    }
    sum++;
    h[xx][yy]=true;
    q[r].step=0;
    q[r].d=dd;
    q[r].x=xx;
    q[r].y=yy;
    r=(r+1)%200006;
    while(f!=r){
        temp=q[f];
        f=(f+1)%200006;
        newtemp=temp;
        if(newtemp.step==k){
            cout<<sum<<endl;
            return;
        }
        int newx,newy;
        if(newtemp.d==0){
            newx=newtemp.x;
            newy=newtemp.y+1;
        }
        else if(newtemp.d==1){
            newx=newtemp.x+1;
            newy=newtemp.y;
        }
        else if(newtemp.d==2){
            newx=newtemp.x;
            newy=newtemp.y-1;
        }
        else{
            newx=newtemp.x-1;
            newy=newtemp.y;
        }
        if(newx>=1&&newx<=n&&newy>=1&&newy<=m&&a[newx][newy]!='x'){
            if(h[newx][newy]==false){
                sum++;
                h[newx][newy]=true;
            }
            newtemp.x=newx;
            newtemp.y=newy;
        }
        else{
            newtemp.d=(newtemp.d+1)%4;
        }
        newtemp.step++;
        q[r]=newtemp;
        r=(r+1)%200006;
    }
}
int main(){
    freopen("explore.in","r",stdin);
    freopen("explore.out","w",stdout);
    cin>>t;
    for(int i=1;i<=t;i++){
        bfs();
    }
    return 0;
}
