#include <bits/stdc++.h>
using namespace std;
int n,a[100050];
map<int,int> mp;
int main(){
    freopen("duel.in","r",stdin);
    freopen("duel.out","w",stdout);
    scanf("%d",&n);
    for(int i = 1;i <= n;i++){
        scanf("%d",&a[i]);
        mp[a[i]]++;
    }
    int ans = -1;
    for(int i = 1;i <= n;i++){
        ans = max(ans,mp[a[i]]);
    }
    printf("%d",ans);
    fclose(stdin);
    fclose(stdout);
    return 0;
}
