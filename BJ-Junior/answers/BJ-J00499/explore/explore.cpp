#include<bits/stdc++.h>
using namespace std;
int main(){
    freopen("explore.in","r",stdin);
    freopen("explore.out","w",stdout);
    int n;
    cin>>n;
    while(n--){
        int n,m,k,x,y,d,sum=0;
        cin>>n>>m>>k>>x>>y>>d;
        x--;
        y--;
        string zf[n];
        int fib[n][m]={0};
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                fib[i][j]=0;
            }
        }
        fib[x][y]++;
        for(int i=0;i<n;i++){
            cin>>zf[i];
        }
        for(int i=0;i<k;i++){
            if(d==0){
                if(y+1<m&&zf[x][y+1]=='.'){
                    y++;
                    fib[x][y]++;
                }
                else{
                    d=(d+1)%4;
                }
            }
            else if(d==1){
                if(x+1<n&&zf[x+1][y]=='.'){
                    x++;
                    fib[x][y]++;
                }
                else{
                    d=(d+1)%4;
                }
            }
            else if(d==2){
                if(y-1>=0&&zf[x][y-1]=='.'){
                    y--;
                    fib[x][y]++;
                }
                else{
                    d=(d+1)%4;
                }
            }
            else{
                if(x-1>=0&&zf[x-1][y]=='.'){
                    x--;
                    fib[x][y]++;
                }
                else{
                    d=(d+1)%4;
                }
            }
        }
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(fib[i][j]) sum++;
            }
        }
        cout<<sum<<endl;
    }
    return 0;
}
