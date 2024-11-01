#include <bits/stdc++.h>
using namespace std;
const long long N=10010;
char a[N][N];
int main(){
    freopen("explore.in","r",stdin);
    freopen("explore.out","w",stdout);
    long long n,m,k,x,y,d,t,cnt=1;
    cin>>t;
    for(long long i=1;i<=n;i++){
        cin>>n>>m>>k;
        cin>>x>>y>>d;
        for(long long j=1;j<=n;j++){
            for(long long p=1;p<=m;p++){
                cin>>a[j][p];
                if(d==0){
                    if(a[x][y+1]='.'){
                        cnt++;
                        y=y+1;
                    }else if(a[x][y+1]!='.'){
                        d=(d+1)%4;
                    }
                }
                if(d==1){
                    if(a[x+1][y]='.'){
                        cnt++;
                        x=x+1;
                    }else if(a[x+1][y]!='.'){
                        d=(d+1)%4;
                    }
                }
                if(d==2){
                    if(a[x][y-1]='.'){
                        cnt++;
                        y=y-1;
                    }else if(a[x][y-1]!='.'){
                        d=(d+1)%4;
                    }
                }
                if(d==3){
                    if(a[x-1][y]='.'){
                        cnt++;
                        x=x-1;
                    }else if(a[x-1][y]=!'.'){
                        d=(d+1)%4;
                    }
                }
            }
        }
        cout<<cnt/2<<endl;
    }
    return 0;
}