#include<iostream>
using namespace std;
void init(){
    int n,m,k,x,y,d,ans=0;
    char mp[1009][1009];
    bool isz[1009][1009];
    cin>>n>>m>>k>>x>>y>>d;
    x--;
    y--;
    //------cin
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            cin>>mp[i][j];
            isz[i][j]=0;
        }
    }
    if(isz[x][y]==0){
        isz[x][y]=1;
        ans++;
    }
    for(int i=0;i<k;i++){
        int nx=x,ny=y;
        if(d==0){
            ny++;
        }
        else if(d==1){
            nx++;
        }
        else if(d==2){
            ny--;
        }
        else{
            nx--;
        }
        if(nx<0||ny<0||nx>=n||ny>=m||mp[nx][ny]=='x'){
            d+=1;
            d%=4;
        }
        else{
            x=nx;
            y=ny;
        }
        if(isz[x][y]==0){
            isz[x][y]=1;
            ans++;
        }
    }
    cout<<ans<<endl;
    return;

}
int main(){
    freopen("explore.in","r",stdin);
    freopen("explore.out","w",stdout);
    int T;
    cin>>T;
    for(int i=0;i<T;i++){
        init();
    }
    fclose(stdin);
    fclose(stdout);
    return 0;
}
