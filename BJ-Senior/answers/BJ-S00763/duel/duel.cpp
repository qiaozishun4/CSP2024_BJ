#include<bits/stdc++.h>
using namespace std;
#define int long long
int n,a[100005],b[100005];
int h[100005],maxn=-1;
int th[100005];
signed main(){
    freopen("duel.in","r",stdin);
    freopen("duel.out","w",stdout);
    cin>>n;
    for(int i=1;i<=n+1;i++){
        if(i<=n){
            cin>>a[i];
        }
    }
    for(int i=1;i<=n;i++){
         maxn=max(maxn,a[i]);
         th[a[i]]++;
    }
    int cnt=0,sum=0;
    for(int i=1;i<=maxn;i++){
        if(th[a[i]]){
			sum++;
		}
        while(th[a[i]]){
            b[++cnt]=sum;
            th[a[i]]--;
        }
    }
    maxn=-1;
    for(int i=1;i<=n;i++) {
		h[b[i]]++;
		maxn=max(b[i],maxn);
	}
    for(int i=2;i<=maxn;i++) n-=min(h[i],h[i-1]);
    cout<<n;
    return 0;
}
