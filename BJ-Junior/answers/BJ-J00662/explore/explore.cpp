#include<bits/stdc++.h>
using namespace std;
const long long mod=1005;
long long n,m,k,a0,b0,d;
char q[mod][mod];
bool bj[mod][mod];
void dfs(long long x,long long y,long long dp,long long k1){
    if(k1>=k){
        return;
    }while(1){
        if(k1>=k){
            return;
        }
        if(d==0){
            if(y+1<=m&&q[x][y+1]=='.'){
                bj[x][y+1]=1;
                dfs(x,y+1,d,k1+1);
                break;
            }else{
                k1++;
                d++;
                d%=4;
            }
        }if(k1>=k){
            return;
        }if(d==1){
            if(x+1<=n&&q[x+1][y]=='.'){
                bj[x+1][y]=1;
                dfs(x+1,y,d,k1+1);
                break;
            }else{
                k1++;
                d++;
                d%=4;
            }
        }if(k1>=k){
            return;
        }if(d==2){
            if(y-1>=1&&q[x][y-1]=='.'){
                bj[x][y-1]=1;
                dfs(x,y-1,d,k1+1);
                break;
            }else{
                k1++;
                d++;
                d%=4;
            }
        }if(k1>=k){
            return;
        }if(d==3){
            if(x-1>=1&&q[x-1][y]=='.'){
                bj[x-1][y]=1;
                dfs(x-1,y,d,k1+1);
                break;
            }else{
                k1++;
                d++;
                d%=4;
            }
        }
    }


}
int main(){
    freopen("explore.in","r",stdin);
    freopen("explore.out","w",stdout);
    int t;
    cin>>t;
    for(int i=1;i<=t;i++){
        cin>>n>>m>>k>>a0>>b0>>d;
        for(int j=1;j<=n;j++){
            for(int x=1;x<=m;x++){
                cin>>q[j][x];
                bj[j][x]=0;
            }
        }bj[a0][b0]=1;
        dfs(a0,b0,d,0);
        long long sum=0;
        for(int j=1;j<=n;j++){
            for(int x=1;x<=m;x++){
                if(bj[j][x]) sum++;
            }
        }cout<<sum<<endl;
    }
    return 0;
}

