#include <iostream>
#include <cstdio>
#include <cmath>
#include <algorithm>
#include <map>
using namespace std;

long long t,n,m,k,x,y,d;
string c[1010];
bool b[1010][1010];

bool f(long long x,long long y){
    if(x<1||x>n||y<1||y>m){
        return 0;
    }
    if(c[x][y]=='x'){
        return 0;
    }
    return 1;
}

int main(){
    freopen("explore.in","r",stdin);
    freopen("explore.out","w",stdout);
    cin>>t;
    while(t--){
        cin>>n>>m>>k;
        cin>>x>>y>>d;
        for(long long i=1;i<=n;i++){
            cin>>c[i];
            c[i]=" "+c[i];
        }
        for(long long i=1;i<=n;i++){
            for(long long j=1;j<=m;j++){
                b[i][j]=0;
            }
        }
        long long ans=0;
        b[x][y]=1;
        for(long long i=1;i<=k;i++){
            long long nx=x,ny=y;
            if(d==0){
                ny++;
            }else if(d==1){
                nx++;
            }else if(d==2){
                ny--;
            }else{
                nx--;
            }
            if(f(nx,ny)){
                b[nx][ny]=1;
                x=nx;
                y=ny;
            }else{
                d=(d+1)%4;
            }
        }
        for(long long i=1;i<=n;i++){
            for(long long j=1;j<=m;j++){
                if(b[i][j]){
                    ans++;
                }
            }
        }
        cout<<ans<<endl;
    }
    return 0;
}
