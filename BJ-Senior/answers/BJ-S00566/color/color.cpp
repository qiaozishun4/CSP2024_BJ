#include <iostream>
#include <cstdio>
using namespace std;
int t,n,a[200005];
long long dp[200005],v[200005],maxdp[200005],maxn,maxnm[1000005];
int main(){
    freopen("color.in","r",stdin);
    freopen("color.out","w",stdout);
    cin >> t;
    while(t--){
        cin >> n;
        maxn=0;
        for(int i = 1;i <= n;i++){
            cin >> a[i];
            if(a[i]==a[i-1]){
                v[i]=v[i-1]+a[i];
            }
            else{
                v[i]=v[i-1];
            }
        }
        for(int i = 1;i <= n+1;i++){
            maxdp[i]=0;
        }
        for(int i = 0;i <= 1000000;i++) maxnm[i]=-1;
        maxn=0;
        for(int i = 1;i <= n+1;i++){
            if(maxnm[a[i]]!=-1) maxdp[i]=maxnm[a[i]]+a[i]+v[i-1];
            maxdp[i]=max(maxdp[i],maxn+v[i-1]);
            maxn=max(maxdp[i]-v[i],maxn);
            if(a[i-1]) maxnm[a[i-1]]=max(maxnm[a[i-1]],maxdp[i]-v[i]);
            //cout << maxnm[a[i-1]] << "!";
        }
        cout << maxdp[n+1] << "\n";
    }
    return 0;
}