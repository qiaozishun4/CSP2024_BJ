#include<iostream>
#include<string>
using namespace std;
string a[1005];
bool visited[1005][1005]={0},can[1005][1005]={0};
int n,m,x,y,k,oldd;
struct j{
    int x;
    int y;
    int d;
};
j w;
void go(int d){
    visited[w.x][w.y]=true;
    if(d==0){
        w.y++;
    }else if(d==1){
        w.x++;
    }else if(d==2){
        w.y--;
    }else{
        w.x--;
    }
}
void z(){
    w.d=(w.d+1)%4;
}
bool cango(){
    if(w.d==0){
        return can[w.x][w.y+1];
    }else if(w.d==1){
        return can[w.x+1][w.y];
    }else if(w.d==2){
        return can[w.x][w.y-1];
    }else{
        return can[w.x-1][w.y];
    }
}
int visit(){
    int ans=0;
    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            ans+=visited[i][j];
        }
    }
    return ans;
}
int main(){
    freopen("explore.in","r",stdin);
    freopen("explore.out","w",stdout);

    int t;
    cin>>t;
    while(t--){
        cin>>n>>m>>k;
        cin>>x>>y>>oldd;
        w.x=x;
        w.y=y;
        w.d=oldd;
        visited[x][y]=true;
        for(int i=1;i<=n;i++){
            cin>>a[i];
        }
        for(int i=1;i<=n;i++){
            for(int j=1;j<=m;j++){
                if(a[i][j-1]=='x'){
                    can[i][j]=false;
                }else{
                    can[i][j]=true;
                }
            }
        }
        for(int i=0;i<k;i++){
            if(cango()){
                go(w.d);
            }else{
                z();
            }
        }
        visited[w.x][w.y]=true;
        cout<<visit()<<endl;
        for(int i=1;i<=1000;i++){
            for(int j=1;j<=1000;j++){
                visited[i][j]=false;
                can[i][j]=false;
            }
        }
    }
    return 0;
}

