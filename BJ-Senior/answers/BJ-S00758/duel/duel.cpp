#include <bits/stdc++.h>
#define N 200002
using namespace std;
int n,a[N],cnt,cnt2,ans;
int main(){
    freopen("duel.in","r",stdin);
    freopen("duel.out","w",stdout);
    ios::sync_with_stdio(0);
    cin>>n;
    for(int i=1;i<=n;i++)  cin>>a[i];
    sort(a+1,a+n+1);cnt2=1;
    for(int i=2;i<=n;i++){
        if(a[i]==a[i-1])  cnt2++;
        else{
            cnt+=cnt2;
            cnt2=1;
        }
        if(cnt){
            cnt--;
            ans++;
        }
        // cout<<cnt<<" "<<cnt2<<" "<<ans<<"\n";
    }
    // cout<<"\n";
    cout<<n-ans<<"\n";
    return 0;
}