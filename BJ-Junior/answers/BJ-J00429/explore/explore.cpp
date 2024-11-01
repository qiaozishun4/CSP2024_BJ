#include<bits/stdc++.h>
using namespace std;
const int N=1010;
long long t,k,n,m,x,y,d;
char a[N][N];
long long ans;
int main(){
    freopen("explore.in","r",stdin);
    freopen("explore.out","w",stdout);
    cin>>t;
    for(int i=1;i<=t;i++){
            ans=0;
        cin>>n>>m>>k>>x>>y>>d;
        for(int j=1;j<=n;j++){
            for(int l=1;l<=m;l++){
                cin>>a[j][l];
            }
        }
        for(int j=1;j<=k;j++){
            a[x][y]='0';
            if(d==0){
                if(y+1>m||a[x][y+1]=='x'){
                    d=(d+1)%4;
                }else if(a[x][y+1]=='0'){
                    y++;
                }else{
                    y++;
                    ans++;
                }
            }else if(d==1){
                if(x+1>n||a[x+1][y]=='x'){
                    d=(d+1)%4;
                }else if(a[x+1][y]=='0'){
                    x++;
                }else{
                    x++;
                    ans++;
                }

            }else if(d==2){
                if(y-1<1||a[x][y-1]=='x'){
                    d=(d+1)%4;
                }else if(a[x][y-1]=='0'){
                    y--;
                }else{
                    y--;
                    ans++;
                }

            }else if(d==3){
                if(x-1<1||a[x-1][y]=='x'){
                    d=(d+1)%4;
                }else if(a[x-1][y]=='0'){
                    x--;
                }else{
                    x--;
                    ans++;
                }
            }

        }
        cout<<ans+1<<endl;
    }
    return 0;
}
