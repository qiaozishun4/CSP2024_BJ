#include <algorithm>
#include <cstdio>
#include <stack>
#include <cmath>
using namespace std;
#define MAXN 100010
int a[MAXN];
int t[MAXN];
int main(){
    freopen("duel.in","r",stdin);
    freopen("duel.out","w",stdout);
    int n,ans=0;
    scanf("%d",&n);
    for(int i=0;i<n;i++)scanf("%d",&a[i]),t[a[i]]++;
    sort(a,a+n);
    for(int i=0;i<n;i++){
        if(a[i]==a[i+1])continue;
        t[a[i+1]]=t[a[i+1]]>=t[a[i]]?t[a[i+1]]:t[a[i+1]]+t[a[i]]-t[a[i+1]];
    }
    ans=t[a[n-1]];
    printf("%d",ans);
    return 0;
}
