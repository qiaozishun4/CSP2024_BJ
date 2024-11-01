#include<iostream>
#include<cmath>
using namespace std;
bool is2(long long z){
    while(z%2==0){
        z/=2;
    }
    return z==1;
}
long long a0[100005];
long long a[100005];
long long c[100005];
char d[25][200005];
long long win[25][200005];
void cz(long long x){
    int k=log2(x);
    for(int i=1;i<=x;i++){
        win[k+1][i]=i;
    }
    for(int i=k;i>=1;i--){
        long long tar=(1<<(i-1));
        for(int j=1;j<=tar;j++){
            if(d[i][j]=='0'){
                if(a[win[i+1][j*2-1]]>=k-i+1){
                    win[i][j]=win[i+1][j*2-1];
                }
            }
            else{
                if(a[win[i+1][j*2]]>=k-i+1){
                    win[i][j]=win[i+1][j*2];
                }
            }
        }
    }
}
int main(){
    ios::sync_with_stdio(0);
    freopen("arena.in","r",stdin);
    freopen("arena.out","w",stdout);
    int n,m;
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        cin>>a0[i];
    }
    for(int i=1;i<=m;i++){
        cin>>c[i];
    }
    int K=log2(n);
    if(!is2(n)){
        K++;
    }
    for(int i=K;i>=1;i--){
        int tar=(1<<(i-1));
        for(int j=1;j<=tar;j++){
            cin>>d[i][j];
        }
    }
    int T;
    cin>>T;
    while(T--){
        long long x[4];
        cin>>x[0]>>x[1]>>x[2]>>x[3];
        for(int i=1;i<=n;i++){
            a[i]=a0[i]^x[i%4];
        }
        long long ans=0;
        for(int i=1;i<=m;i++){
            if(is2(c[i])){
                cz(c[i]);
                ans=ans^(win[1][1]*i);
            }
        }
        cout<<ans<<'\n';
    }
    return 0;
}
