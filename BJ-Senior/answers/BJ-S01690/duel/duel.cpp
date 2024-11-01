#include<bits/stdc++.h>
using namespace std;
int n;
int r[100005];
int cnt[100005],top,ans;
int main(){
    freopen("duel.in","r",stdin);
    freopen("duel.out","w",stdout);
    scanf("%d",&n);
    for(int i=1;i<=n;i++){
        scanf("%d",&r[i]);
    }
    sort(r+1,r+1+n);
    for(int i=1;i<=n;i++){
        if(r[i]!=r[i-1]){
            top++;
        }
        cnt[top]++;
    }
    for(int i=2;i<=top;i++){
        ans+=cnt[i-1];
        ans=max(ans-cnt[i],0);
    }
    ans+=cnt[top];
    printf("%d",ans);
    return 0;
}
