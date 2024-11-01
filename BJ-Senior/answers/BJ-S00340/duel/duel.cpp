#include<bits/stdc++.h>
using namespace std;
int n,a[100005],ans;
int t[100005];
int cnt[100005],tot;
int main(){
    freopen("duel.in","r",stdin);
    freopen("duel.out","w",stdout);
    cin>>n;ans=n;
    for(int i=1;i<=n;i++)cin>>a[i],t[i]=a[i];
    sort(t+1,t+n+1);
    int len=unique(t+1,t+n+1)-(t+1);
    for(int i=1;i<=n;i++){
        a[i]=lower_bound(t+1,t+len+1,a[i])-t;
        cnt[a[i]]++;
    }
    //for(int i=1;i<=n;i++)
    ans=cnt[1];
    for(int i=2;i<=len;i++){//cout<<t[i]<<" "<<ans<<endl;
        if(ans>cnt[i])ans-=cnt[i];
        else ans=0;
        ans+=cnt[i];
    }
    cout<<ans;
    return 0;
}
