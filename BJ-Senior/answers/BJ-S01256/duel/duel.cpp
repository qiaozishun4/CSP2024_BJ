#include<bits/stdc++.h>
#define int long long
using namespace std;
const int maxn=1e5+5;
int buc[maxn];
int a[maxn];
signed main(){
    freopen("duel.in","r",stdin);
    freopen("duel.out","w",stdout);
    int n;
    scanf("%lld",&n);
    memset(buc,0,sizeof(buc));
    int maxx=-1;
    for(int i=1;i<=n;i++){
        scanf("%lld",&a[i]);
        buc[a[i]]++;
        maxx=max(maxx,a[i]);
    }
    int ans=0;
    int cnt=0;
    for(int i=1;i<=maxx;i++){
        if(buc[i]==0)continue;
        else{
            if(cnt==0){
                cnt+=buc[i];
            }else{
                if(cnt<buc[i]){
                    ans+=cnt;
                    cnt=buc[i];
                }else{
                    ans+=buc[i];
                }
            }
        }
    }
    cout<<n-ans;
    return 0;
}