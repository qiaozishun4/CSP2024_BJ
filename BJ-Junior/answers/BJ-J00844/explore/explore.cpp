#include<bits/stdc++.h>
using namespace std;
int a,h,l,num,x,y,d,cnt,cnta;
char Map[1005][1005];
bool gomap[1005][1005];
void apply(int x0,int y0,int d){
    gomap[x0][y0]=true;
    if(cnta==num)return;
    int x1,y1,d1;
    if(d==0){
        x1=x0;
        y1=y0+1;
    }
    else if(d==1){
        x1=x0+1;
        y1=y0;
    }
    else if(d==2){
        x1=x0;
        y1=y0-1;
    }
    else if(d==3){
        x1=x0-1;
        y1=y0;
    }
    if(x1>=0&&y1>=0&&x1<h&&y1<l&&!(Map[x1][y1]=='x')){
        x0=x1;
        y0=y1;
        cnta++;
        apply(x0,y0,d);
    }
    else{
        d++;
        if(d==4)d=0;
        cnta++;
        apply(x0,y0,d);
    }
}
int main(){
    freopen("explore.in","r",stdin);
    freopen("explore.out","w",stdout);
    cin>>a;
    for(int i=0;i<a;i++){
        cin>>h>>l>>num>>x>>y>>d;
        x--;
        y--;
        for(int i=0;i<h;i++)for(int j=0;j<l;j++)gomap[i][j]=false;
        for(int i=0;i<h;i++)for(int j=0;j<l;j++)cin>>Map[i][j];
        apply(x,y,d);
        for(int i=0;i<h;i++)for(int j=0;j<l;j++)if(gomap[i][j])cnt++;
        cout<<cnt<<"\n";
    }
    return 0;
}