#include<bits/stdc++.h>
using namespace std;
int n,a[100005];
multiset<int> att;
int main(){
    #ifndef JZQ
    freopen("duel.in","r",stdin);
    freopen("duel.out","w",stdout);
    #endif
    scanf("%d",&n);
    for(int i=1;i<=n;i++){
        scanf("%d",&a[i]);
        att.insert(a[i]);
    }
    sort(a+1,a+n+1);
    int ans=n;
    for(int i=1;i<=n;i++){
        auto it=att.upper_bound(a[i]);
        if(it!=att.end()){
            ans--;
            att.erase(it);
        }
    }
    printf("%d\n",ans);
    return 0;
}