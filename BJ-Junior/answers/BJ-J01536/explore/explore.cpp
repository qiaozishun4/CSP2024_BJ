#include<bits/stdc++.h>
using namespace std;
int T,n,m,k,x,y,d;
bool flag[1005][1005];
string s[1005];
int f1(int x,int d){
    if(d==0||d==2)return x;
    if(d==1)return x+1;
    return x-1;
}
int f2(int y,int d){
    if(d==1||d==3)return y;
    if(d==0)return y+1;
    return y-1;
}
bool check(int x,int y){
    if(x<0||y<0||x>=n||y>=m)return false;
    if(s[x][y]=='x')return false;
    return true;
}
void Main(){
    cin>>n>>m>>k>>x>>y>>d;
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            flag[i][j]=0;
        }
    }
    x--,y--;
    for(int i=0;i<n;i++)cin>>s[i];
    flag[x][y]=1;
    while(k>0){
        int nextx=f1(x,d),nexty=f2(y,d);
        if(check(nextx,nexty)){
            x=nextx;
            y=nexty;
            flag[x][y]=1;
            k--;
        }
        else{
            do{
                d=(d+1)%4;
                k--;
                nextx=f1(x,d);
                nexty=f2(y,d);
            }while(!check(nextx,nexty)&&k>0);
            if(check(nextx,nexty)&&k>0){
                flag[nextx][nexty]=1;
                k--;
                x=nextx,y=nexty;
            }
        }
    }
    int sum=0;
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            if(flag[i][j]==1){
                sum++;
            }
        }
    }
    cout<<sum<<endl;
    return;
}
int main(){
    freopen("explore.in","r",stdin);
    freopen("explore.out","w",stdout);
    cin>>T;
    while(T--)Main();
}
