#include<iostream>
using namespace std;
int t;
int x,y,d;
int n,m,k;
int ans=0;
int x1[1005];
int y1[1005];
string str[1005];
int main(){
    freopen("explore.in","r",stdin);
    freopen("explore.out","w",stdout);
    cin>>t;
    cin>>n>>m>>k;
    cin>>x>>y>>d;
    for(int i=0;i<=n;i++){
        for(int j=0;j<=m;j++){
            cin>>str[i];
        }
    }
    for(int i=0;i<k-1;i++){
        if(d==0){
            str[x][y] = str[x][y+1];
        }
        else if(d=1){
            str[x][y]=str[x+1][y];
        }
        else if(d=2){
            str[x][y]=str[x][y-1];
        }
        else if(d=3){
            str[x][y]=str[x-1][y];
        }
        if(x>=1&&x<=n&&y>=1&&y<=m){
            str[x+1][y];
            ans++;
        }
        else{
            d=(d+1)%4;
            ans++;
        }
        x=x1[i];
        y=y1[i];
    }
    cout<<ans<<endl;
    for(int i=0;i<=ans;i++){
        cout<<x1[i]<<y1[i]<<endl;
    }
    return 0;
}
