#include<iostream>
using namespace std;
char a[1001][1001];
bool f[1001][1001];
int x,y,d;
int main(){
    int t,n,m,k,cnt=1;
    freopen("explore1.in","r",stdin);
    freopen("explore1.out","w",stdout);
    cin>>t;
    for(int i=0;i<t;i++){
        cin>>n>>m>>k;
        cin>>x>>y>>d;
        for(int i=1;i<=n;i++){
            for(int j=1;j<=m;j++){
                cin>>a[n][m];
            }
        }
        for(int i=0;i<=n;i++){
            for(int j=0;j<=m;j++){
                f[i][j]=false;
            }
        }
        for(int i=0;i<k;i++){
            if(d==0){
                if(y+1<=m&&a[x][y+1]=='.'){
                    y++;
                    f[x][y]=true;
                }
                else{
                    d=(d+1)%4;
                }
            }
            else if(d==1){
                if(x+1<=n&&a[x+1][y]=='.'){
                    x++;
                    f[x][y]=true;
                }
                else{
                    d=(d+1)%4;
                }
            }
            else if(d==2){
                if(y-1>=1&&a[x][y-1]=='.'){
                    y--;
                    f[x][y]=true;
                }
                else{
                    d=(d+1)%4;
                }
            }
            else{
                if(x-1>=1&&a[x-1][y]=='.'){
                    x--;
                    f[x][y]=true;
                }
                else{
                    d=(d+1)%4;
                }
            }
        }
        for(int i=1;i<=n;i++){
            for(int j=1;j<=m;j++){
                if(f[i][j]){
                    cnt++;
                }
            }
        }
        cout<<cnt<<endl;
        cnt=1;
    }
    return 0;
}