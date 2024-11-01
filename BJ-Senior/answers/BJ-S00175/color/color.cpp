#include <cstdio>
#include <map>
#include <algorithm>
using namespace std;
map<int,int>mp;
int a[200010];
void solve(){
    int n;
    long long ans=0;
    scanf("%d",&n);
    for(int i=0;i<n;i++){
        scanf("%d",&a[i]);
        mp[a[i]]=0;
    }
    for(int i=0;i<n;i++)mp[a[i]]++;
    sort(a,a+n);
    for(int i=0;i<n;i++){
        if(a[i]==a[i+1])continue;
        ans+=(mp[a[i]]-1)*a[i];
        //printf("%d %d %d\n",i,a[i],ans);
    }
    printf("%lld\n",ans);
}
int main(){
    freopen("color.in","r",stdin);
    freopen("color.out","w",stdout);
    int t;
    scanf("%d",&t);
    while(t--)solve();
    return 0;
}
