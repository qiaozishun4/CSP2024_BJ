#include<bits/stdc++.h>
using namespace std;
int n,r[100005],mp[100005],cnt,f[100005],ans;
int main(){
    freopen("duel.in","r",stdin);
    freopen("duel.out","w",stdout);
    scanf("%d",&n);
    for(int i=1;i<=n;i++){
        scanf("%d",&r[i]);
        mp[r[i]]++;
        ans=max(ans,mp[r[i]]);
    }
    printf("%d",ans);
    return 0;
}

