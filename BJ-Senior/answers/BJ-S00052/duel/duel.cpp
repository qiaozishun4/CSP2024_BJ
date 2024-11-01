#include<bits/stdc++.h>
using namespace std;
int n,cnt[100005],cnt1,ans;
void slv(){
    cin>>n;
    for(int i=1;i<=n;i++){
        int x;
        cin>>x;
        cnt[x]++;
    }
    for(int i=1;i<=1e5;i++){
        ans+=min(cnt[i],cnt1);
        cnt1=max(cnt1-cnt[i],0);
        cnt1+=cnt[i];
    }
    cout<<n-ans<<endl;
}
int main(){
    freopen("duel.in","r",stdin);
    freopen("duel.out","w",stdout);
    slv();
    fclose(stdin);
    fclose(stdout);
    return 0;
}