#include<bits/stdc++.h>
using namespace std;
const int N=1e5+10;
int n,r[N],ans;
int main(){
    freopen("duel.in","r",stdin);
    freopen("duel.out","w",stdout);
    scanf("%d",&n);
    for(int i=1;i<=n;i++) scanf("%d",&r[i]);
    sort(r+1,r+1+n);
    for(int i=1;i<=n;i++){
        int x=lower_bound(r+1,r+1+n,r[i])-r-1;
        if(x>ans) ans++;
    }
    printf("%d\n",n-ans);
    return 0;
}
